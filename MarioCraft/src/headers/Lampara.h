#pragma once
#include "libs.h"
#include "MarioCraftModel.h"

class Lampara : public MarioCraftModel {
public:
	vector<glm::mat4> matrices;

	void Load(Shader* shader);
	void InitMatrices(vector<float>, Terrain*);
	void Render() override;
};