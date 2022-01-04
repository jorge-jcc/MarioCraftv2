#pragma once
#include "libs.h"

class MarioCraftCamera{
private:
	bool FP = false;
	FirstPersonCamera * Fpcamera = new FirstPersonCamera();
	Camera * camera = new ThirdPersonCamera();
	float distanceFromTarget = 7.0;
	bool enableCameraSelect = true;
	float Zoom = 45.0f;
public:
	MarioCraftCamera();
	void scrollCamera(GLFWwindow* window, double xoffset, double yoffset);
	void keyboardInput(GLFWwindow* window, double deltaTime, int offsetX, int offsetY);
	Camera* get();
	glm::mat4 getViewMatrix();
	void setCameraTarget(glm::vec3 cameraTarget);
	void setAngleTarget(float angleTarget);
	void updateCamera();
	glm::vec3 getPosition();
	float getZoom();
};

