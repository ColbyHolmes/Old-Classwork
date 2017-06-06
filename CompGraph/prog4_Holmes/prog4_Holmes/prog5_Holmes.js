// prog5_Holmes.js
//Colby Holmes
//4/19/17
// Takes the base code from prog4_Holmes.js

// Allows toggle of AABB with b key (*calculated, but having trouble adding buffer*)
// Allows the user to scale the z = f(x, y) function with D/d key 
// Replaced animation with user controlled rotation via arrow keys 3 degrees regular, 15 degrees shifted
// Uses Orthographic projection scaled with Z/z key (*not implemented*)
// Uses Phong shading with a single point light source and ambient light
// Front faces are red, back faces are blue (blue faces and their normals may not be correct..)


//Note! The vertices were wrong in program 4, but I wasn't pointed towards how to correct them,
//So they are still incorrect.



// Based on LightedCube_animation.js (c) 2012 matsuda

// Vertex shader program
var VSHADER_SOURCE =
  'attribute vec4 a_Position;\n' +
  'attribute vec4 a_Color;\n' +
  'attribute vec4 a_Normal;\n' +
  'attribute vec4 b_Position;\n' +
  'attribute vec4 b_Color;\n' +
  'attribute vec4 b_Normal;\n' +
  'uniform mat4 u_MvpMatrix;\n' +
  'uniform mat4 u_ModelMatrix;\n' +    // Model matrix
  'uniform mat4 u_NormalMatrix;\n' +
  'uniform vec3 u_LightDirection;\n' +
  'varying vec4 v_Color;\n' +
  'varying vec3 v_Normal;\n' +
  'varying vec3 v_Position;\n' +
  'void main() {\n' +
  '  gl_Position = u_MvpMatrix * a_Position;\n' +
  '  vec4 normal = u_NormalMatrix * a_Normal;\n' +
  '  float nDotL = max(dot(u_LightDirection, normalize(normal.xyz)), 0.0);\n' +
  '  v_Position = vec3(u_ModelMatrix * a_Position);\n' +
  '  v_Normal = normalize(vec3(u_NormalMatrix * a_Normal));\n' +
  '  v_Color = vec4(a_Color.xyz * nDotL, a_Color.a);\n' + 
  '}\n';

// Fragment shader program
var FSHADER_SOURCE =
  '#ifdef GL_ES\n' +
  'precision mediump float;\n' +
  '#endif\n' +
    'uniform vec3 u_LightColor;\n' +     // Light color
  'uniform vec3 u_LightPosition;\n' +  // Position of the light source
  'uniform vec3 u_AmbientLight;\n' +   // Ambient light color
  'varying vec3 v_Normal;\n' +
  'varying vec3 v_Position;\n' +
  'varying vec4 v_Color;\n' +
  'void main() {\n' +
     // Normalize the normal because it is interpolated and not 1.0 in length any more
  '  vec3 normal = normalize(v_Normal);\n' +
     // Calculate the light direction and make its length 1.
  '  vec3 lightDirection = normalize(u_LightPosition - v_Position);\n' +
     // The dot product of the light direction and the orientation of a surface (the normal)
  '  float nDotL = max(dot(lightDirection, normal), 0.0);\n' +
     // Calculate the final color from diffuse reflection and ambient reflection
  '  vec3 diffuse = u_LightColor * v_Color.rgb * nDotL;\n' +
  '  vec3 ambient = u_AmbientLight * v_Color.rgb;\n' +
  '  gl_FragColor = vec4(diffuse + ambient, v_Color.a);\n' +
  '}\n';

var SCALE = 1;//for scaling function
var r = 0.0;//AABB radius
var c = new Float32Array(4); //center of AABB
var vsf = 1;//for ortho scaling
var TOGGLE = 0;//toggle AABB
var currentAnglex = 0.0;  // Current rotation angle x
var currentAngley = 0.0;  // Current rotation angle y
var m;//for indices of AABB
var boxvert = new Float32Array(24); //vertices of AABB

function main() {
    // Retrieve <canvas> element
    var canvas = document.getElementById('webgl');

    // Get the rendering context for WebGL
    var gl = getWebGLContext(canvas);
    if (!gl) {
        console.log('Failed to get the rendering context for WebGL');
        return;
    }

    // Initialize shaders
    if (!initShaders(gl, VSHADER_SOURCE, FSHADER_SOURCE)) {
        console.log('Failed to intialize shaders.');
        return;
    }

    // 
    var n = initVertexBuffers(gl);
    if (n < 0) {
        console.log('Failed to set the vertex information');
        return;
    }

    // Set the clear color and enable the depth test
    gl.clearColor(0, 0, 0, 1);
    gl.enable(gl.DEPTH_TEST);


    // Get the storage locations of uniform variables and so on
    var u_MvpMatrix = gl.getUniformLocation(gl.program, 'u_MvpMatrix');
    var u_NormalMatrix = gl.getUniformLocation(gl.program, 'u_NormalMatrix');
    var u_LightDirection = gl.getUniformLocation(gl.program, 'u_LightDirection');
    var u_LightColor = gl.getUniformLocation(gl.program, 'u_LightColor');
    var u_LightPosition = gl.getUniformLocation(gl.program, 'u_LightPosition');
    var u_AmbientLight = gl.getUniformLocation(gl.program, 'u_AmbientLight');
    if (!u_MvpMatrix || !u_NormalMatrix || !u_LightDirection || !u_LightColor || !u_LightPosition|| !u_AmbientLight) { 
        console.log('Failed to get the storage location');
        return;
    }
    // Set the light color (white)
    gl.uniform3f(u_LightColor, 1.0, 1.0, 1.0);
    // Set the light direction (in the world coordinate)
    gl.uniform3f(u_LightPosition, 2.3, 4.0, 3.5);
    // Set the ambient light
    gl.uniform3f(u_AmbientLight, 0.2, 0.2, 0.2);

    var vpMatrix = new Matrix4();   // View projection matrix
    // Calculate the view projection matrix
    vpMatrix.setPerspective(30, canvas.width/canvas.height, 1, 100);
    vpMatrix.lookAt(3, 3, 7, 0, 0, 0, 0, 1, 0);
    // Set the light direction (in the world coordinate)
    var lightDirection = new Vector3([0.5, 3.0, 4.0]);
    lightDirection.normalize();     // Normalize
    gl.uniform3fv(u_LightDirection, lightDirection.elements);
  

    var modelMatrix = new Matrix4();  // Model matrix
    var modelMatrix1 = new Matrix4();
    var modelMatrix2 = new Matrix4();
    var mvpMatrix = new Matrix4();    // Model view projection matrix
    var normalMatrix = new Matrix4(); // Transformation matrix for normals

    var tick = function () {
        // Register the key event handler
        document.onkeydown = function (ev) { keydown(ev, gl); };


        // Calculate the model matrix
        modelMatrix1.setRotate(currentAngley, 0, 1, 0); // Rotate around the y-axis
        modelMatrix2.setRotate(currentAnglex, 1, 0, 0); // Rotate around the x-axis
        modelMatrix.set(modelMatrix1.multiply(modelMatrix2));

        //**********AHHHH
        //modelMatrix.makeTranslation(-c[0], -c[1], -c[2]);
        //setOrtho(-vsf * r, vsf * r, -vsf * r, vsf * r, 2.0 * r, 4.0 * r);

        mvpMatrix.set(vpMatrix).multiply(modelMatrix);
        gl.uniformMatrix4fv(u_MvpMatrix, false, mvpMatrix.elements);

        // Pass the matrix to transform the normal based on the model matrix to u_NormalMatrix
        normalMatrix.setInverseOf(modelMatrix);
        normalMatrix.transpose();
        gl.uniformMatrix4fv(u_NormalMatrix, false, normalMatrix.elements);

        // Clear color and depth buffer
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

        // Draw the graph
        gl.drawElements(gl.TRIANGLES, n, gl.UNSIGNED_SHORT, 0);//altered here as well (BYTE->SHORT)

        /*var m = initVertexBufferBox(gl);
        if (m < 0) {
            console.log('Failed to set the vertex information');
            return;
        }
        // If toggled Draw the box
        if (TOGGLE) {
            gl.drawElements(gl.TRIANGLES, m, gl.UNSIGNED_BYTE, 0);
        }//*/
        requestAnimationFrame(tick, canvas); // Request that the browser ?calls tick
    };
    tick();
}

function draw(gl, n, angle, vpMatrix, u_MvpMatrix, u_NormalMatrix) {
}

function initVertexBuffers(gl) {
    //intialize variables

    var K = 50;
    var NV = Math.pow(K + 1, 2);
    var NT = 2 * Math.pow(K, 2);

    var box = new Float32Array(6); //mins and maxs of AABB

    //vertex list
    var v = new Array(NV);
    for (var i = 0; i < NV; i++) {
        v[i] = new Float32Array(3);
    }
    
    //triangle list
    var ltri = new Array(NT);
    for (var i = 0; i < NT; i++) {
        ltri[i] = new Float32Array(3);
    }

    //vertex normal list
    var vn = new Array(NV);
    for (var i = 0; i < NV; i++) {
        vn[i] = new Float32Array(3);
    }

    //triangle normal list
    var tn = new Float32Array(3);

    //Store vertices
    var h = 1.0/K;
    var indv = 0;
    
    for (var j = 0; j < K; j++) {
        var y = j * h;

        for (var i = 0; i < K; i++) {
            var x = i * h;
            v[indv][0] = x;
            v[indv][1] = y;
            v[indv][2] = SCALE* .5*Math.exp(-.04*Math.sqrt(Math.pow((80*x-40), 2) + Math.pow((90*y-45), 2))) * Math.cos(0.15*Math.sqrt(Math.pow((80*x-40), 2) + Math.pow((90*y-45), 2)));

            indv = indv + 1;
        }//endfor
    }//endfor

    //intialize box limits
    var indv = 0;
    box[0] = v[0][0];
    box[1] = v[0][0];
    box[2] = v[0][1];
    box[3] = v[0][1];
    box[4] = v[0][2];
    box[5] = v[0][2];

    //find box limits
    for (var j = 0; j < K; j++) {
        for (var i = 0; i < K; i++) {
            if (v[indv][0] < box[0]) {//less than x min
                box[0] = v[indv][0];
            }
            else if (v[indv][0] > box[1]) {//greater than x max
                box[1] = v[indv][0];
            }
            if (v[indv][1] < box[2]) {//less than y min
                box[2] = v[indv][1];
            }
            else if (v[indv][1] > box[3]) {//greater than y max
                box[3] = v[indv][1];
            }
            if (v[indv][2] < box[4]) {//less than x min
                box[4] = v[indv][2];
            }
            else if (v[indv][2] > box[5]) {//greater than x max
                box[5] = v[indv][2];
            }
            indv = indv + 1;
        }//endfor
    }//endfor*/
    // Create a box 
    //    v6----- v5
    //   /|      /|
    //  v1------v0|
    //  | |     | |
    //  | |v7---|-|v4
    //  |/      |/
    //  v2------v3
    // Coordinates
    var boxvert = [
   box[1], box[3], box[5]  , box[0], box[3], box[5]  , box[0], box[2], box[5]  , box[1], box[2], box[5], // v0-v1-v2-v3 front
   box[1], box[3], box[5]  , box[1], box[2], box[5]  , box[1], box[2], box[4]  , box[1], box[3], box[4], // v0-v3-v4-v5 right
   box[1], box[3], box[5]  , box[1], box[3], box[4]  , box[0], box[3], box[4]  , box[0], box[3], box[5], // v0-v5-v6-v1 up
   box[0], box[3], box[5]  , box[0], box[3], box[4]  , box[0], box[2], box[4]  , box[0], box[2], box[5], // v1-v6-v7-v2 left
   box[0], box[2], box[4]  , box[1], box[2], box[4]  , box[1], box[2], box[5]  , box[0], box[2], box[5], // v7-v4-v3-v2 down
   box[1], box[2], box[4]  , box[0], box[2], box[4]  , box[0], box[3], box[4]  , box[1], box[3], box[4]  // v4-v7-v6-v5 back
    ];
    //calc box center
    c[0] = box[1] - box[0]; //midpoint x
    c[1] = box[3] - box[2]; //midpoint y
    c[2] = box[5] - box[4];//midpoint z
    c[3] = 1;

    //calc radius sqrt(A^2 + B^2 + C^2)/2
    r = Math.sqrt(Math.pow(c[0], 2) + Math.pow(c[1], 2) + Math.pow(c[2], 2)) / 2;

    //Store triangles (triples of vertex indices)
    var indt = 0;
    for (var j = 1; j < K; j++) {

        for (var i = 1; i < K; i++) {

            indv = j * (K + 1) + i;
            // indv indexes the upper right corner of a cell.
            ltri[indt][0] = indv - K - 2;
            ltri[indt][1] = indv - K - 1;
            ltri[indt][2] = indv;
            ltri[indt + 1][0] = indv - K - 2;
            ltri[indt + 1][1] = indv;
            ltri[indt + 1][2] = indv - 1;

            indt += 2;
        }//endfor
    }//endfor



    //Initialize normals
    for (indv = 0; indv < NV - 1; indv++) {
        vn[indv][0] = 0;
        vn[indv][1] = 0;
        vn[indv][2] = 0;
    }//endfor


    //Add triangle normals to vertex normals
    for (indt = 0; indt < NT-1; indt++){
        i1 = ltri[indt][0]
        i2 = ltri[indt][1]
        i3 = ltri[indt][2]
        
        tn[0] = (v[i2][1]-v[i1][1])*(v[i3][2]-v[i1][2])-(v[i2][2]-v[i1][2])*(v[i3][1]-v[i1][1])
        
        tn[1] = (v[i2][2]-v[i1][2])*(v[i3][0]-v[i1][0])-(v[i2][0]-v[i1][0])*(v[i3][2]-v[i1][2])
        
        tn[2] = (v[i2][0]-v[i1][0])*(v[i3][1]-v[i1][1])-(v[i2][1]-v[i1][1])*(v[i3][0]-v[i1][0])
        
        //normalize triangle normal (tn)
        var mag = Math.sqrt((tn[0] * tn[0]) + (tn[1] * tn[1]) + (tn[2] * tn[2]));
        tn[0] = tn[0] / mag;
        tn[1] = tn[1] / mag;
        tn[2] = tn[2] / mag;

        //add to vector normals
        vn[i1][0] += tn[0];
        vn[i1][1] += tn[1];
        vn[i1][2] += tn[2];

        vn[i2][0] += tn[0];
        vn[i2][1] += tn[1];
        vn[i2][2] += tn[2];

        vn[i3][0] += tn[0];
        vn[i3][1] += tn[1];
        vn[i3][2] += tn[2];
    }//endfor



    //Normalize vertex normals
    for (indv = 0; indv < NV - 1; indv++) {
        var mag = Math.sqrt((vn[indv][0] * vn[indv][0]) + (vn[indv][1] * vn[indv][1]) + (vn[indv][2] * vn[indv][2]));
        vn[indv][0] = vn[indv][0] / mag;
        vn[indv][1] = vn[indv][1] / mag;
        vn[indv][2] = vn[indv][2] / mag;
    }//endfor


//Convert all the 2D arrays to 1D
    var vertices = new Float32Array(3*NV);
    indv = 0;

    for(var i = 0; i < v.length; i++)
    {
     	vertices[indv]     = v[i][0];
    	vertices[indv + 1] = v[i][1];
    	vertices[indv + 2] = v[i][2];
    	indv = indv + 3;
    }

    var normals = new Float32Array(3*NV);
    indv = 0;

    for(var i = 0; i < vn.length; i++)
    {
    	normals[indv]     = vn[i][0];
    	normals[indv + 1] = vn[i][1];
    	normals[indv + 2] = vn[i][2];
    	indv = indv + 3;
    }

    var colors = new Float32Array(3*NV);
    indv = 0;

    for(var i = 0; i < v.length; i++)
    {
        //chose color for front or back faces
        if (normals[indv] + normals[indv + 1] + normals[indv + 2] > 0) {
            colors[indv] = 1;
            colors[indv + 1] = 0;
            colors[indv + 2] = 0;
       }
        else {
            //reverse normals for backfaces
            normals[indv] *= -1;
            normals[indv + 1] *= -1;
            normals[indv + 2] *= -1;
            colors[indv] = 0;
            colors[indv + 1] = 0;
            colors[indv + 2] = 1;
        }//*/
    	indv = indv + 3;
    }
    var indices = new Uint16Array(3*NT);
    indv = 0;

    for(var i = 0; i < ltri.length; i++)
    {
    	indices[indv]     = ltri[i][0];
    	indices[indv + 1] = ltri[i][1];
    	indices[indv + 2] = ltri[i][2];
    	indv = indv + 3;
    }


    // Write the vertex property to buffers (coordinates, colors and normals)
    if (!initArrayBuffer(gl, 'a_Position', vertices, 3, gl.FLOAT)) return -1;
    if (!initArrayBuffer(gl, 'a_Color', colors, 3, gl.FLOAT)) return -1;    
    if (!initArrayBuffer(gl, 'a_Normal', normals, 3, gl.FLOAT)) return -1;

    // Unbind the buffer object
    gl.bindBuffer(gl.ARRAY_BUFFER, null);

    // Write the indices to the buffer object
    var indexBuffer = gl.createBuffer();
    if (!indexBuffer) {
        console.log('Failed to create the buffer object');
        return false;
    }
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);
//***************************

    return indices.length;
}

function initVertexBufferBox(gl) {
    //already have box

    // Colors
    var colors = new Float32Array([
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v0-v1-v2-v3 front
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v0-v3-v4-v5 right
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v0-v5-v6-v1 up
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v1-v6-v7-v2 left
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v7-v4-v3-v2 down
      0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,     // v4-v7-v6-v5 back
    ]);

    // Normal
    var normals = new Float32Array([
      0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,  // v0-v1-v2-v3 front
      1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,  // v0-v3-v4-v5 right
      0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,  // v0-v5-v6-v1 up
     -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0,  // v1-v6-v7-v2 left
      0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0,  // v7-v4-v3-v2 down
      0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0   // v4-v7-v6-v5 back
    ]);

    // Indices of the vertices
    var indices = new Uint8Array([
       0, 1, 2, 0, 2, 3,    // front
       4, 5, 6, 4, 6, 7,    // right
       8, 9, 10, 8, 10, 11,    // up
      12, 13, 14, 12, 14, 15,    // left
      16, 17, 18, 16, 18, 19,    // down
      20, 21, 22, 20, 22, 23     // back
    ]);

    // Write the vertex property to buffers (coordinates, colors and normals)
    if (!initArrayBuffer(gl, 'b_Position', boxvert, 3)) return -1;
    if (!initArrayBuffer(gl, 'b_Color', colors, 3)) return -1;
    if (!initArrayBuffer(gl, 'b_Normal', normals, 3)) return -1;

    // Unbind the buffer object
    gl.bindBuffer(gl.ARRAY_BUFFER, null);

    // Write the indices to the buffer object
    var indexBuffer = gl.createBuffer();
    if (!indexBuffer) {
        console.log('Failed to create the buffer object');
        return false;
    }
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

    return indices.length;
}

function initArrayBuffer(gl, attribute, data, num, type) {
    // Create a buffer object
    var buffer = gl.createBuffer();
    if (!buffer) {
        console.log('Failed to create the buffer object');
        return false;
    }
    // Write date into the buffer object
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, data, gl.STATIC_DRAW);
    // Assign the buffer object to the attribute variable
    var a_attribute = gl.getAttribLocation(gl.program, attribute);
    if (a_attribute < 0) {
        console.log('Failed to get the storage location of ' + attribute);
        return false;
    }
    gl.vertexAttribPointer(a_attribute, num, type, false, 0, 0);
    // Enable the assignment of the buffer object to the attribute variable
    gl.enableVertexAttribArray(a_attribute);

    return true;
}

function initVertexBufferBox(gl) {
    //already have box

    // Colors
    var colors = new Float32Array([
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v0-v1-v2-v3 front
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v0-v3-v4-v5 right
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v0-v5-v6-v1 up
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v1-v6-v7-v2 left
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v7-v4-v3-v2 down
      0, 1, 0,   0, 1, 0,   0, 1, 0,  0, 1, 0,     // v4-v7-v6-v5 back
    ]);

    // Normal
    var normals = new Float32Array([
      0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,  // v0-v1-v2-v3 front
      1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,  // v0-v3-v4-v5 right
      0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,  // v0-v5-v6-v1 up
     -1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,  -1.0, 0.0, 0.0,  // v1-v6-v7-v2 left
      0.0,-1.0, 0.0,   0.0,-1.0, 0.0,   0.0,-1.0, 0.0,   0.0,-1.0, 0.0,  // v7-v4-v3-v2 down
      0.0, 0.0,-1.0,   0.0, 0.0,-1.0,   0.0, 0.0,-1.0,   0.0, 0.0,-1.0   // v4-v7-v6-v5 back
    ]);

    // Indices of the vertices
    var indices = new Uint8Array([
       0, 1, 2,   0, 2, 3,    // front
       4, 5, 6,   4, 6, 7,    // right
       8, 9,10,   8,10,11,    // up
      12,13,14,  12,14,15,    // left
      16,17,18,  16,18,19,    // down
      20,21,22,  20,22,23     // back
    ]);

    // Write the vertex property to buffers (coordinates, colors and normals)
    if (!initArrayBuffer(gl, 'b_Position', boxvert, 3)) return -1;
    if (!initArrayBuffer(gl, 'b_Color', colors, 3)) return -1;
    if (!initArrayBuffer(gl, 'b_Normal', normals, 3)) return -1;

    // Unbind the buffer object
    gl.bindBuffer(gl.ARRAY_BUFFER, null);

    // Write the indices to the buffer object
    var indexBuffer = gl.createBuffer();
    if (!indexBuffer) {
        console.log('Failed to create the buffer object');
        return false;
    }
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

    return indices.length;
}

function animate(angle, step) {
    /*// Calculate the elapsed time
    var now = Date.now();
    var elapsed = now - g_last;
    g_last = now;//*/
    // Update the current rotation angle (adjusted by the elapsed time)
    var newAngle = angle + step;
    return newAngle %= 360;
}

//user input commands
function keydown(ev, gl) { //shift 16
    switch (ev.keyCode) {
        case 38: // UP arrow key
            if (ev.shiftKey) {
                currentAnglex = animate(currentAnglex, 15.0);  // Update the rotation angle
            }
            else{
                currentAnglex = animate(currentAnglex, 3.0);  // Update the rotation angle
            }
            break;

        case 40: // DOWN arrow key
            if (ev.shiftKey) {
                currentAnglex = animate(currentAnglex, -15.0);  // Update the rotation angle
            }
            else {
                currentAnglex = animate(currentAnglex, -3.0);  // Update the rotation angle
            }
            break;

        case 39: // RIGHT arrow key
            if (ev.shiftKey) {
                currentAngley = animate(currentAngley, 15.0);  // Update the rotation angle
            }
            else {
                currentAngley = animate(currentAngley, 3.0);  // Update the rotation angle
            }
            break;

        case 37: // LEFT arrow key
            if (ev.shiftKey) {
                currentAngley = animate(currentAngley, -15.0);  // Update the rotation angle
            }
            else {
                currentAngley = animate(currentAngley, -3.0);  // Update the rotation angle
            }
            break;

        case 66: // b key
            if (TOGGLE) { TOGGLE = 0; }
            else { TOGGLE = 1;}
            break;

        case 68: // d key
            if (ev.shiftKey) {
                SCALE++;
                initVertexBuffers(gl)
            }
            else {
                SCALE--;
                initVertexBuffers(gl)
            }
            break;
        case 90: // z key
            if (ev.shiftKey) {
                vsf--;
            }
            else {
                vsf++;
            }
            break;

        default:
            break;
    }
}