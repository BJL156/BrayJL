#version 460 core

out vec4 fragColor;

in vec2 outTexCoords;
in vec3 outFragPosition;
in vec3 outNormal;

uniform sampler2D texture_diffuse1;

void main() {
    fragColor = texture(texture_diffuse1, outTexCoords);
}