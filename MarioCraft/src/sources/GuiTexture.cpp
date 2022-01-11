#include "GuiTexture.h"

GuiTexture::GuiTexture(const string& FileName, glm::vec2 position, glm::vec2 scale){
	texture = new MarioCraftTexture(FileName);
	glm::mat4 aux = glm::mat4(1.f);
	aux = glm::translate(aux, glm::vec3(position, 0.f));
	aux = glm::scale(aux, glm::vec3(scale, 0.f));
	matrix = aux;
}
