#include "Antorcha.h"

void Antorcha::Load(Shader * shader){
	MarioCraftModel::loadModel("../models/Antorcha/Torch.obj");
	MarioCraftModel::setShader(shader);
}

void Antorcha::InitMatrices(vector<float> antorchas, Terrain* terrain){
	glm::mat4 aux;
	for (int i = 0; i < antorchas.size(); i += 2) {
		aux = glm::translate(glm::mat4(1.f), glm::vec3(antorchas[i], 0.0f, antorchas[i+1]));
		aux = glm::scale(aux, glm::vec3(2.0f, 2.0f, 2.0f));
		aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]);
		matrices.push_back(aux);
	}
}

void Antorcha::Render(){
	for (int i = 0; i < matrices.size(); i++) {
		MarioCraftModel::Init(matrices[i]);
		MarioCraftModel::Render();
	}
}
