#include "Moneda.h"

void Moneda::Load(Shader* shader){
	MarioCraftModel::loadModel("../models/Moneda/Moneda.obj");
	MarioCraftModel::setShader(shader);
}

void Moneda::InitMatrices(vector<float> moneditas, Terrain* terrain){
	glm::mat4 aux;
	for (int i = 0; i < moneditas.size(); i += 3) {
		aux = glm::translate(glm::mat4(1.f), glm::vec3(moneditas[i], 0.0f, moneditas[i + 2]));
		aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]) + moneditas[i + 1];
		matrices["moneda-" + std::to_string(i)] = aux;
	}
}

void Moneda::removeMoneda(string moneda){
	matrices.erase(moneda);
}

void Moneda::Render(){
	for (std::map<string, glm::mat4>::iterator it = matrices.begin(); it != matrices.end(); it++) {
		MarioCraftModel::Init(it->second);
		MarioCraftModel::Render();
	}
}

void Moneda::animate(){
	for (std::map<string, glm::mat4>::iterator it = matrices.begin(); it != matrices.end(); it++) {
		it->second = glm::rotate(it->second, glm::radians(5.f), glm::vec3(0.f, 1.f, 0.f));
	}
}
