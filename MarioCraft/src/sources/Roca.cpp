#include "Roca.h"

void Roca::Load(Shader* shader) {
	MarioCraftModel::loadModel("../models/Rock/Rock.obj");
	MarioCraftModel::setShader(shader);
	show = false;
}

void Roca::InitMatrices(RocaValues roca, Terrain* terrain) {
	show = true;
	this->roca = roca;
	glm::mat4 aux = glm::mat4(1.f);
	aux = glm::translate(aux, glm::vec3(roca.X, 0.f, roca.Z));
	aux = glm::scale(aux, glm::vec3(0.3f, 0.3f, 0.3f));
	aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]) + 0.6;
	MarioCraftModel::Init(aux);
}

void Roca::Render() {
	if (show)
		MarioCraftModel::Render();
}

void Roca::animate() {
	if (show) {
		matrix = glm::translate(matrix, glm::vec3(roca.translate));
		matrix = glm::rotate(matrix, glm::radians(5.f), glm::vec3(roca.rotate));
	}
}

RocaValues Roca::newRoca(float X, float Z, glm::vec3 transalte, glm::vec3 rotate){
	RocaValues roca;
	roca.X = X;
	roca.Z = Z;
	roca.translate = glm::vec3(transalte);
	roca.rotate = glm::vec3(rotate);
	return roca;
}
