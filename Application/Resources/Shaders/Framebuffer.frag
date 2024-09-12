#version 460 core

out vec4 fragColor;

in vec2 outTexCoords;

uniform sampler2D screenTexture;

void main() {
    vec3 color = texture(screenTexture, outTexCoords).rgb;
    vec3 gammaCorrection = pow(color, vec3(1.0/2.2));
    fragColor = vec4(gammaCorrection, 1.0);
}