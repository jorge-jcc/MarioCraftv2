#pragma once
#include "libs.h"
#include "MarioCraftModel.h"

class Moneda : public MarioCraftModel {
public:
	map<string, glm::mat4> matrices;

	void Load(Shader* shader);
	void InitMatrices(vector<float>, Terrain*);
	void removeMoneda(string moneda);
	void Render() override;
	void animate() override;
};

