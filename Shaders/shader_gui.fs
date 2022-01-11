#version 400
in vec2 textureCoords;
out vec4 out_Color;

uniform sampler2D guiTexture;

void main(void){
	//out_Color = vec4(1.0, 0.0, 0.0, 0.0);
	out_Color = texture(guiTexture,textureCoords);
}