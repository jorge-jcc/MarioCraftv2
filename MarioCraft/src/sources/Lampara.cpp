#include "Lampara.h"

void Lampara::Load(Shader* shader) {
	MarioCraftModel::loadModel("../models/lamp/lamp.obj");
	MarioCraftModel::setShader(shader);
	MarioCraftModel::mcEnable(DEPTH);
}

void Lampara::InitMatrices(vector<float> antorchas, Terrain* terrain) {
	glm::mat4 aux;
	for (int i = 0; i < antorchas.size(); i += 2) {
		aux = glm::translate(glm::mat4(1.f), glm::vec3(antorchas[i], 0.0f, antorchas[i+1]));
		aux = glm::scale(aux, glm::vec3(0.15f, 0.15f, 0.15f));
		aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]);
		matrices.push_back(aux);
	}
}

void Lampara::Render() {
	for (int i = 0; i < matrices.size(); i++) {
		MarioCraftModel::Init(matrices[i]);
		MarioCraftModel::Render();
	}
}
