#pragma once
#include "libs.h"
#include "MarioCraftModel.h"


struct RocaValues {
	float X;
	float Z;
	glm::vec3 translate;
	glm::vec3 rotate;
};

class Roca: public MarioCraftModel{
public:
	bool show;
	RocaValues roca;

	void Load(Shader* shader);
	void InitMatrices(RocaValues, Terrain*);
	void Render() override;
	void animate() override;

	static RocaValues newRoca(float, float, glm::vec3, glm::vec3);
};

