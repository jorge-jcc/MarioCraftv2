#pragma once
#include "MarioCraftModel.h"

using  namespace std;

MarioCraftModel::MarioCraftModel() {
	this->matrix = glm::mat4(1.0f);
}

MarioCraftModel::~MarioCraftModel() {
	Model::destroy();
}

MarioCraftModel* MarioCraftModel::Init(glm::mat4 matrixInit) {
	this->matrix = matrixInit;
	return this;
}

MarioCraftModel* MarioCraftModel::Rotate(float ang, float rX, float rY, float rZ) {
	this->matrix = glm::rotate(this->matrix, glm::radians(ang), glm::vec3(rX, rY, rZ));
	return this;
}

MarioCraftModel* MarioCraftModel::Translate(float tX, float tY, float tZ) {
	this->matrix = glm::translate(this->matrix, glm::vec3(tX, tY, tZ));
	return this;
}

MarioCraftModel* MarioCraftModel::Scale(float sX, float xY, float sZ) {
	this->matrix = glm::scale(this->matrix, glm::vec3(sX, xY, sZ));
	return this;
}

void MarioCraftModel::Render() {
	Model::render(this->matrix);
}

void MarioCraftModel::keyboardInput()
{
}

void MarioCraftModel::animate() {
}

void MarioCraftModel::setShader(Shader* shader) {
	Model::setShader(shader);
}

void MarioCraftModel::mcEnable(MCenum value) {
	glm::mat4 matrixCollider;
	switch (value) {
	case BLENDING:
		normalRender = false;
		blending = true;
		break;
	case DEPTH:
		normalRender = false;
		depth = true;
		break;
	case COLL_OBB:
		collider = true;
		coll.OBB = new AbstractModel::OBB();
		coll.OBB->u = glm::quat_cast(this->matrix);
		matrixCollider = glm::scale(this->matrix, glm::vec3(1.0, 1.0, 1.0));
		matrixCollider = glm::translate(matrixCollider, this->getObb().c);
		coll.OBB->c = glm::vec3(matrixCollider[3]);
		coll.OBB->e = this->getObb().e * glm::vec3(1.0, 1.0, 1.0);
		break;
	case COLL_SBB:
		collider = true;
		coll.SBB = new AbstractModel::SBB();
		matrixCollider = glm::scale(this->matrix, glm::vec3(1.0, 1.0, 1.0));
		matrixCollider = glm::translate(matrixCollider, this->getSbb().c);
		coll.SBB->c = glm::vec3(matrixCollider[3]);
		coll.SBB->ratio = this->getSbb().ratio * 1.0;
		break;
	default:
		break;
	}
}