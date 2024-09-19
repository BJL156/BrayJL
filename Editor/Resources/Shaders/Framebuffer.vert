#version 460 core

layout (location = 0) in vec2 vertex;
layout (location = 1) in vec2 texCoords;

out vec2 outTexCoords;

void main() {
    gl_Position = vec4(vertex, 0.0, 1.0);
    outTexCoords = texCoords;
}