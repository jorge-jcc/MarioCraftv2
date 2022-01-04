#include "MarioCraftCamera.h"

MarioCraftCamera::MarioCraftCamera(){
	camera->setPosition(glm::vec3(0.0, 0.0, 10.0));
	camera->setDistanceFromTarget(distanceFromTarget);
	camera->setSensitivity(1.0);

	Fpcamera->setPosition(glm::vec3(0.0, 0.0, 10.0));
	Fpcamera->setDistanceFromTarget(distanceFromTarget);
}

void MarioCraftCamera::scrollCamera(GLFWwindow* window, double xoffset, double yoffset){
	distanceFromTarget -= yoffset;
	if (FP) {
		if (Zoom >= 1.0f && Zoom <= 45.0f)
			Zoom -= yoffset;
		if (Zoom <= 1.0f)
			Zoom = 1.0f;
		if (Zoom >= 45.0f)
			Zoom = 45.0f;
	}
	else
		camera->setDistanceFromTarget(distanceFromTarget);
}

void MarioCraftCamera::keyboardInput(GLFWwindow* window, double deltaTime, int offsetX, int offsetY){
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		camera->mouseMoveCamera(offsetX, offsetY, deltaTime);
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		camera->mouseMoveCamera(0.0, offsetY, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		Fpcamera->moveFrontCamera(true, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		Fpcamera->moveFrontCamera(false, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		Fpcamera->moveRightCamera(false, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		Fpcamera->moveRightCamera(true, deltaTime);
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		Fpcamera->mouseMoveCamera(offsetX, offsetY, deltaTime);

	if (enableCameraSelect && glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		enableCameraSelect = false;
		FP = !FP;
		if (FP)
			Fpcamera->setPosition(camera->getPosition());
	}
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
		enableCameraSelect = true;
}

Camera* MarioCraftCamera::get() {
	if (FP)
		return Fpcamera;
	return camera;
}

glm::mat4 MarioCraftCamera::getViewMatrix(){
	if (FP)
		return Fpcamera->getViewMatrix();
	return camera->getViewMatrix();
}

void MarioCraftCamera::setCameraTarget(glm::vec3 cameraTarget) {
	camera->setCameraTarget(cameraTarget);
}
void  MarioCraftCamera::setAngleTarget(float angleTarget) {
	camera->setAngleTarget(angleTarget);
}

void MarioCraftCamera::updateCamera() {
	camera->updateCamera();
	Fpcamera->updateCamera();
}

glm::vec3 MarioCraftCamera::getPosition() {
	if (FP)
		return Fpcamera->getPosition();
	return camera->getPosition();
}

float MarioCraftCamera::getZoom(){
	if (FP)
		return Zoom;
	return 45.0f;
}
