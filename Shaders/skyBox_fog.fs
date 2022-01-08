#version 330 core

in vec3 our_uv;
out vec4 color;

uniform samplerCube skybox;
uniform samplerCube skyboxNight;
uniform float blendFactor;

uniform float lowerLimit = 0.0;
uniform float upperLimit = 0.02;
uniform vec3 fogColor;

void main(){
    vec4 texture1 = texture(skybox, our_uv);
    vec4 texture2 = texture(skyboxNight, our_uv);
    vec4 finalColor = mix(texture1, texture2, blendFactor);

    float factor = (our_uv.y - lowerLimit) / (upperLimit - lowerLimit);
    factor = clamp(factor, 0.0, 1.0); // Acota entre 0 y 1
    color = mix(vec4(fogColor, 1.0), finalColor, factor);
}
