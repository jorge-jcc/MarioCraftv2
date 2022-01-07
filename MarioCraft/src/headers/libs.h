#pragma once
#include <stdlib.h>
#include <string>		
#include <random>
#include <vector>

#include "Headers/Model.h"
#include "Headers/Shader.h"
#include "Headers/Terrain.h"
#include "Headers/FirstPersonCamera.h"
#include "Headers/ThirdPersonCamera.h"
#include "Headers/TimeManager.h"

#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>