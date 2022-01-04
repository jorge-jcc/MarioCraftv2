#include "MarioCraftTerrain.h"

MarioCraftTerrain::MarioCraftTerrain(
	float gridX, float gridZ, float size, float maxHeight, string heightMap, Shader* shader
) : Terrain(gridX, gridZ, size, maxHeight, heightMap) {
	Terrain::init();
	Terrain::setShader(shader);
	Terrain::setPosition(glm::vec3(100, 0, 100));
}

MarioCraftTerrain::~MarioCraftTerrain() {
	Terrain::destroy();
}
