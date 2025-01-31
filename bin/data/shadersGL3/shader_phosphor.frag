OF_GLSL_SHADER_HEADER

uniform sampler2D tex0;

uniform vec2 resolution;

uniform float test;

out vec4 fragColor; // Explicit output variable

void main() {
  vec2 uv = gl_FragCoord.xy / resolution.xy;
  float x = 0.0016;
  float y = 0.0022;

  vec4 color =
    texture(tex0, uv) +
    texture(tex0, uv + vec2(x, y)) +
    texture(tex0, uv + vec2(x, -y)) +
    texture(tex0, uv + vec2(-x, y)) +
    texture(tex0, uv + vec2(-x, -y));
  color.rgb = color.rgb * 0.18;

  if (color.r < 0.01) {
    color = vec4(0.0);
  }

  fragColor = color;
}