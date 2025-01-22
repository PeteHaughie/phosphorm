OF_GLSL_SHADER_HEADER

precision mediump float;

uniform sampler2D tex0;
varying vec2 texCoordVarying;
uniform float test;

void main() {
  float x = 0.0016;
  float y = 0.0022;

  vec4 color =
    texture2D(tex0, texCoordVarying) +
    texture2D(tex0, texCoordVarying + vec2(x, y)) +
    texture2D(tex0, texCoordVarying + vec2(x, -y)) +
    texture2D(tex0, texCoordVarying + vec2(-x, y)) +
    texture2D(tex0, texCoordVarying + vec2(-x, -y));
  color.rgb = color.rgb * 0.18;

  if (color.r < 0.01) {
    color = vec4(0.0);
  }

  gl_FragColor = color;
}
