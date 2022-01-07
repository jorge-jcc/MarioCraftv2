#pragma once
#include "libs.h"
#include "MarioCraftModel.h"
#include "MarioCraftCamera.h"

enum tipoModel { STATIC, DYNAMIC };

class ModelManager {
private:
	std::vector<MarioCraftModel*> staticModels;
	//std::vector<DynamicModel*> dymanicModels;
public:
	void addModel(MarioCraftModel*, tipoModel tipo = STATIC);
	void renderModels();
	void renderBlending(MarioCraftCamera *);
	void prepareModels(Shader * shader);
	void keyboardInputModels();
	void updateModels();
	void destroy();
};