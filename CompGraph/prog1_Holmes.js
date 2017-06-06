// prog1_ColbyHolmes.js
// Chaos Game program

var VSHADER_SOURCE = 
  'attribute vec4 a_Position;\n' + // attribute variable
  'void main() {\n' +
  '  gl_Position = a_Position;\n' +
  '  gl_PointSize = 1.0;\n' +
  '}\n';

// Fragment shader program
var FSHADER_SOURCE = 
  'void main() {\n' +
  '  gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);\n' + //changed to yellow, more "triforce" asthetic
  '}\n';

function main() {
  // Retrieve <canvas> element
  var canvas = document.getElementById('webgl');
  var v1 = [0.0, 1.0]; //coordinates (no z necessary
  var v2 = [-1.0, -1.0];
  var v3 = [1.0, -1.0];
  var p0 = [0.0, 0.0]; //start point
  var i, n = 40000, rand;

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

  // Get the storage location of a_Position
  var a_Position = gl.getAttribLocation(gl.program, 'a_Position');
  if (a_Position < 0) {
    console.log('Failed to get the storage location of a_Position');
    return;
  }//*/


  // Pass vertex position to attribute variable
  gl.vertexAttrib3f(a_Position, p0[0], p0[1], 0.0);
 

  // Specify the color for clearing <canvas>
  gl.clearColor(0.0, 0.0, 0.0, 1.0);

  // Clear <canvas>
  gl.clear(gl.COLOR_BUFFER_BIT);

  // Draw
  gl.drawArrays(gl.POINTS, 0, 1);
  
  for (i = 0; i < n; i++) {
      rand = Math.floor((Math.random() * 3) + 1);//choose v to move towards
      switch (rand) {
          case 1: //v1
              p0[0] = (p0[0] + v1[0]) / 2;//x
              p0[1] = (p0[1] + v1[1]) / 2;//y
              break;
          case 2: //v2
              p0[0] = (p0[0] + v2[0]) / 2;//x
              p0[1] = (p0[1] + v2[1]) / 2;//y
              break;
          case 3: //v3
              p0[0] = (p0[0] + v3[0]) / 2;//x
              p0[1] = (p0[1] + v3[1]) / 2;//y
              break;
      }
      // Pass vertex position to attribute variable
      gl.vertexAttrib3f(a_Position, p0[0], p0[1], 0.0);

      // Draw
      gl.drawArrays(gl.POINTS, 0, 1);
  }

}