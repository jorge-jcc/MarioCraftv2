#pragma once
#include "libs.h"

using  namespace std;

class MarioCraftTerrain : public Terrain {
private:
	string rutaObj;
public:
	MarioCraftTerrain(float gridX, float gridZ, float size, float maxHeight, string heightMap, Shader*);
	~MarioCraftTerrain();
};