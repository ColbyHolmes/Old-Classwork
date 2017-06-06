// prog4_Holmes.js
//Colby Holmes
//3/30/17
// Takes the base code from LightedCube_animation.js
// Altered to show a bivariate graph instead of a cube.
// Uses z = .5*exp[-.04*sqrt((80x-40)^2 + (90y-45)^2)] *
//             cos[0.15*sqrt((80x-40)^2 + (90y-45)^2)]



// Based on LightedCube_animation.js (c) 2012 matsuda

// Vertex shader program
var VSHADER_SOURCE =
  'attribute vec4 a_Position;\n' +
  'attribute vec4 a_Color;\n' +
  'attribute vec4 a_Normal;\n' +
  'uniform mat4 u_MvpMatrix;\n' +
  'uniform mat4 u_NormalMatrix;\n' +
  'uniform vec3 u_LightDirection;\n' +
  'varying vec4 v_Color;\n' +
  'void main() {\n' +
  '  gl_Position = u_MvpMatrix * a_Position;\n' +
  '  vec4 normal = u_NormalMatrix * a_Normal;\n' +
  '  float nDotL = max(dot(u_LightDirection, normalize(normal.xyz)), 0.0);\n' +
  '  v_Color = vec4(a_Color.xyz * nDotL, a_Color.a);\n' + 
  '}\n';

// Fragment shader program
var FSHADER_SOURCE =
  '#ifdef GL_ES\n' +
  'precision mediump float;\n' +
  '#endif\n' +
  'varying vec4 v_Color;\n' +
  'void main() {\n' +
  '  gl_FragColor = v_Color;\n' +
  '}\n';

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
    if (!u_MvpMatrix || !u_NormalMatrix || !u_LightDirection) { 
        console.log('Failed to get the storage location');
        return;
    }

    var vpMatrix = new Matrix4();   // View projection matrix
    // Calculate the view projection matrix
    vpMatrix.setPerspective(30, canvas.width/canvas.height, 1, 100);
    vpMatrix.lookAt(3, 3, 7, 0, 0, 0, 0, 1, 0);
    // Set the light direction (in the world coordinate)
    var lightDirection = new Vector3([0.5, 3.0, 4.0]);
    lightDirection.normalize();     // Normalize
    gl.uniform3fv(u_LightDirection, lightDirection.elements);
  
    var currentAngle = 0.0;  // Current rotation angle
    var modelMatrix = new Matrix4();  // Model matrix
    var mvpMatrix = new Matrix4();    // Model view projection matrix
    var normalMatrix = new Matrix4(); // Transformation matrix for normals

    var tick = function() {
        currentAngle = animate(currentAngle);  // Update the rotation angle

        // Calculate the model matrix
        modelMatrix.setRotate(currentAngle, 0, 1, 0); // Rotate around the y-axis
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

        requestAnimationFrame(tick, canvas); // Request that the browser ?calls tick
    };
    tick();
}

function draw(gl, n, angle, vpMatrix, u_MvpMatrix, u_NormalMatrix) {
}

function initVertexBuffers(gl) {
//******START OF ALTERED CODE*******

//intialize variables
    var K = 50;
    var NV = Math.pow(K + 1, 2);
    var NT = 2 * Math.pow(K, 2);

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
    tn = new Float32Array(3);

    //Store vertices
    var h = 1.0/K;
    var indv = 0;
    
    for (var j = 0; j < K; j++) {
        var y = j * h;

        for (var i = 0; i < K; i++) {
            var x = i * h;
            v[indv][0] = x;
            v[indv][1] = y;
            v[indv][2] = .5*Math.exp(-.04*Math.sqrt(Math.pow((80*x-40), 2) + Math.pow((90*y-45), 2))) * Math.cos(0.15*Math.sqrt(Math.pow((80*x-40), 2) + Math.pow((90*y-45), 2)));

            indv = indv + 1;
        }//endfor
    }//endfor


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

    var colors = new Float32Array(3*NV);
    indv = 0;

    for(var i = 0; i < v.length; i++)
    {
    	colors[indv]     = 0;
    	colors[indv + 1] = 1;
    	colors[indv + 2] = 0;
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

    var indices = new Uint16Array(3*NT);
    indv = 0;

    for(var i = 0; i < ltri.length; i++)
    {
    	indices[indv]     = ltri[i][0];
    	indices[indv + 1] = ltri[i][1];
    	indices[indv + 2] = ltri[i][2];
    	indv = indv + 3;
    }
//******END OF ALTERED CODE*******

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

// Rotation angle (degrees/second)
var ANGLE_STEP = 30.0;
// Last time that this function was called
var g_last = Date.now();
function animate(angle) {
    // Calculate the elapsed time
    var now = Date.now();
    var elapsed = now - g_last;
    g_last = now;
    // Update the current rotation angle (adjusted by the elapsed time)
    var newAngle = angle + (ANGLE_STEP * elapsed) / 1000.0;
    return newAngle %= 360;
}