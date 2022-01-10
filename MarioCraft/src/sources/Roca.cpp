#include "Roca.h"

void Roca::Load(Shader* shader) {
	MarioCraftModel::loadModel("../models/Rock/Rock.obj");
	MarioCraftModel::setShader(shader);
}

void Roca::InitMatrices(Terrain* terrain) {
	show = false;
	glm::mat4 aux = glm::mat4(1.f);
	aux = glm::translate(aux, glm::vec3(93.f, 0.f, 48.f));
	aux = glm::scale(aux, glm::vec3(0.3f, 0.3f, 0.3f));
	aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]) + 0.6;
	matrix = aux;
}

void Roca::Render() {
	if (show)
		MarioCraftModel::Render();
}

void Roca::animate() {
	if (show) {
		MarioCraftModel::Translate(-0.7f, 0.f, 0.f);
		MarioCraftModel::Rotate(5.f, 1.f, 0.f, 0.f);
	}
}
