#version 460 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 outTexCoords;
out vec3 outFragPosition;
out vec3 outNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    outTexCoords = texCoords;

    outFragPosition = vec3(model * vec4(vertex, 1.0));

    outNormal = mat3(transpose(inverse(model))) * normal;

    gl_Position = proj * view * vec4(outFragPosition, 1.0);
}