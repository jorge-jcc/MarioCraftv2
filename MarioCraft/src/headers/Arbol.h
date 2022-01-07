#pragma once
#include "libs.h"
#include "MarioCraftModel.h"

typedef struct {
	float ren;
	float col;
	float X;
	float Z;
} Bosque;

class Arbol : public MarioCraftModel{
private:
	MarioCraftModel* hojas = new MarioCraftModel();
public:
	vector<glm::mat4> matrices;

	void Load(Shader* shader);
	void InitMatrices(vector<Bosque>, Terrain*);
	void Render() override;
	void setShader(Shader*) override;
	static Bosque newArbol(float ren, float col, float X, float Z);
};

