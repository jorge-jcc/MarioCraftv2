#pragma once
#include "libs.h"
#include "MarioCraftModel.h"

class Roca: public MarioCraftModel{
public:
	bool show;

	void Load(Shader* shader);
	void InitMatrices( Terrain*);
	void Render() override;
	void animate() override;
};

