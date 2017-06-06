//prog3_Holmes.js
//Colby Holmes
//3/8/17
//Creates an array of objects
//that each move in an interesting way,
//the speed can be altered between SLOW, MEDIUM, and FAST,
//and the animation can be toggled

//*Note to Grader*
//I received a 5 point deduction on the last program for formatting the description incorrectly.
//Before I get silly deductions on this assignment please at least specify what format you expect.
//There is none written on the course syllabus and I've no idea where else to look.
//Thank You

"use strict";

// Vertex shader program
var VSHADER_SOURCE =
  'attribute vec4 a_Position;\n' +
  'uniform mat4 u_ModelMatrix;\n' +
  'void main() {\n' +
  '  gl_Position = u_ModelMatrix * a_Position;\n' +
  '  gl_PointSize = 5.0;' +//anchor size
  '}\n';


// Fragment shader program
var FSHADER_SOURCE =
  'precision mediump float;\n' +
  'uniform vec4 u_FragColor;\n' +  
  'void main() {\n' +
  '  gl_FragColor = u_FragColor;\n' + //dynamic coloring
  '}\n';

// Rotation angle (degrees/second)
var ANGLE_STEP = 90.0;
// Bob radius
var RAD = 0.1;
// Wire length
var LEN = 0.5;
var PAUSE = 0;
var HOLD = 90.0;

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

    // Write the positions of vertices to a vertex shader
    var n = initVertexBuffers(gl);
    if (n < 0) {
        console.log('Failed to set the positions of the vertices');
        return;
    }

    // Get the storage location of u_FragColor
    var u_FragColor = gl.getUniformLocation(gl.program, 'u_FragColor');
    if (!u_FragColor) {
        console.log('Failed to get the storage location of u_FragColor');
        return;
    }

    // Specify the color for clearing <canvas>
    gl.clearColor(0, 0, 0, 1);

    // Get storage location of u_ModelMatrix
    var u_ModelMatrix = gl.getUniformLocation(gl.program, 'u_ModelMatrix');
    if (!u_ModelMatrix) {
        console.log('Failed to get the storage location of u_ModelMatrix');
        return;
    }

    // Current rotation angle
    var currentAngle = 0.0;
    // Model matrix
    var modelMatrix = new Matrix4();

    // Start drawing
    var tick = function () {
        currentAngle = animate(currentAngle);  // Update the rotation angle
        draw(gl, n, currentAngle, modelMatrix, u_ModelMatrix, u_FragColor);   // Draw the triangle
        requestAnimationFrame(tick, canvas);   // Request that the browser ?calls tick
    };
    tick();
}

function initVertexBuffers(gl) {
    var vertices = new Float32Array([ //stored all the objects in a single array
//line
    0.0, 0.0, .1, .1,
//triangle
    0.0, 0.0, RAD, RAD, -RAD, RAD,
//hexagon
    //1st     2nd                                     3rd    
      RAD, 0,    1 / 2 * RAD, -(Math.sqrt(3) / 2) * RAD,   -1 / 2 * RAD, -(Math.sqrt(3) / 2) * RAD,
    //4th     5th                                     6th
      -RAD, 0,   -1 / 2 * RAD, (Math.sqrt(3) / 2) * RAD,   1 / 2 * RAD, (Math.sqrt(3) / 2) * RAD
    ]);

    var n = 9;   // The number of vertices

    // Create a buffer object
    var vertexBuffer = gl.createBuffer();
    if (!vertexBuffer) {
        console.log('Failed to create the buffer object');
        return -1;
    }

    // Bind the buffer object to target
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
    // Write date into the buffer object
    gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);

    // Assign the buffer object to a_Position variable
    var a_Position = gl.getAttribLocation(gl.program, 'a_Position');
    if (a_Position < 0) {
        console.log('Failed to get the storage location of a_Position');
        return -1;
    }
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, 0, 0);

    // Enable the assignment to a_Position variable
    gl.enableVertexAttribArray(a_Position);

    return n;
}

function draw(gl, n, currentAngle, modelMatrix, u_ModelMatrix, u_FragColor) {
//hexagon!
    // Set the rotation matrix
    modelMatrix.setRotate(currentAngle, 0, 0, 1);
    modelMatrix.translate(LEN, 0, 0);

    // Pass the rotation matrix to the vertex shader
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);

    // Clear <canvas>
    gl.clear(gl.COLOR_BUFFER_BIT);

    // Pass the color of a point to u_FragColor variable
    gl.uniform4f(u_FragColor, 1.0, 0.0, 0.0, 1.0); //red

    gl.drawArrays(gl.TRIANGLE_FAN, 2, 3);

//triangle!
    //orbit first object
    modelMatrix.setRotate(currentAngle, 0, 0, 1);
    modelMatrix.translate(LEN + (.2 * Math.cos(currentAngle * .1) + .2 * Math.sin(.1 * currentAngle)),
        (.2 * Math.cos(currentAngle * .1) - .2 * Math.sin(.1 * currentAngle)), 0);

    // Pass the rotation matrix to the vertex shader
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);

    // Pass the color of a point to u_FragColor variable
    gl.uniform4f(u_FragColor, 1.0, 0.0, 1.0, 1.0);//violet

    // Draw the hexagon
    gl.drawArrays(gl.TRIANGLE_FAN, 5, 6);

//polygon!
    //orbit first object
    modelMatrix.setRotate(currentAngle, currentAngle * LEN, currentAngle * RAD, 1);
    modelMatrix.translate(0, 0, 0);

    // Pass the rotation matrix to the vertex shader
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);

    // Pass the color of a point to u_FragColor variable
    gl.uniform4f(u_FragColor, 1.0, 1.0, 0.0, 1.0); //yellow

    gl.drawArrays(gl.TRIANGLE_FAN, 2, 6);

    //polygon!
    //orbit first object
    modelMatrix.setRotate(10 * Math.cos(currentAngle * .1), 0, 0);
    modelMatrix.translate(Math.cos(currentAngle * .017), Math.cos(currentAngle * .017), 0);

    // Pass the rotation matrix to the vertex shader
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);

    // Pass the color of a point to u_FragColor variable
    gl.uniform4f(u_FragColor, 0.0, 1.0, 1.0, 1.0); //cyan

    gl.drawArrays(gl.TRIANGLE_FAN, 4, 4);
}

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

function slow() {
    ANGLE_STEP = 45.0;
}

function medium() {
    ANGLE_STEP = 90.0;
}

function fast() {
    ANGLE_STEP = 180.0;
}

function pause() {
    if (PAUSE == 0) {
        PAUSE = 1;
        HOLD = ANGLE_STEP;
        ANGLE_STEP = 0.0;
    }
    else {
        PAUSE = 0;
        ANGLE_STEP = HOLD;
    }

}