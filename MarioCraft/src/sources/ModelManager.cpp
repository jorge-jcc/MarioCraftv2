#include "ModelManager.h"

// addModel registra un nuevo modelo en la lista de modelos
void ModelManager::addModel(MarioCraftModel* model, tipoModel tipo) {
	staticModels.push_back(model);
}

// renderModels recorre la lista de modelos e invoca para cada uno su metodo draw
void ModelManager::renderModels() {
	for (MarioCraftModel * model : staticModels)
		if(model->normalRender)
			model->Render();
}

void ModelManager::keyboardInputModels() {
	for (MarioCraftModel * model : staticModels)
		model->keyboardInput();
}

// 
void ModelManager::updateModels() {
	for (MarioCraftModel * model : staticModels)
		model->animate();
}

void ModelManager::renderBlending(MarioCraftCamera* camera) {
	std::map<float, MarioCraftModel*> blendingSorted;
	for (MarioCraftModel * model : staticModels) {
		if (model->depth) {
			float distanceFromView = glm::length(camera->getPosition() - glm::vec3(model->matrix[3]));
			blendingSorted[distanceFromView] = model;
		}
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	for (std::map<float, MarioCraftModel*>::reverse_iterator it = blendingSorted.rbegin(); it != blendingSorted.rend(); it++) {
		it->second->Render();
	}
	glEnable(GL_CULL_FACE);
}

void ModelManager::prepareModels(Shader * shader) {
	for (MarioCraftModel * model : staticModels)
			model->setShader(shader);
}