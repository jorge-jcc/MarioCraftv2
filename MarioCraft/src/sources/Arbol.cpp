#include "Arbol.h"

void Arbol::Load(Shader* shader){
	MarioCraftModel::loadModel("../models/ArbolMinecraft1/tronco.obj");
	MarioCraftModel::setShader(shader);

	hojas->loadModel("../models/ArbolMinecraft1/arbol.obj");
	hojas->setShader(shader);
	hojas->mcEnable(DEPTH);
}

void Arbol::InitMatrices(vector<Bosque> arboles, Terrain* terrain){
	glm::mat4 aux;
	int ren = 5;
	int lim;
	for (int a = 0; a < arboles.size(); a++) {
		for (int i = 0; i < arboles[a].col; i++) {
			lim = (i % 2) == 0 ? arboles[a].ren : arboles[a].ren - 1;
			for (int j = 0; j < lim; j++) {
				float X = arboles[a].X <= 0.f ? arboles[a].X - 6.f * i : arboles[a].X + 6.f * i;
				float Z = arboles[a].Z <= 0.f ? 
					-((i % 2) == 0 ? -arboles[a].Z : -arboles[a].Z + 3.f) - 6.f * j 
					: ((i % 2) == 0 ? arboles[a].Z : arboles[a].Z + 3.f) + 6.f * j;
				aux = glm::translate(glm::mat4(1.f), glm::vec3(X, 0.0, Z));
				aux = glm::scale(aux, glm::vec3(3.f, 3.f, 3.f));
				aux[3][1] = terrain->getHeightTerrain(aux[3][0], aux[3][2]);
				matrices.push_back(aux);
			}
		}
	}
}

void Arbol::Render(){
	for (int i = 0; i < matrices.size(); i++) {
		MarioCraftModel::Init(matrices[i]);
		MarioCraftModel::Render();
		hojas->Init(matrices[i]);
		hojas->Render();
	}
}

void Arbol::setShader(Shader* shader){
	MarioCraftModel::setShader(shader);
	hojas->setShader(shader);
}

Bosque Arbol::newArbol(float ren, float col, float X, float Z){
	Bosque arbol;
	arbol.ren = ren;
	arbol.col = col;
	arbol.X = X;
	arbol.Z = Z;
	return arbol;
}
