OF_GLSL_SHADER_HEADER

precision mediump float;

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

void main() {
    gl_Position = modelViewProjectionMatrix * position;
}