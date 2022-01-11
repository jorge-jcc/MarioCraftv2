#pragma once
#include "libs.h"
#include "MarioCraftTexture.h"

class GuiTexture{
public:
	MarioCraftTexture *texture;
	glm::mat4 matrix;

	GuiTexture(const string&, glm::vec2, glm::vec2);
};

