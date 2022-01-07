#include "CasasToad.h"

CasasToad::CasasToad(){

}

CasasToad::~CasasToad() {
}

void CasasToad::Load(vector<CasaToad> casas, Shader* shader) {
	this->casas = casas;

	casaRoja->loadModel("../models/CasaToad/casaToadRoja/casatoad.obj");
	casaRoja->setShader(shader);
	casaRoja->mcEnable(DEPTH);
	
	casaAzul->loadModel("../models/CasaToad/casaToadAzul/casatoad.obj");
	casaAzul->setShader(shader);
	casaAzul->mcEnable(DEPTH);

}

void CasasToad::InitMatrices(Terrain* terrain) {
	glm::mat4 aux;
	for (int i = 0; i < casas.size(); i++) {
		aux = glm::translate(glm::mat4(1.f), glm::vec3(casas[i].X, 0.0f, casas[i].Z));
		aux = glm::rotate(aux, glm::radians(casas[i].rot), glm::vec3(0.f, 1.f, 0.f));
		aux = glm::scale(aux, glm::vec3(3.0f, 3.0f, 3.0f));
		aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]);
		matrices.push_back(aux);
	}
}

void CasasToad::Render(){
	for(int i = 0; i < casas.size(); i++) {
		if (casas[i].tipo == ROJA) {
			casaRoja->Init(matrices[i]);
			casaRoja->Render();
		}
		else {
			casaAzul->Init(matrices[i]);
			casaAzul->Render();
		}
	}
}

void CasasToad::setShader(Shader* shader){
	casaRoja->setShader(shader);
	casaAzul->setShader(shader);
}

CasaToad CasasToad::newCasa(tipoCasa tipo, float X, float Z, float rot){
	CasaToad casa;
	casa.tipo = tipo;
	casa.X = X;
	casa.Z = Z;
	casa.rot = rot;
	casa.fire = (rand() % 2 == 0);
	return casa;
}

