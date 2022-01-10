#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
//glew include
#include <GL/glew.h>

//std includes
#include <string>
#include <iostream>

// contains new std::shuffle definition
#include <algorithm>
#include <random>

//glfw include
#include <GLFW/glfw3.h>

// program include
#include "Headers/TimeManager.h"

// Shader include
#include "Headers/Shader.h"

// Model geometric includes
#include "Headers/Sphere.h"
#include "Headers/Cylinder.h"
#include "Headers/Box.h"

//GLM include
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Headers/Texture.h"

// Include loader Model class
#include "Headers/Model.h"

// Include Terrain
#include "Headers/Terrain.h"

#include "Headers/AnimationUtils.h"

// Include Colision headers functions
#include "Headers/Colisiones.h"

// 
#include "Headers/ShadowBox.h"

// OpenAL include
#include <AL/alut.h>

#include"MarioCraftCamera.h"
#include "MarioCraftModel.h"
#include "MarioCraftTexture.h"
#include "ModelManager.h"
#include "CasasToad.h"
#include "Arbol.h"
#include "Antorcha.h"
#include "Lampara.h"
#include "Moneda.h"
#include "Roca.h"
//#include "Dragon.h"

#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))
#define NUM_CASAS 2

int screenWidth;
int screenHeight;

const unsigned int SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;

GLFWwindow *window;

Shader shader;
//Shader con skybox
Shader shaderSkybox;
//Shader con multiples luces
Shader shaderMulLighting;
//Shader para el terreno
Shader shaderTerrain;
//Shader para las particulas de fountain
Shader shaderParticlesFountain;
//Shader para las particulas de fuego
Shader shaderParticlesFire;
//Shader para visualizar el buffer de profundidad
Shader shaderViewDepth;
//Shader para dibujar el buffer de profunidad
Shader shaderDepth;

MarioCraftCamera* camera = new MarioCraftCamera();

Sphere skyboxSphere(20, 20);
Box boxCollider;
Sphere sphereCollider(10, 10);
Box boxViewDepth;
Box boxLightViewBox;

ShadowBox * shadowBox;

ModelManager * models;

MarioCraftModel * castillo = new MarioCraftModel();
MarioCraftModel * aircraft2 = new MarioCraftModel();
MarioCraftModel * dragon = new MarioCraftModel();
MarioCraftModel * fortaleza = new MarioCraftModel();
MarioCraftModel * casa1 = new MarioCraftModel();
MarioCraftModel * casa2 = new MarioCraftModel();
MarioCraftModel * casa3 = new MarioCraftModel();
MarioCraftModel * casa4 = new MarioCraftModel();
MarioCraftModel * casa5 = new MarioCraftModel();
MarioCraftModel * casa6 = new MarioCraftModel();
MarioCraftModel * meta = new MarioCraftModel();
MarioCraftModel * puente = new MarioCraftModel();
MarioCraftModel * banca = new MarioCraftModel();
MarioCraftModel * lamp = new MarioCraftModel();
MarioCraftModel * laberinto = new MarioCraftModel();
MarioCraftModel * torre = new MarioCraftModel();
MarioCraftModel * speedCola = new MarioCraftModel();
MarioCraftModel * doubleTap = new MarioCraftModel();
MarioCraftModel * juggerNog = new MarioCraftModel();
MarioCraftModel * quickRevive = new MarioCraftModel();
CasasToad * casita = new CasasToad();
Arbol * arbol = new Arbol();
Antorcha * antorcha = new Antorcha();
Lampara * lampara = new Lampara();
Moneda * moneda = new Moneda();
Roca* roca = new Roca();

int puntos = 0;
int vida = 100;

// Mayow
Model spiderModelAnimate;
// Terrain model instance
Terrain terrain(-1, -1, 200, 16, "../Textures/heightmap.jpeg");

MarioCraftTexture * textureTerrainBackground;
MarioCraftTexture * textureTerrainR;
MarioCraftTexture * textureTerrainG;
MarioCraftTexture * textureTerrainB;
MarioCraftTexture * textureTerrainBlendMap;

MarioCraftTexture * textureParticleFire;

GLuint texId, textureTerrainBlendMapID;
GLuint skyboxTextureID;
GLuint nightSkyboxTextureID;

GLenum types[6] = {
GL_TEXTURE_CUBE_MAP_POSITIVE_X,
GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };

std::string fileNames[6] = { 
	"../Textures/skybox/right.jpg",
	"../Textures/skybox/left.jpg",
	"../Textures/skybox/top.jpg",
	"../Textures/skybox/bottom.jpg",
	"../Textures/skybox/front.jpg",
	"../Textures/skybox/back.jpg",
};

std::string nightFileNames[6] = {
	"../Textures/nightSkybox/right.png",
	"../Textures/nightSkybox/left.png",
	"../Textures/nightSkybox/top.png",
	"../Textures/nightSkybox/bottom.png",
	"../Textures/nightSkybox/front.png",
	"../Textures/nightSkybox/back.png",
};

const float rotate_speed = 1.f;
float rotation = 0;
float timeDay = 0.f;
glm::vec3 light = glm::vec3(0.05f);

bool exitApp = false;
int lastMousePosX, offsetX = 0;
int lastMousePosY, offsetY = 0;

// Model matrix definitions
glm::mat4 modelMatrixSpider = glm::mat4(1.0f);

int animationIndex = 4;
int modelSelected = 2;
bool enableCountSelected = true;

// Lamps positions
std::vector<glm::vec3> lamp1Position = { glm::vec3(-7.03, 0, -19.14), glm::vec3(
		24.41, 0, -34.57), glm::vec3(-10.15, 0, -54.10) };
std::vector<float> lamp1Orientation = { -17.0, -82.67, 23.70 };
std::vector<glm::vec3> lamp2Position = { glm::vec3(-36.52, 0, -23.24),
		glm::vec3(-52.73, 0, -3.90) };
std::vector<float> lamp2Orientation = { 21.37 + 90, -65.0 + 90 };

// Blending model unsorted
std::map<std::string, glm::vec3> blendingUnsorted = {
		{"aircraft", glm::vec3(10.0, 0.0, -17.5)},
		{"lambo", glm::vec3(23.0, 0.0, 0.0)},
		{"heli", glm::vec3(5.0, 10.0, -5.0)},
		{"fountain", glm::vec3(5.0, 0.0, -40.0)},
		{"fire", glm::vec3(0.f)}
};

double deltaTime;
double currTime, lastTime;

// Jump variables
bool isJump = false;
float GRAVITY = 1.81;
double tmv = 0;
double startTimeJump = 0;

bool isPlataform = false;
float platformHeight;

// Definition for the particle system
GLuint initVel, startTime;
GLuint VAOParticles;
GLuint nParticles = 8000;
double currTimeParticlesAnimation, lastTimeParticlesAnimation;

// Definition for the particle system fire
GLuint initVelFire, startTimeFire;
GLuint VAOParticlesFire;
GLuint nParticlesFire = 2000;
GLuint posBuf[2], velBuf[2], age[2];
GLuint particleArray[2];
GLuint feedback[2];
GLuint drawBuf = 1;
float particleSize = 0.5, particleLifetime = 3.0;
double currTimeParticlesAnimationFire, lastTimeParticlesAnimationFire;

// Colliders
std::map<std::string, std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> > collidersOBB;
std::map<std::string, std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> > collidersSBB;

// Framesbuffers
GLuint depthMap, depthMapFBO;

/**********************
 * OpenAL config
 */

 // OpenAL Defines
#define NUM_BUFFERS 5
#define NUM_SOURCES 5
#define NUM_ENVIRONMENTS 1
// Listener
ALfloat listenerPos[] = { 0.0, 0.0, 0.0 };
ALfloat listenerVel[] = { 0.0, 0.0, 0.0 };
ALfloat listenerOri[] = { 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
// Source 0
ALfloat source0Pos[] = { 0.0, 0.0, 0.0 };
ALfloat source0Vel[] = { 0.0, 0.0, 0.0 };
// Source 1
ALfloat source1Pos[] = { 0.0, 0.0, 0.0 };
ALfloat source1Vel[] = { 0.0, 0.0, 0.0 };
// Source 2
ALfloat source2Pos[] = { 0.0, 0.0, 0.0 };
ALfloat source2Vel[] = { 0.0, 0.0, 0.0 };
// Source 3
ALfloat source3Pos[] = { 0.0, 0.0, 0.0 };
ALfloat source3Vel[] = { 0.0, 0.0, 0.0 };
// Source 4
ALfloat source4Pos[] = { 0.0, 0.0, 0.0 };
ALfloat source4Vel[] = { 0.0, 0.0, 0.0 };
// Buffers
ALuint buffer[NUM_BUFFERS];
ALuint source[NUM_SOURCES];
ALuint environment[NUM_ENVIRONMENTS];
// Configs
ALsizei size, freq;
ALenum format;
ALvoid *data;
int ch;
ALboolean loop;
std::vector<bool> sourcesPlay = { true, true, true, true, false, };

// Se definen todos las funciones.
void reshapeCallback(GLFWwindow *Window, int widthRes, int heightRes);
void keyCallback(GLFWwindow *window, int key, int scancode, int action,
	int mode);
void mouseCallback(GLFWwindow *window, double xpos, double ypos);
void mouseButtonCallback(GLFWwindow *window, int button, int state, int mod);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void initParticleBuffers();
void init(int width, int height, std::string strTitle, bool bFullScreen);
void destroy();
bool processInput(bool continueApplication = true);
void prepareScene();
void prepareDepthScene();
void renderScene(bool renderParticles = true);

void initParticleBuffers() {
	// Generate the buffers
	glGenBuffers(1, &initVel);   // Initial velocity buffer
	glGenBuffers(1, &startTime); // Start time buffer

	// Allocate space for all buffers
	int size = nParticles * 3 * sizeof(float);
	glBindBuffer(GL_ARRAY_BUFFER, initVel);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, startTime);
	glBufferData(GL_ARRAY_BUFFER, nParticles * sizeof(float), NULL, GL_STATIC_DRAW);

	// Fill the first velocity buffer with random velocities
	glm::vec3 v(0.0f);
	float velocity, theta, phi;
	GLfloat *data = new GLfloat[nParticles * 3];
	for (unsigned int i = 0; i < nParticles; i++) {

		theta = glm::mix(0.0f, glm::pi<float>() / 6.0f, ((float)rand() / RAND_MAX));
		phi = glm::mix(0.0f, glm::two_pi<float>(), ((float)rand() / RAND_MAX));

		v.x = sinf(theta) * cosf(phi);
		v.y = cosf(theta);
		v.z = sinf(theta) * sinf(phi);

		velocity = glm::mix(0.6f, 0.8f, ((float)rand() / RAND_MAX));
		v = glm::normalize(v) * velocity;

		data[3 * i] = v.x;
		data[3 * i + 1] = v.y;
		data[3 * i + 2] = v.z;
	}
	glBindBuffer(GL_ARRAY_BUFFER, initVel);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);

	// Fill the start time buffer
	delete[] data;
	data = new GLfloat[nParticles];
	float time = 0.0f;
	float rate = 0.00075f;
	for (unsigned int i = 0; i < nParticles; i++) {
		data[i] = time;
		time += rate;
	}
	glBindBuffer(GL_ARRAY_BUFFER, startTime);
	glBufferSubData(GL_ARRAY_BUFFER, 0, nParticles * sizeof(float), data);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	delete[] data;

	glGenVertexArrays(1, &VAOParticles);
	glBindVertexArray(VAOParticles);
	glBindBuffer(GL_ARRAY_BUFFER, initVel);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, startTime);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void initParticleBuffersFire() {
	// Generate the buffers
	glGenBuffers(2, posBuf);    // position buffers
	glGenBuffers(2, velBuf);    // velocity buffers
	glGenBuffers(2, age);       // age buffers

	// Allocate space for all buffers
	int size = nParticlesFire * sizeof(GLfloat);
	glBindBuffer(GL_ARRAY_BUFFER, posBuf[0]);
	glBufferData(GL_ARRAY_BUFFER, 3 * size, 0, GL_DYNAMIC_COPY);
	glBindBuffer(GL_ARRAY_BUFFER, posBuf[1]);
	glBufferData(GL_ARRAY_BUFFER, 3 * size, 0, GL_DYNAMIC_COPY);
	glBindBuffer(GL_ARRAY_BUFFER, velBuf[0]);
	glBufferData(GL_ARRAY_BUFFER, 3 * size, 0, GL_DYNAMIC_COPY);
	glBindBuffer(GL_ARRAY_BUFFER, velBuf[1]);
	glBufferData(GL_ARRAY_BUFFER, 3 * size, 0, GL_DYNAMIC_COPY);
	glBindBuffer(GL_ARRAY_BUFFER, age[0]);
	glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_COPY);
	glBindBuffer(GL_ARRAY_BUFFER, age[1]);
	glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_COPY);

	// Fill the first age buffer
	std::vector<GLfloat> initialAge(nParticlesFire);
	float rate = particleLifetime / nParticlesFire;
	for (unsigned int i = 0; i < nParticlesFire; i++) {
		int index = i - nParticlesFire;
		float result = rate * index;
		initialAge[i] = result;
	}
	// Shuffle them for better looking results
	//Random::shuffle(initialAge);
	auto rng = std::default_random_engine{};
	std::shuffle(initialAge.begin(), initialAge.end(), rng);
	glBindBuffer(GL_ARRAY_BUFFER, age[0]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, initialAge.data());

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Create vertex arrays for each set of buffers
	glGenVertexArrays(2, particleArray);

	// Set up particle array 0
	glBindVertexArray(particleArray[0]);
	glBindBuffer(GL_ARRAY_BUFFER, posBuf[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, velBuf[0]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, age[0]);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	// Set up particle array 1
	glBindVertexArray(particleArray[1]);
	glBindBuffer(GL_ARRAY_BUFFER, posBuf[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, velBuf[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, age[1]);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	// Setup the feedback objects
	glGenTransformFeedbacks(2, feedback);

	// Transform feedback 0
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, feedback[0]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, posBuf[0]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 1, velBuf[0]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 2, age[0]);

	// Transform feedback 1
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, feedback[1]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, posBuf[1]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 1, velBuf[1]);
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 2, age[1]);

	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
}

// Implementacion de todas las funciones.
void init(int width, int height, std::string strTitle, bool bFullScreen) {

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(-1);
	}

	screenWidth = width;
	screenHeight = height;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (bFullScreen)
		window = glfwCreateWindow(width, height, strTitle.c_str(),
			glfwGetPrimaryMonitor(), nullptr);
	else
		window = glfwCreateWindow(width, height, strTitle.c_str(), nullptr,
			nullptr);

	if (window == nullptr) {
		std::cerr
			<< "Error to create GLFW window, you can try download the last version of your video card that support OpenGL 3.3+"
			<< std::endl;
		destroy();
		exit(-1);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);

	glfwSetWindowSizeCallback(window, reshapeCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetScrollCallback(window, scrollCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Init glew
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cerr << "Failed to initialize glew" << std::endl;
		exit(-1);
	}

	glViewport(0, 0, screenWidth, screenHeight);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// Inicialización de los shaders
	shader.initialize("../Shaders/colorShader.vs", "../Shaders/colorShader.fs");
	shaderSkybox.initialize("../Shaders/skyBox.vs", "../Shaders/skyBox_fog.fs");
	shaderMulLighting.initialize("../Shaders/iluminacion_textura_animation_shadow.vs", "../Shaders/multipleLights_shadow.fs");
	shaderTerrain.initialize("../Shaders/terrain_shadow.vs", "../Shaders/terrain_shadow.fs");
	shaderParticlesFountain.initialize("../Shaders/particlesFountain.vs", "../Shaders/particlesFountain.fs");
	//shaderParticlesFire.initialize("../Shaders/particlesFire.vs", "../Shaders/particlesFire.fs", { "Position", "Velocity", "Age" });
	shaderParticlesFire.initialize("../Shaders/particlesSmoke.vs", "../Shaders/particlesSmoke.fs", { "Position", "Velocity", "Age" });
	shaderViewDepth.initialize("../Shaders/texturizado.vs", "../Shaders/texturizado_depth_view.fs");
	shaderDepth.initialize("../Shaders/shadow_mapping_depth.vs", "../Shaders/shadow_mapping_depth.fs");

	// Inicializacion de los objetos.
	skyboxSphere.init();
	skyboxSphere.setShader(&shaderSkybox);
	skyboxSphere.setScale(glm::vec3(100.0f, 100.0f, 100.0f));

	boxCollider.init();
	boxCollider.setShader(&shader);
	boxCollider.setColor(glm::vec4(1.0, 1.0, 1.0, 1.0));

	sphereCollider.init();
	sphereCollider.setShader(&shader);
	sphereCollider.setColor(glm::vec4(1.0, 1.0, 1.0, 1.0));

	boxViewDepth.init();
	boxViewDepth.setShader(&shaderViewDepth);

	boxLightViewBox.init();
	boxLightViewBox.setShader(&shaderViewDepth);

	terrain.init();
	terrain.setShader(&shaderTerrain);
	terrain.setPosition(glm::vec3(100, 0, 100));

	models = new ModelManager();	

	meta->loadModel("../models/meta/meta.obj");
	meta->setShader(&shaderMulLighting);
	meta
		->Init(glm::mat4(1.0f))
		//->Rotate(-3.6, 0.f, 1.f, 0.f)
		->Translate(-8.6f, 1.5f, 20.0f)
		->Scale(0.11f, 0.11f, 0.11f);
	meta->mcEnable(DEPTH);
	models->addModel(meta);

	puente->loadModel("../models/puente1/puente1.obj");
	puente->setShader(&shaderMulLighting);
	puente
		->Init(glm::mat4(1.0f))
		//->Rotate(-3.6, 0.f, 1.f, 0.f)
		->Translate(-8.2f, 2.f, -38.0f)
		->Scale(5.9f, 6.0f, 5.0f);
	puente->mcEnable(DEPTH);
	models->addModel(puente);

	banca->loadModel("../models/banca/banca.obj");
	banca->setShader(&shaderMulLighting);
	banca
		->Init(glm::mat4(1.0f))
		//->Rotate(-3.6, 0.f, 1.f, 0.f)
		->Translate(-10.0f, 2.0f, -28.0f)
		->Scale(1.0f, 1.0f, 1.0f);
	banca->matrix[3][1] = terrain.getHeightTerrain(banca->matrix[3][0], banca->matrix[3][2]);
	banca->mcEnable(DEPTH);
	models->addModel(banca);

	roca->Load(&shaderMulLighting);
	roca->InitMatrices(&terrain);
	models->addModel(roca);
	

	laberinto->loadModel("../models/laberinto/laberinto.obj");
	laberinto->setShader(&shaderMulLighting);
	laberinto
		->Init(glm::mat4(1.0f))
		->Translate(60.0f, 1.8f, 85.0f)
		->Scale(5.0f, 5.0f, 6.0f)
		->Rotate(-90.0f, 0.f, 1.f, 0.f);
	laberinto->mcEnable(DEPTH);
	models->addModel(laberinto);

	torre->loadModel("../models/torre/torre.obj");
	torre->setShader(&shaderMulLighting);
	torre
		->Init(glm::mat4(1.0f))
		->Translate(-70.0f, -0.3f, -35.0f)
		->Scale(40.0f, 40.0f, 40.0f);
		//->Rotate(-90.0f, 0.f, 1.f, 0.f);
	torre->mcEnable(DEPTH);
	models->addModel(torre);

	casa4->loadModel("../models/CasaMinecraft5/CasaMinecraft5.obj");
	casa4->setShader(&shaderMulLighting);
	casa4
		->Init(glm::mat4(1.0f))
		->Translate(-45.0f, 0.0f, -28.0f)
		->Scale(30.0f, 30.0f, 30.0f)
	    ->Rotate(90.0f, 0.f, 1.f, 0.f);
	casa4->mcEnable(DEPTH);
	models->addModel(casa4);

	casa5->loadModel("../models/CasaMinecraft6/CasaMinecraft6.obj");
	casa5->setShader(&shaderMulLighting);
	casa5
		->Init(glm::mat4(1.0f))
		->Translate(-50.0f, -2.0f, -60.0f)
		->Scale(20.0f, 20.0f, 20.0f)
	    ->Rotate(-90.0f, 0.f, 1.f, 0.f);
	casa5->mcEnable(DEPTH);
	models->addModel(casa5);

	casa6->loadModel("../models/CasaMinecraft7/CasaMinecraft7.obj");
	casa6->setShader(&shaderMulLighting);
	casa6
		->Init(glm::mat4(1.0f))
		->Translate(-80.0f, 0.0f, -60.0f)
		->Scale(15.0f, 15.0f, 15.0f)
		->Rotate(-90.0f, 0.f, 1.f, 0.f);
	casa6->mcEnable(DEPTH);
	models->addModel(casa6);

	//MarioCraftModel* castillo = new MarioCraftModel("../models/Castillo/castillo.obj", &shaderMulLighting);
	castillo->loadModel("../models/Castillo/castillo.obj");
	castillo->setShader(&shaderMulLighting);
	castillo
		->Init(glm::mat4(1.0f))
		->Rotate(-3.6, 0.f, 1.f, 0.f)
		->Translate(-8.0f, 0.0f, -111.0f)
		->Scale(26.5f, 26.5f, 26.5f);
	castillo->matrix[3][1] = terrain.getHeightTerrain(castillo->matrix[3][0], castillo->matrix[3][2]) + 19.f;
	castillo->mcEnable(DEPTH);
	models->addModel(castillo);

	fortaleza->loadModel("../models/CasaMinecraft4/fortaleza.obj");
	fortaleza->setShader(&shaderMulLighting);
	fortaleza
		->Init(glm::mat4(1.0f))
		->Translate(-29.0, 0.0f, 33.0f)
		->Scale(2.f, 2.f, 2.f);
	fortaleza->matrix[3][1] = terrain.getHeightTerrain(fortaleza->matrix[3][0], fortaleza->matrix[3][2]) - 1.f;
	fortaleza->mcEnable(DEPTH);
	models->addModel(fortaleza);

	casa1->loadModel("../models/CasaMinecraft3/casa.obj");
	casa1->setShader(&shaderMulLighting);
	casa1
		->Init(glm::mat4(1.0f))
		->Translate(-90.f, 0.f, 50.f)
		->Scale(1.8f, 1.8f, 1.8f);
	casa1->matrix[3][1] = terrain.getHeightTerrain(casa1->matrix[3][0], casa1->matrix[3][2]) - 5;
	casa1->mcEnable(DEPTH);
	models->addModel(casa1);

	casa2->loadModel("../models/CasaMinecraft1/casa.obj");
	casa2->setShader(&shaderMulLighting);
	casa2
		->Init(glm::mat4(1.0f))
		->Translate(-90.f, 0.f, 15.f)
		->Scale(0.5f, 0.5f, 0.5f);
	casa2->matrix[3][1] = terrain.getHeightTerrain(casa2->matrix[3][0], casa2->matrix[3][2]) + 5.9f;
	casa2->mcEnable(DEPTH);
	models->addModel(casa2);

	casa3->loadModel("../models/CasaMinecraft2/casa2.obj");
	casa3->setShader(&shaderMulLighting);
	casa3
		->Init(glm::mat4(1.0f))
		->Translate(-90.f, 0.f, -10.f)
		->Scale(10.0f, 10.0f, 10.0f);
	casa3->matrix[3][1] = terrain.getHeightTerrain(casa3->matrix[3][0], casa3->matrix[3][2]) - 2.1;
	casa3->mcEnable(DEPTH);
	models->addModel(casa3);

	
	speedCola->loadModel("../models/speedCola/speedCola.obj");
	speedCola->setShader(&shaderMulLighting);
	speedCola
		->Init(glm::mat4(1.0f))
		->Translate(-90.f, 0.f, -99.f)
		->Scale(0.05f, 0.05f, 0.05f);
	speedCola->matrix[3][1] = terrain.getHeightTerrain(speedCola->matrix[3][0], speedCola->matrix[3][2]);
	speedCola->mcEnable(DEPTH);
	models->addModel(speedCola);

	doubleTap->loadModel("../models/doubleTap/doubleTap.obj");
	doubleTap->setShader(&shaderMulLighting);
	doubleTap
		->Init(glm::mat4(1.0f))
		->Translate(21.f, 0.f, -98.8f)
		->Scale(0.05f, 0.05f, 0.05f);
	doubleTap->matrix[3][1] = terrain.getHeightTerrain(doubleTap->matrix[3][0], doubleTap->matrix[3][2]);
	doubleTap->mcEnable(DEPTH);
	models->addModel(doubleTap);

	juggerNog->loadModel("../models/juggerNog/juggerNog.obj");
	juggerNog->setShader(&shaderMulLighting);
	juggerNog
		->Init(glm::mat4(1.0f))
		->Translate(60.5f, 0.f, 88.f)
		->Scale(0.05f, 0.05f, 0.05f);
	juggerNog->matrix[3][1] = terrain.getHeightTerrain(juggerNog->matrix[3][0], juggerNog->matrix[3][2]);
	juggerNog->mcEnable(DEPTH);
	models->addModel(juggerNog);

	quickRevive->loadModel("../models/quickRevive/quickRevive.obj");
	quickRevive->setShader(&shaderMulLighting);
	quickRevive
		->Init(glm::mat4(1.0f))
		->Translate(-23.f, 0.f, 42.f)
		->Scale(0.05f, 0.05f, 0.05f);
	quickRevive->matrix[3][1] = terrain.getHeightTerrain(quickRevive->matrix[3][0], quickRevive->matrix[3][2]);
	quickRevive->mcEnable(DEPTH);
	models->addModel(quickRevive);

	vector<CasaToad> casitas = {
		CasasToad::newCasa(AZUL,  8.f, - 5.f, -90.f), 
		CasasToad::newCasa(ROJA,  8.f, -20.f, -90.f),
		CasasToad::newCasa(AZUL,  8.f, -35.f, -90.f), 
		CasasToad::newCasa(ROJA, 27.f, - 5.f, -90.f),
		CasasToad::newCasa(AZUL, 27.f, -20.f, -90.f), 
		CasasToad::newCasa(ROJA, 27.f, -35.f, -90.f),

		CasasToad::newCasa(AZUL, 65.f,   0.f, 0.f), 
		CasasToad::newCasa(ROJA, 65.f, -15.f, 0.f),
		CasasToad::newCasa(AZUL, 65.f, -30.f, 0.f), 
		CasasToad::newCasa(ROJA, 65.f, -45.f, 0.f),
		CasasToad::newCasa(AZUL, 65.f, -60.f, 0.f), 
		CasasToad::newCasa(ROJA, 85.f,   0.f, 0.f),
		CasasToad::newCasa(AZUL, 85.f, -15.f, 0.f), 
		CasasToad::newCasa(ROJA, 85.f, -30.f, 0.f),
		CasasToad::newCasa(AZUL, 85.f, -45.f, 0.f), 
		CasasToad::newCasa(ROJA, 85.f, -60.f, 0.f),

		CasasToad::newCasa(AZUL, -25.f,  -5.f, 90.f),
		CasasToad::newCasa(ROJA, -25.f, -20.f, 90.f),
		CasasToad::newCasa(AZUL, -25.f, -35.f, 90.f),
		CasasToad::newCasa(ROJA, -25.f, -50.f, 90.f),
	};
	casita->Load(casitas, &shaderMulLighting);
	casita->InitMatrices(&terrain);
	models->addModel(casita);

	vector<Bosque> arbolitos = {
		Arbol::newArbol(5, 12,  25.f, -72.f),
		Arbol::newArbol(5, 12, -30.5f, -72.f),
		Arbol::newArbol(6, 13, -23.f,  65.f),
	};
	arbol->Load(&shaderMulLighting);
	arbol->InitMatrices(arbolitos, &terrain);
	models->addModel(arbol);

	// ---------------------------------------------------------------------------
	// Antorchas
	vector<float> moneditas = {
		// Puente
		-10.f,  3.f,  -40.f,

		// Bosque de atrás
		-25.f,  1.0f,  65.f,
		-32.f,  0.3f,  74.f,
		-42.f,  1.0f,  78.f,
		-33.f,  0.2f,  87.f,
		-23.f,  0.7f,  92.f,
		-50.f,  0.5f,  85.f,
		-65.f,  1.0f,  77.f,
		-86.f,  0.3f,  72.f,
		-93.f,  0.9f,  66.f,
		-93.f,  0.6f,  66.f,
		-91.f,  0.4f,  78.f,
		-89.f,  1.0f,  88.f,
		-74.f,  0.8f,  86.f,
		-74.f,  0.7f,  86.f,
		-52.f,  1.0f,  80.f,

		// Laberinto
		60.f, 0.5f, 40.f,
		60.f, 0.5f, 47.f,
		75.f, 0.5f, 47.f,
		90.f, 0.5f, 47.f,
		90.f, 0.5f, 64.f,
		90.f, 0.5f, 64.f,
		90.f, 0.5f, 80.f,
		87.f, 0.5f, 73.f,
		87.f, 0.5f, 54.f,
		73.f, 0.5f, 67.f,
		77.f, 0.5f, 95.f,
		77.f, 0.5f, 63.f,
		70.f, 0.5f, 60.f,
		80.f, 0.5f, 83.f,
		83.f, 0.5f, 56.f,
		83.f, 0.5f, 75.f,
		96.f, 0.5f, 96.f,
		96.f, 0.5f, 69.f,
		97.f, 0.5f, 40.f,
		63.f, 0.5f, 42.f,
		93.f, 0.5f, 43.f,
		93.f, 0.5f, 69.f,
		93.f, 0.5f, 82.f,
		83.f, 0.5f, 87.f,
		43.f, 0.5f, 84.f,
		33.f, 0.5f, 96.f,
		24.f, 0.5f, 96.f,
		30.f, 0.5f, 84.f,
		34.f, 0.5f, 84.f,
		24.f, 0.5f, 64.f,
		24.f, 0.5f, 40.f,
		73.f, 0.5f, 72.f,
		67.f, 0.5f, 83.f,
		63.f, 0.5f, 75.f,
		53.f, 0.5f, 91.f,
		53.f, 0.5f, 84.f,
		53.f, 0.5f, 75.f,
		53.f, 0.5f, 67.f,
		48.f, 0.5f, 90.f,
		56.f, 0.5f, 59.f,
		40.f, 0.5f, 59.f,
		35.f, 0.5f, 79.f,
		30.f, 0.5f, 47.f,
		53.f, 0.5f, 47.f,
		53.f, 0.5f, 43.f,
		27.f, 0.5f, 43.f,
		27.f, 0.5f, 64.f,
		27.f, 0.5f, 83.f,
		33.f, 0.5f, 83.f,
		37.f, 0.5f, 56.f,
		60.f, 0.5f, 62.f,
		60.f, 0.5f, 75.f,

		07.f, 0.5f, -13.f,
		27.f, 0.5f, -13.f,
		35.f, 0.5f, -20.f,
		35.f, 0.5f, -35.f,
		18.f, 0.5f, -43.f,
		07.f, 0.5f, -28.f,
		26.f, 0.5f, -28.f,
	   -33.f, 0.5f, -27.f,
	   -33.f, 0.5f,   2.f,
	   -17.f, 0.5f,   2.f,
	   -17.f, 0.5f, -19.f,
	   -17.f, 0.5f, -49.f,

		// Castillo
	   -24.f, 0.5f, -97.f,
	   -24.f, 0.5f, -87.f,
	   -24.f, 0.5f, -71.f,
	   -10.f, 0.5f, -71.f,
	    06.f, 0.5f, -71.f,
	    18.f, 0.5f, -84.f,
	    18.f, 0.5f, -97.f,
	    31.f, 0.5f, -77.f,
	    24.f, 0.5f, -75.f,
	    25.f, 0.5f, -82.f,
	    40.f, 0.5f, -90.f,
	    52.f, 0.5f, -84.f,
	    53.f, 0.5f, -71.f,
	    69.f, 0.5f, -77.f,
	    82.f, 0.5f, -87.f,
	    91.f, 0.5f, -96.f,
	    93.f, 0.5f, -83.f,
	    85.f, 0.5f, -75.f,
	    42.f, 0.5f, -78.f,
	    64.f, 0.5f, -84.f,
	    67.f, 0.5f, -96.f,
		30.f, 0.5f, -96.f,

		// Bosque Izquierdo
	    -33.f, 0.5f, -75.f,
	    -33.f, 0.5f, -75.f,
	    -33.f, 0.5f, -87.f,
	    -33.f, 0.5f, -96.f,
	    -39.f, 0.5f, -84.f,
	    -37.f, 0.5f, -78.f,
	    -44.f, 0.5f, -75.f,
	    -48.f, 0.5f, -84.f,
	    -48.f, 0.5f, -90.f,
	    -54.f, 0.5f, -93.f,
	    -54.f, 0.5f, -81.f,
	    -58.f, 0.5f, -90.f,
	    -60.f, 0.5f, -78.f,
	    -75.f, 0.5f, -77.f,
	    -78.f, 0.5f, -93.f,
	    -96.f, 0.5f, -84.f,
	    -90.f, 0.5f, -75.f,
	    -95.f, 0.5f, -71.f,
	    -96.f, 0.5f, -96.f,
	    -78.f, 0.5f, -81.f,

		// Colonia 2
		74.f, 0.5f, -52.f,
		74.f, 0.5f, -38.f,
		74.f, 0.5f, -22.f,
		74.f, 0.5f,  09.f,
		93.f, 0.5f,  09.f,
		93.f, 0.5f, -07.f,
		93.f, 0.5f, -22.f,
		93.f, 0.5f, -37.f,
		93.f, 0.5f, -51.f,
		93.f, 0.5f, -66.f,
		55.f, 0.5f, -44.f,
		55.f, 0.5f, -14.f,

		71.f, 0.5f, 13.f,
		71.f, 0.5f, 20.f,
		71.f, 0.5f, 27.f,

	   -76.f, 0.5f, 49.f,
	   -85.f, 0.5f, 40.f,
	   -77.f, 0.5f, 34.f,
	   -87.f, 0.5f, 22.f,

		





	};
	moneda->Load(&shaderMulLighting);
	moneda->InitMatrices(moneditas, &terrain);
	models->addModel(moneda);


	// ---------------------------------------------------------------------------
	// Antorchas
	vector<float> antorchitas = {
		-70.f, 22.f,
		-70.f, 41.f,

		-25.f, 25.f,
	};
	antorcha->Load(&shaderMulLighting);
	antorcha->InitMatrices(antorchitas, &terrain);
	models->addModel(antorcha);

	// ---------------------------------------------------------------------------
	// Lamparas
	vector<float> lamparitas = {
		/*
		-14.0f, -0.0f,
		-14.0f, -22.5f,
		//-14.0f, -30.0f,
		-14.0f, -45.0f,

		/*
		-0.7f, -0.0f,
		-0.7f, -25.5f,
		//-0.7f, -30.0f,
		-0.7f, -45.0f,
		*/
		/*
		17.f, -0.0f,
		//17.f, -15.0f,
		17.f, -22.5f,
		17.f, -45.0f,
		/*
		59.5f,   7.5f,
		59.5f, - 8.5f,
		59.5f, -23.5f,
		59.5f, -38.5f,
		59.5f, -53.5f,
		*/ 
		/*
		76.f,   7.5f,
		76.f, -12.5f,
		76.f, -32.5f,
		76.f, -52.5f,

		*/
	};
	lampara->Load(&shaderMulLighting);
	lampara->InitMatrices(lamparitas, &terrain);
	models->addModel(lampara);

	//Spider
	spiderModelAnimate.loadModel("../models/Spidi/Spidi.fbx");
	spiderModelAnimate.setShader(&shaderMulLighting);

	// Definimos el tamanio de la imagen
	int imageWidth, imageHeight;
	FIBITMAP *bitmap;
	unsigned char *data;

	// Carga de texturas para el skybox
	Texture skyboxTexture = Texture("");
	glGenTextures(1, &skyboxTextureID);
	// Tipo de textura CUBE MAP
	glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureID);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	for (int i = 0; i < ARRAY_SIZE_IN_ELEMENTS(types); i++) {
		skyboxTexture = Texture(fileNames[i]);
		FIBITMAP *bitmap = skyboxTexture.loadImage(true);
		unsigned char *data = skyboxTexture.convertToData(bitmap, imageWidth,
			imageHeight);
		if (data) {
			glTexImage2D(types[i], 0, GL_RGBA, imageWidth, imageHeight, 0,
				GL_BGRA, GL_UNSIGNED_BYTE, data);
		}
		else
			std::cout << "Failed to load texture" << std::endl;
		skyboxTexture.freeImage(bitmap);
	}

	Texture nightSkyboxTexture = Texture("");
	glGenTextures(1, &nightSkyboxTextureID);
	// Tipo de textura CUBE MAP
	glBindTexture(GL_TEXTURE_CUBE_MAP, nightSkyboxTextureID);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	for (int i = 0; i < ARRAY_SIZE_IN_ELEMENTS(types); i++) {
		nightSkyboxTexture = Texture(nightFileNames[i]);
		FIBITMAP* bitmap = nightSkyboxTexture.loadImage(true);
		unsigned char* data = nightSkyboxTexture.convertToData(bitmap, imageWidth,
			imageHeight);
		if (data) {
			glTexImage2D(types[i], 0, GL_RGBA, imageWidth, imageHeight, 0,
				GL_BGRA, GL_UNSIGNED_BYTE, data);
		}
		else
			std::cout << "Failed to load texture" << std::endl;
		nightSkyboxTexture.freeImage(bitmap);
	}

	textureTerrainBackground = new MarioCraftTexture("../Textures/pasto.jpg");
	textureTerrainR = new MarioCraftTexture("../Textures/carretera.jpeg");
	textureTerrainG = new MarioCraftTexture("../Textures/camino.jpeg");
	textureTerrainB = new MarioCraftTexture("../Textures/tierra.jpeg");
	textureTerrainBlendMap = new MarioCraftTexture("../Textures/blendMap.jpeg", true);

	textureParticleFire = new MarioCraftTexture("../Textures/smoke.png");

	std::uniform_real_distribution<float> distr01 = std::uniform_real_distribution<float>(0.0f, 1.0f);
	std::mt19937 generator;
	std::random_device rd;
	generator.seed(rd());
	int size = nParticlesFire * 2;
	std::vector<GLfloat> randData(size);
	for (int i = 0; i < randData.size(); i++) {
		randData[i] = distr01(generator);
	}

	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_1D, texId);
	glTexStorage1D(GL_TEXTURE_1D, 1, GL_R32F, size);
	glTexSubImage1D(GL_TEXTURE_1D, 0, 0, size, GL_RED, GL_FLOAT, randData.data());
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	shaderParticlesFire.setInt("Pass", 1);
	shaderParticlesFire.setInt("ParticleTex", 0);
	shaderParticlesFire.setInt("RandomTex", 1);
	shaderParticlesFire.setFloat("ParticleLifetime", particleLifetime);
	shaderParticlesFire.setFloat("ParticleSize", particleSize);
	shaderParticlesFire.setVectorFloat3("Accel", glm::value_ptr(glm::vec3(0.0f, 0.1f, 0.0f)));
	shaderParticlesFire.setVectorFloat3("Emitter", glm::value_ptr(glm::vec3(0.0f)));

	glm::mat3 basis;
	glm::vec3 u, v, n;
	v = glm::vec3(0, 1, 0);
	n = glm::cross(glm::vec3(1, 0, 0), v);
	if (glm::length(n) < 0.00001f) {
		n = glm::cross(glm::vec3(0, 1, 0), v);
	}
	u = glm::cross(v, n);
	basis[0] = glm::normalize(u);
	basis[1] = glm::normalize(v);
	basis[2] = glm::normalize(n);
	shaderParticlesFire.setMatrix3("EmitterBasis", 1, false, glm::value_ptr(basis));

	/*******************************************
	 * Inicializacion de los buffers de la fuente
	 *******************************************/
	initParticleBuffers();

	/*******************************************
	 * Inicializacion de los buffers del fuego
	 *******************************************/
	initParticleBuffersFire();

	/*******************************************
	 * Inicializacion del framebuffer para
	 * almacenar el buffer de profunidadad
	 *******************************************/
	glGenFramebuffers(1, &depthMapFBO);
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	/*******************************************
	 * OpenAL init
	 *******************************************/
	alutInit(0, nullptr);
	alListenerfv(AL_POSITION, listenerPos);
	alListenerfv(AL_VELOCITY, listenerVel);
	alListenerfv(AL_ORIENTATION, listenerOri);
	alGetError(); // clear any error messages
	if (alGetError() != AL_NO_ERROR) {
		printf("- Error creating buffers !!\n");
		exit(1);
	}
	else {
		printf("init() - No errors yet.");
	}
	// Config source 0
	// Generate buffers, or else no sound will happen!
	alGenBuffers(NUM_BUFFERS, buffer);
	buffer[0] = alutCreateBufferFromFile("../sounds/doubleTap.wav");
	buffer[1] = alutCreateBufferFromFile("../sounds/juggerNog.wav");
	buffer[2] = alutCreateBufferFromFile("../sounds/quickRevive.wav");
	buffer[3] = alutCreateBufferFromFile("../sounds/speedCola.wav");
	buffer[4] = alutCreateBufferFromFile("../sounds/moneda.wav");
	int errorAlut = alutGetError();
	if (errorAlut != ALUT_ERROR_NO_ERROR) {
		printf("- Error open files with alut %d !!\n", errorAlut);
		exit(2);
	}


	alGetError(); /* clear error */
	alGenSources(NUM_SOURCES, source);

	if (alGetError() != AL_NO_ERROR) {
		printf("- Error creating sources !!\n");
		exit(2);
	}
	else {
		printf("init - no errors after alGenSources\n");
	}
	alSourcef(source[0], AL_PITCH, 1.0f);
	alSourcef(source[0], AL_GAIN, 0.02f);
	alSourcefv(source[0], AL_POSITION, source0Pos);
	alSourcefv(source[0], AL_VELOCITY, source0Vel);
	alSourcei(source[0], AL_BUFFER, buffer[0]);
	alSourcei(source[0], AL_LOOPING, AL_TRUE);
	alSourcef(source[0], AL_MAX_DISTANCE, 50);

	alSourcef(source[1], AL_PITCH, 1.0f);
	alSourcef(source[1], AL_GAIN, 0.02f);
	alSourcefv(source[1], AL_POSITION, source1Pos);
	alSourcefv(source[1], AL_VELOCITY, source1Vel);
	alSourcei(source[1], AL_BUFFER, buffer[1]);
	alSourcei(source[1], AL_LOOPING, AL_TRUE);
	alSourcef(source[1], AL_MAX_DISTANCE, 50);

	alSourcef(source[2], AL_PITCH, 1.0f);
	alSourcef(source[2], AL_GAIN, 0.02f);
	alSourcefv(source[2], AL_POSITION, source2Pos);
	alSourcefv(source[2], AL_VELOCITY, source2Vel);
	alSourcei(source[2], AL_BUFFER, buffer[2]);
	alSourcei(source[2], AL_LOOPING, AL_TRUE);
	alSourcef(source[2], AL_MAX_DISTANCE, 50);

	alSourcef(source[3], AL_PITCH, 1.0f);
	alSourcef(source[3], AL_GAIN, 0.02f);
	alSourcefv(source[3], AL_POSITION, source3Pos);
	alSourcefv(source[3], AL_VELOCITY, source3Vel);
	alSourcei(source[3], AL_BUFFER, buffer[3]);
	alSourcei(source[3], AL_LOOPING, AL_TRUE);
	alSourcef(source[3], AL_MAX_DISTANCE, 50);

	alSourcef(source[4], AL_PITCH, 1.0f);
	alSourcef(source[4], AL_GAIN, 1.0f);
	alSourcefv(source[4], AL_POSITION, source4Pos);
	alSourcefv(source[4], AL_VELOCITY, source4Vel);
	alSourcei(source[4], AL_BUFFER, buffer[4]);
	alSourcei(source[4], AL_LOOPING, AL_FALSE);
	alSourcef(source[4], AL_MAX_DISTANCE, 50);
}

void destroy() {
	glfwDestroyWindow(window);
	glfwTerminate();
	// --------- IMPORTANTE ----------
	// Eliminar los shader y buffers creados.

	// Shaders Delete
	shader.destroy();
	shaderMulLighting.destroy();
	shaderSkybox.destroy();
	shaderTerrain.destroy();
	shaderParticlesFountain.destroy();
	shaderParticlesFire.destroy();

	// Basic objects Delete
	skyboxSphere.destroy();
	boxCollider.destroy();
	sphereCollider.destroy();
	boxViewDepth.destroy();
	boxLightViewBox.destroy();

	// Terrains objects Delete
	terrain.destroy();

	// Custom objects Delete
	//models->destroy();

	// Custom objects animate
	spiderModelAnimate.destroy();

	// Textures Delete
	glBindTexture(GL_TEXTURE_2D, 0);
	textureTerrainBackground->~MarioCraftTexture();
	textureTerrainR->~MarioCraftTexture();
	textureTerrainG->~MarioCraftTexture();
	textureTerrainB->~MarioCraftTexture();
	textureTerrainBlendMap->~MarioCraftTexture();
	textureParticleFire->~MarioCraftTexture();

	// Cube Maps Delete
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glDeleteTextures(1, &skyboxTextureID);
	glDeleteTextures(1, &nightSkyboxTextureID);

	// Remove the buffer of the fountain particles
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &initVel);
	glDeleteBuffers(1, &startTime);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAOParticles);

	// Remove the buffer of the fire particles
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(2, posBuf);
	glDeleteBuffers(2, velBuf);
	glDeleteBuffers(2, age);
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
	glDeleteTransformFeedbacks(2, feedback);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAOParticlesFire);
}

void reshapeCallback(GLFWwindow *Window, int widthRes, int heightRes) {
	screenWidth = widthRes;
	screenHeight = heightRes == 0 ? 1 : heightRes;
	glViewport(0, 0, widthRes, heightRes);
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action,
	int mode) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			exitApp = true;
			break;
		}
	}
}

void mouseCallback(GLFWwindow *window, double xpos, double ypos) {
	offsetX = xpos - lastMousePosX;
	offsetY = ypos - lastMousePosY;
	lastMousePosX = xpos;
	lastMousePosY = ypos;
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	camera->scrollCamera(window, xoffset, yoffset);
}

void mouseButtonCallback(GLFWwindow *window, int button, int state, int mod) {
	if (state == GLFW_PRESS) {
		switch (button) {
		case GLFW_MOUSE_BUTTON_RIGHT:
			std::cout << "lastMousePos.y:" << lastMousePosY << std::endl;
			break;
		case GLFW_MOUSE_BUTTON_LEFT:
			std::cout << "lastMousePos.x:" << lastMousePosX << std::endl;
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
			std::cout << "lastMousePos.x:" << lastMousePosX << std::endl;
			std::cout << "lastMousePos.y:" << lastMousePosY << std::endl;
			break;
		}
	}
}

bool processInput(bool continueApplication) {
	if (exitApp || glfwWindowShouldClose(window) != 0) {
		return false;
	}
	//control de Xbox
	if (glfwJoystickPresent(GLFW_JOYSTICK_1) == GL_TRUE) {
		//std::cout << "Esta presente el mando" << std::endl;
		int axesCount, buttonCount;
		const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
		if (fabs(axes[0]) > 0.2) {
			modelMatrixSpider = glm::rotate(modelMatrixSpider, glm::radians(1.0f), glm::vec3(0, -axes[0] * 0.1, 0));
			animationIndex = 1;
		}

		if (fabs(axes[1]) > 0.2) {
			modelMatrixSpider = glm::translate(modelMatrixSpider, glm::vec3(0, 0, axes[1] * 0.1));
			animationIndex = 0;
		}

		const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
		if (!isJump && buttons[0] == GLFW_PRESS) {
			isJump = true;
			startTimeJump = currTime;
			tmv = 0;
		}
	}
	// Control de la camara
	camera->keyboardInput(window, deltaTime, offsetX, offsetY);
	offsetX = 0;
	offsetY = 0;

	// Seleccionar modelo
	if (enableCountSelected && glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS) {
		enableCountSelected = false;
		modelSelected++;
		if (modelSelected > 2)
			modelSelected = 0;
		std::cout << "modelSelected:" << modelSelected << std::endl;
	}
	else if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_RELEASE)
		enableCountSelected = true;

	if (modelSelected == 2 && glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		modelMatrixSpider = glm::rotate(modelMatrixSpider, glm::radians(1.0f), glm::vec3(0, 1, 0));
		animationIndex = 4;
	}
	else if (modelSelected == 2 && glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		modelMatrixSpider = glm::rotate(modelMatrixSpider, glm::radians(-1.0f), glm::vec3(0, 1, 0));
		animationIndex = 4;
	}if (modelSelected == 2 && glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		modelMatrixSpider = glm::translate(modelMatrixSpider, glm::vec3(0, 0, 0.2));
		animationIndex = 4;
	}
	else if (modelSelected == 2 && glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		modelMatrixSpider = glm::translate(modelMatrixSpider, glm::vec3(0, 0, -0.2));
		animationIndex = 4;
	}
	else if (modelSelected == 2 && glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		cout << endl;
		cout << glm::to_string(modelMatrixSpider[3]) << endl;
		cout << endl;
	}

	bool keySpaceStatus = glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS;
	if (!isJump && keySpaceStatus) {
		isJump = true;
		startTimeJump = currTime;
		tmv = 0;
		sourcesPlay[3] = true;
	}

	glfwPollEvents();
	return continueApplication;
}

void applicationLoop() {
	bool psi = true;
	glm::mat4 view;
	glm::vec3 axis;
	glm::vec3 target;
	float angleTarget;

	modelMatrixSpider = glm::translate(modelMatrixSpider, glm::vec3(13.0f, 0.05f, -5.0f));
	modelMatrixSpider = glm::rotate(modelMatrixSpider, glm::radians(-90.0f), glm::vec3(0, 1, 0));

	lastTime = TimeManager::Instance().GetTime();

	// Time for the particles animation
	currTimeParticlesAnimation = lastTime;
	lastTimeParticlesAnimation = lastTime;

	currTimeParticlesAnimationFire = lastTime;
	lastTimeParticlesAnimationFire = lastTime;

	glm::vec3 lightPos = glm::vec3(10.0, 10.0, 0.0);
	shadowBox = new ShadowBox(-lightPos, camera->get(), 15.0f, 0.1f, 45.f);

	while (psi) {
		currTime = TimeManager::Instance().GetTime();
		if (currTime - lastTime < 0.016666667) {
			glfwPollEvents();
			continue;
		}
		lastTime = currTime;
		TimeManager::Instance().CalculateFrameRate(true);
		deltaTime = TimeManager::Instance().DeltaTime;
		psi = processInput(true);

		std::map<std::string, bool> collisionDetection;

		glm::mat4 projection = glm::perspective(glm::radians(camera->getZoom()),
			(float)screenWidth / (float)screenHeight, 0.1f, 100.0f);

		if (modelSelected == 1) {
			
		}
		else {
			axis = glm::axis(glm::quat_cast(modelMatrixSpider));
			angleTarget = glm::angle(glm::quat_cast(modelMatrixSpider));
			target = modelMatrixSpider[3];
		}

		if (std::isnan(angleTarget))
			angleTarget = 0.0;
		if (axis.y < 0)
			angleTarget = -angleTarget;
		if (modelSelected == 1)
			angleTarget -= glm::radians(90.0f);
		camera->setCameraTarget(target);
		camera->setAngleTarget(angleTarget);
		camera->updateCamera();
		view = camera->getViewMatrix();

		rotation += rotate_speed * deltaTime;
		glm::mat4 viewRot = glm::rotate(view, glm::radians(rotation), glm::vec3(0.f, 1.f, 0.f));
		timeDay += deltaTime * 200;
		timeDay = (int)timeDay % 24000;
		GLuint texture1;
		GLuint texture2;
		float blendFactor;
		if (timeDay >= 0 && timeDay < 5000) {
			texture1 = nightSkyboxTextureID;
			texture2 = nightSkyboxTextureID;
			blendFactor = (timeDay - 0) / (5000 - 0);
		}
		else if (timeDay >= 5000 && timeDay < 8000) {
			texture1 = nightSkyboxTextureID;
			texture2 = skyboxTextureID;
			blendFactor = (timeDay - 5000) / (8000 - 5000);
		}
		else if (timeDay >= 8000 && timeDay < 21000) {
			texture1 = skyboxTextureID;
			texture2 = skyboxTextureID;
			blendFactor = (timeDay - 8000) / (21000 - 8000);
		}
		else {
			texture1 = skyboxTextureID;
			texture2 = nightSkyboxTextureID;
			blendFactor = (timeDay - 21000) / (24000 - 21000);
		}

		// Matriz de proyección del shadow mapping
		glm::mat4 lightProjection = glm::mat4(1.f), lightView = glm::mat4(1.f);
		shadowBox->update(screenWidth, screenHeight);
		glm::vec3 centerBox = shadowBox->getCenter();
		glm::mat4 lightSpaceMatrix;
		lightView = glm::lookAt(centerBox, centerBox + glm::normalize(-lightPos), glm::vec3(0.f, 1.f, 0.f));
		lightProjection[0][0] = 2.f / shadowBox->getWidth();
		lightProjection[1][1] = 2.f / shadowBox->getHeight();
		lightProjection[2][2] = -2.f / shadowBox->getLength();
		lightProjection[3][3] = 1.f;
		lightSpaceMatrix = lightProjection * lightView;
		shaderDepth.setMatrix4("lightSpaceMatrix", 1, false, glm::value_ptr(lightSpaceMatrix));

		// Settea la matriz de vista y projection al shader con solo color
		shader.setMatrix4("projection", 1, false, glm::value_ptr(projection));
		shader.setMatrix4("view", 1, false, glm::value_ptr(view));

		// Settea la matriz de vista y projection al shader con skybox
		shaderSkybox.setMatrix4("projection", 1, false,
			glm::value_ptr(projection));
		shaderSkybox.setMatrix4("view", 1, false,
			glm::value_ptr(glm::mat4(glm::mat3(viewRot))));
		// Settea la matriz de vista y projection al shader con multiples luces
		shaderMulLighting.setMatrix4("projection", 1, false,
			glm::value_ptr(projection));
		shaderMulLighting.setMatrix4("view", 1, false,
			glm::value_ptr(view));
		shaderMulLighting.setMatrix4("lightSpaceMatrix", 1, false,
			glm::value_ptr(lightSpaceMatrix));
		// Settea la matriz de vista y projection al shader con multiples luces
		shaderTerrain.setMatrix4("projection", 1, false,
			glm::value_ptr(projection));
		shaderTerrain.setMatrix4("view", 1, false,
			glm::value_ptr(view));
		shaderTerrain.setMatrix4("lightSpaceMatrix", 1, false,
			glm::value_ptr(lightSpaceMatrix));
		// Settea la matriz de vista y projection al shader para el fountain
		shaderParticlesFountain.setMatrix4("projection", 1, false,
			glm::value_ptr(projection));
		shaderParticlesFountain.setMatrix4("view", 1, false,
			glm::value_ptr(view));
		// Settea la matriz de vista y projection al shader para el fuego
		shaderParticlesFire.setInt("Pass", 2);
		shaderParticlesFire.setMatrix4("projection", 1, false, glm::value_ptr(projection));
		shaderParticlesFire.setMatrix4("view", 1, false, glm::value_ptr(view));

		/*******************************************
		 * Propiedades de neblina
		 *******************************************/
		shaderMulLighting.setVectorFloat3("fogColor", glm::value_ptr(glm::vec3(0.38, 0.68, 0.73)));
		shaderTerrain.setVectorFloat3("fogColor", glm::value_ptr(glm::vec3(0.38, 0.68, 0.73)));
		shaderSkybox.setVectorFloat3("fogColor", glm::value_ptr(glm::vec3(0.38, 0.68, 0.73)));

		if (timeDay > 7000 && timeDay < 19000) {
			light = glm::vec3(0.3 * glm::sin(glm::radians((timeDay - 7000.f) * 0.015)) + 0.05);
		}

		/*******************************************
		 * Propiedades Luz direccional
		 *******************************************/
		shaderMulLighting.setVectorFloat3("viewPos", glm::value_ptr(camera->getPosition()));
		shaderMulLighting.setVectorFloat3("directionalLight.light.ambient", glm::value_ptr(glm::vec3(light)));
		shaderMulLighting.setVectorFloat3("directionalLight.light.diffuse", glm::value_ptr(glm::vec3(0.3, 0.3, 0.3)));
		shaderMulLighting.setVectorFloat3("directionalLight.light.specular", glm::value_ptr(glm::vec3(0.4, 0.4, 0.4)));
		shaderMulLighting.setVectorFloat3("directionalLight.direction", glm::value_ptr(glm::vec3(-0.707106781, -0.707106781, 0.0)));

		/*******************************************
		 * Propiedades Luz direccional Terrain
		 *******************************************/
		shaderTerrain.setVectorFloat3("viewPos", glm::value_ptr(camera->getPosition()));
		shaderTerrain.setVectorFloat3("directionalLight.light.ambient", glm::value_ptr(glm::vec3(light)));
		shaderTerrain.setVectorFloat3("directionalLight.light.diffuse", glm::value_ptr(glm::vec3(0.3, 0.3, 0.3)));
		shaderTerrain.setVectorFloat3("directionalLight.light.specular", glm::value_ptr(glm::vec3(0.4, 0.4, 0.4)));
		shaderTerrain.setVectorFloat3("directionalLight.direction", glm::value_ptr(glm::vec3(-0.707106781, -0.707106781, 0.0)));

		/*******************************************
		 * Propiedades SpotLights
		 *******************************************/
		
		/*******************************************
		 * Propiedades PointLights
		 *******************************************/
		if (timeDay < 7000 || timeDay > 22000) {
			shaderMulLighting.setInt("pointLightCount", lampara->matrices.size() + antorcha->matrices.size());
			shaderTerrain.setInt("pointLightCount", lampara->matrices.size() + antorcha->matrices.size());
			for (int i = 0; i < lampara->matrices.size(); i++) {
				glm::mat4 matrixAdjustLamp = lampara->matrices[i];
				matrixAdjustLamp = glm::translate(matrixAdjustLamp, glm::vec3(0, 3, 0));
				glm::vec3 lampPosition = glm::vec3(matrixAdjustLamp[3]);
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.ambient", glm::value_ptr(glm::vec3(0.2, 0.16, 0.01)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.diffuse", glm::value_ptr(glm::vec3(0.4, 0.32, 0.02)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.specular", glm::value_ptr(glm::vec3(0.6, 0.5, 0.02)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i) + "].position", glm::value_ptr(lampPosition));
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i) + "].constant", 1.0);
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i) + "].linear", 0.09);
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.01);
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.ambient", glm::value_ptr(glm::vec3(0.2, 0.16, 0.01)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.diffuse", glm::value_ptr(glm::vec3(0.4, 0.32, 0.02)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i) + "].light.specular", glm::value_ptr(glm::vec3(0.6, 0.5, 0.02)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i) + "].position", glm::value_ptr(lampPosition));
				shaderTerrain.setFloat("pointLights[" + std::to_string(i) + "].constant", 1.0);
				shaderTerrain.setFloat("pointLights[" + std::to_string(i) + "].linear", 0.09);
				shaderTerrain.setFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.01);
			}
			for (int i = 0; i < antorcha->matrices.size(); i++) {
				glm::mat4 matrixAdjustLamp = antorcha->matrices[i];
				matrixAdjustLamp = glm::translate(matrixAdjustLamp, glm::vec3(0, 2, 0));
				glm::vec3 lampPosition = glm::vec3(matrixAdjustLamp[3]);
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.ambient", glm::value_ptr(glm::vec3(0.2, 0.16, 0.01)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.diffuse", glm::value_ptr(glm::vec3(0.4, 0.32, 0.02)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.specular", glm::value_ptr(glm::vec3(0.6, 0.5, 0.02)));
				shaderMulLighting.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].position", glm::value_ptr(lampPosition));
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].constant", 1.0);
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].linear", 0.09);
				shaderMulLighting.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].quadratic", 0.01);
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.ambient", glm::value_ptr(glm::vec3(0.2, 0.16, 0.01)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.diffuse", glm::value_ptr(glm::vec3(0.4, 0.32, 0.02)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].light.specular", glm::value_ptr(glm::vec3(0.6, 0.5, 0.02)));
				shaderTerrain.setVectorFloat3("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].position", glm::value_ptr(lampPosition));
				shaderTerrain.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].constant", 1.0);
				shaderTerrain.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].linear", 0.09);
				shaderTerrain.setFloat("pointLights[" + std::to_string(i + lampara->matrices.size()) + "].quadratic", 0.01);
			}
		}
		else {
			shaderMulLighting.setInt("pointLightCount", 0);
			shaderTerrain.setInt("pointLightCount", 0);
		}

		/*******************************************
		 * 1.- We render the depth buffer
		 *******************************************/
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// render scene from light's point of view
		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
		glClear(GL_DEPTH_BUFFER_BIT);
		//glCullFace(GL_FRONT);
		prepareDepthScene();
		renderScene(false);
		//glCullFace(GL_BACK);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		 /*******************************************
		  * 2.- We render the normal objects
		  *******************************************/
		glViewport(0, 0, screenWidth, screenHeight);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		prepareScene();
		glActiveTexture(GL_TEXTURE10);
		glBindTexture(GL_TEXTURE_2D, depthMap);
		shaderMulLighting.setInt("shadowMap", 10);
		shaderTerrain.setInt("shadowMap", 10);
		/*******************************************
		 * Skybox
		 *******************************************/
		GLint oldCullFaceMode;
		GLint oldDepthFuncMode;
		// deshabilita el modo del recorte de caras ocultas para ver las esfera desde adentro
		glGetIntegerv(GL_CULL_FACE_MODE, &oldCullFaceMode);
		glGetIntegerv(GL_DEPTH_FUNC, &oldDepthFuncMode);
		glActiveTexture(GL_TEXTURE11);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texture1);
		glActiveTexture(GL_TEXTURE12);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texture2);
		shaderSkybox.setInt("skybox", 11);
		shaderSkybox.setInt("skyboxNight", 12);
		shaderSkybox.setFloat("blendFactor", blendFactor);
		glCullFace(GL_FRONT);
		glDepthFunc(GL_LEQUAL);
		skyboxSphere.render();
		glCullFace(oldCullFaceMode);
		glDepthFunc(oldDepthFuncMode);
		renderScene();


		 /*******************************************
		  * Creacion de colliders
		  * IMPORTANT do this before interpolations
		  *******************************************/
		for (int i = 0; i < casita->matrices.size(); i++) {
			AbstractModel::SBB casaToadCollider;
			glm::mat4 modelMatrixCasitas = glm::mat4(casita->matrices[i]);
			modelMatrixCasitas = glm::scale(modelMatrixCasitas, glm::vec3(3.0, 3.0, 3.0));
			modelMatrixCasitas = glm::translate(modelMatrixCasitas, casita->casaRoja->getSbb().c);
			modelMatrixCasitas = glm::translate(modelMatrixCasitas, glm::vec3(0.f, -1.0f, 0.f));
			casaToadCollider.c = glm::vec3(modelMatrixCasitas[3]);
			casaToadCollider.ratio = casita->casaRoja->getSbb().ratio * 3.0;
			addOrUpdateColliders(collidersSBB, "casa-" + std::to_string(i), casaToadCollider, casita->matrices[i]);
		}

		for (int i = 0; i < arbol->matrices.size(); i++) {
			AbstractModel::OBB arbolitoCollider;
			glm::mat4 modelMatrixColliderArbolito = glm::mat4(arbol->matrices[i]);
			// Set the orientation of collider before doing the scale
			arbolitoCollider.u = glm::quat_cast(arbol->matrices[i]);
			modelMatrixColliderArbolito = glm::scale(modelMatrixColliderArbolito, glm::vec3(3.0, 3.0, 3.0));
			modelMatrixColliderArbolito = glm::translate(modelMatrixColliderArbolito, arbol->getObb().c);
			modelMatrixColliderArbolito = glm::translate(modelMatrixColliderArbolito, glm::vec3(0.f, -0.4093f, 0.f));
			arbolitoCollider.c = glm::vec3(modelMatrixColliderArbolito[3]);
			arbolitoCollider.e = arbol->getObb().e * glm::vec3(3.0, 3.0, 3.0);
			addOrUpdateColliders(collidersOBB, "arbol-" + std::to_string(i), arbolitoCollider, arbol->matrices[i]);
		}

		//Collider Meta 

		AbstractModel::OBB metaColliderIzq;
		glm::mat4 modelMatrixColliderMetaIzq = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		metaColliderIzq.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderMetaIzq = glm::translate(modelMatrixColliderMetaIzq, meta->getObb().c);
		modelMatrixColliderMetaIzq = glm::translate(modelMatrixColliderMetaIzq, glm::vec3(-52.0f, -15.0f, 0.0f));
		metaColliderIzq.c = glm::vec3(modelMatrixColliderMetaIzq[3]);
		metaColliderIzq.e = meta->getObb().e * glm::vec3(0.01, 0.05, 0.1);
		addOrUpdateColliders(collidersOBB, "MetaIzq", metaColliderIzq, meta->matrix);

		AbstractModel::OBB metaColliderDer;
		glm::mat4 modelMatrixColliderMeta = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		metaColliderDer.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderMeta = glm::translate(modelMatrixColliderMeta, meta->getObb().c);
		modelMatrixColliderMeta = glm::translate(modelMatrixColliderMeta, glm::vec3(52.0f, -15.0f, 0.0f));
		metaColliderDer.c = glm::vec3(modelMatrixColliderMeta[3]);
		metaColliderDer.e = meta->getObb().e * glm::vec3(0.01, 0.05, 0.1);
		addOrUpdateColliders(collidersOBB, "MetaDer", metaColliderDer, meta->matrix);

		//Collider Puente
		AbstractModel::OBB puenteColliderPiso;
		glm::mat4 modelMatrixColliderPuentePiso = glm::mat4(puente->matrix);
		// Set the orientation of collider before doing the scale
		puenteColliderPiso.u = glm::quat_cast(puente->matrix);
		modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(5.9f, 0.5f, 5.0f));
		modelMatrixColliderPuentePiso = glm::translate(modelMatrixColliderPuentePiso, puente->getObb().c);
		modelMatrixColliderPuentePiso = glm::translate(modelMatrixColliderPuentePiso, glm::vec3(0.0f, -0.15f, 0.0f));
		puenteColliderPiso.c = glm::vec3(modelMatrixColliderPuentePiso[3]);
		puenteColliderPiso.e = puente->getObb().e * glm::vec3(5.9f, 0.5f, 5.0f);
		addOrUpdateColliders(collidersOBB, "PuentePiso", puenteColliderPiso, puente->matrix);

		AbstractModel::OBB puenteColliderIzq;
		glm::mat4 modelMatrixColliderPuenteIzq = glm::mat4(puente->matrix);
		// Set the orientation of collider before doing the scale
		puenteColliderIzq.u = glm::quat_cast(puente->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderPuenteIzq = glm::translate(modelMatrixColliderPuenteIzq, puente->getObb().c);
		modelMatrixColliderPuenteIzq = glm::translate(modelMatrixColliderPuenteIzq, glm::vec3(0.0f, 0.0f, -0.4f));
		puenteColliderIzq.c = glm::vec3(modelMatrixColliderPuenteIzq[3]);
		puenteColliderIzq.e = puente->getObb().e * glm::vec3(5.9f, 6.0f, 0.5f);
		addOrUpdateColliders(collidersOBB, "PuenteIzq", puenteColliderIzq, puente->matrix);

		AbstractModel::OBB puenteColliderDer;
		glm::mat4 modelMatrixColliderPuenteDer = glm::mat4(puente->matrix);
		// Set the orientation of collider before doing the scale
		puenteColliderDer.u = glm::quat_cast(puente->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderPuenteDer = glm::translate(modelMatrixColliderPuenteDer, puente->getObb().c);
		modelMatrixColliderPuenteDer = glm::translate(modelMatrixColliderPuenteDer, glm::vec3(0.0f, 0.0f, 0.4f));
		puenteColliderDer.c = glm::vec3(modelMatrixColliderPuenteDer[3]);
		puenteColliderDer.e = puente->getObb().e * glm::vec3(5.9f, 6.0f, 0.5f);
		addOrUpdateColliders(collidersOBB, "PuenteDer", puenteColliderDer, puente->matrix);

		//casas

		AbstractModel::OBB casa3Collider;
		glm::mat4 modelMatrixColliderCasa3 = glm::mat4(casa3->matrix);
		// Set the orientation of collider before doing the scale
		casa3Collider.u = glm::quat_cast(casa3->matrix);
		modelMatrixColliderCasa3 = glm::translate(modelMatrixColliderCasa3, casa3->getObb().c);
		modelMatrixColliderCasa3 = glm::translate(modelMatrixColliderCasa3, glm::vec3(0.0f, 0.0f, 0.2f));
		casa3Collider.c = glm::vec3(modelMatrixColliderCasa3[3]);
		casa3Collider.e = casa3->getObb().e * glm::vec3(10.0f, 10.0f, 5.0f);
		addOrUpdateColliders(collidersOBB, "Casa3", casa3Collider, casa3->matrix);

		AbstractModel::OBB casa2Collider;
		glm::mat4 modelMatrixColliderCasa2 = glm::mat4(casa2->matrix);
		// Set the orientation of collider before doing the scale
		casa2Collider.u = glm::quat_cast(casa2->matrix);
		modelMatrixColliderCasa2 = glm::translate(modelMatrixColliderCasa2, casa2->getObb().c);
		modelMatrixColliderCasa2 = glm::translate(modelMatrixColliderCasa2, glm::vec3(-2.4f, 0.0f, 2.5f));
		casa2Collider.c = glm::vec3(modelMatrixColliderCasa2[3]);
		casa2Collider.e = casa2->getObb().e * glm::vec3(0.35f, 0.5f, 0.35f);
		addOrUpdateColliders(collidersOBB, "Casa2", casa2Collider, casa2->matrix);

		AbstractModel::OBB casa1Collider;
		glm::mat4 modelMatrixColliderCasa1 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa1Collider.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa1 = glm::translate(modelMatrixColliderCasa1, casa1->getObb().c);
		modelMatrixColliderCasa1 = glm::translate(modelMatrixColliderCasa1, glm::vec3(0.0f, 0.0f, 0.0f));
		casa1Collider.c = glm::vec3(modelMatrixColliderCasa1[3]);
		casa1Collider.e = casa1->getObb().e * glm::vec3(1.5f, 1.8f, 1.5f);
		addOrUpdateColliders(collidersOBB, "Casa1", casa1Collider, casa1->matrix);

		AbstractModel::OBB casa6Collider;
		glm::mat4 modelMatrixColliderCasa6 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa6Collider.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa6 = glm::translate(modelMatrixColliderCasa6, casa1->getObb().c);
		modelMatrixColliderCasa6 = glm::translate(modelMatrixColliderCasa6, glm::vec3(1.0f, -2.0f, -58.5f));
		casa6Collider.c = glm::vec3(modelMatrixColliderCasa6[3]);
		casa6Collider.e = casa1->getObb().e * glm::vec3(1.2f, 1.8f, 1.55f);
		addOrUpdateColliders(collidersOBB, "Casa6", casa6Collider, casa1->matrix);

		AbstractModel::OBB torreCollider;
		glm::mat4 modelMatrixCollidertorre = glm::mat4(torre->matrix);
		// Set the orientation of collider before doing the scale
		torreCollider.u = glm::quat_cast(torre->matrix);
		modelMatrixCollidertorre = glm::translate(modelMatrixCollidertorre, torre->getObb().c);
		modelMatrixCollidertorre = glm::translate(modelMatrixCollidertorre, glm::vec3(0.0f, -0.47f, 0.0f));
		torreCollider.c = glm::vec3(modelMatrixCollidertorre[3]);
		torreCollider.e = torre->getObb().e * glm::vec3(36.0f, 1.0f, 36.0f);
		addOrUpdateColliders(collidersOBB, "torre", torreCollider, torre->matrix);

		AbstractModel::OBB casa5Collider;
		glm::mat4 modelMatrixColliderCasa5 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa5Collider.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa5 = glm::translate(modelMatrixColliderCasa5, casa1->getObb().c);
		modelMatrixColliderCasa5 = glm::translate(modelMatrixColliderCasa5, glm::vec3(22.0f, -4.0f, -61.0f));
		casa5Collider.c = glm::vec3(modelMatrixColliderCasa5[3]);
		casa5Collider.e = casa1->getObb().e * glm::vec3(3.5f, 0.7f, 2.5f);
		addOrUpdateColliders(collidersOBB, "Casa5", casa5Collider, casa1->matrix);
		
		AbstractModel::OBB casa4Collider;
		glm::mat4 modelMatrixColliderCasa4 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa4 = glm::translate(modelMatrixColliderCasa4, casa1->getObb().c);
		modelMatrixColliderCasa4 = glm::translate(modelMatrixColliderCasa4, glm::vec3(24.5f, 0.2f, -41.4f));
		casa4Collider.c = glm::vec3(modelMatrixColliderCasa4[3]);
		casa4Collider.e = casa1->getObb().e * glm::vec3(1.7f, 0.09f, 1.7f);
		addOrUpdateColliders(collidersOBB, "Casa4", casa4Collider, casa1->matrix);

		AbstractModel::OBB casa4Collider1;
		glm::mat4 modelMatrixColliderCasa41 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider1.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa41 = glm::translate(modelMatrixColliderCasa41, casa1->getObb().c);
		modelMatrixColliderCasa41 = glm::translate(modelMatrixColliderCasa41, glm::vec3(22.7f, -2.5f, -37.0f));
		casa4Collider1.c = glm::vec3(modelMatrixColliderCasa41[3]);
		casa4Collider1.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.1", casa4Collider1, casa1->matrix);

		AbstractModel::OBB casa4Collider2;
		glm::mat4 modelMatrixColliderCasa42 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider2.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa42 = glm::translate(modelMatrixColliderCasa42, casa1->getObb().c);
		modelMatrixColliderCasa42 = glm::translate(modelMatrixColliderCasa42, glm::vec3(23.0f, -2.2f, -37.0f));
		casa4Collider2.c = glm::vec3(modelMatrixColliderCasa42[3]);
		casa4Collider2.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.2", casa4Collider2, casa1->matrix);
		
		AbstractModel::OBB casa4Collider3;
		glm::mat4 modelMatrixColliderCasa43 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider3.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa43 = glm::translate(modelMatrixColliderCasa43, casa1->getObb().c);
		modelMatrixColliderCasa43 = glm::translate(modelMatrixColliderCasa43, glm::vec3(23.3f, -1.9f, -37.0f));
		casa4Collider3.c = glm::vec3(modelMatrixColliderCasa43[3]);
		casa4Collider3.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.3", casa4Collider3, casa1->matrix);

		AbstractModel::OBB casa4Collider4;
		glm::mat4 modelMatrixColliderCasa44 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider4.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa44 = glm::translate(modelMatrixColliderCasa44, casa1->getObb().c);
		modelMatrixColliderCasa44 = glm::translate(modelMatrixColliderCasa44, glm::vec3(23.6f, -1.6f, -37.0f));
		casa4Collider4.c = glm::vec3(modelMatrixColliderCasa44[3]);
		casa4Collider4.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.4", casa4Collider4, casa1->matrix);

		AbstractModel::OBB casa4Collider5;
		glm::mat4 modelMatrixColliderCasa45 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider5.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa45 = glm::translate(modelMatrixColliderCasa45, casa1->getObb().c);
		modelMatrixColliderCasa45 = glm::translate(modelMatrixColliderCasa45, glm::vec3(23.9f, -1.3f, -37.0f));
		casa4Collider5.c = glm::vec3(modelMatrixColliderCasa45[3]);
		casa4Collider5.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.5", casa4Collider5, casa1->matrix);

		AbstractModel::OBB casa4Collider6;
		glm::mat4 modelMatrixColliderCasa46 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider6.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa46 = glm::translate(modelMatrixColliderCasa46, casa1->getObb().c);
		modelMatrixColliderCasa46 = glm::translate(modelMatrixColliderCasa46, glm::vec3(24.2f, -1.0f, -37.0f));
		casa4Collider6.c = glm::vec3(modelMatrixColliderCasa46[3]);
		casa4Collider6.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.6", casa4Collider6, casa1->matrix);

		AbstractModel::OBB casa4Collider7;
		glm::mat4 modelMatrixColliderCasa47 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider7.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa47 = glm::translate(modelMatrixColliderCasa47, casa1->getObb().c);
		modelMatrixColliderCasa47 = glm::translate(modelMatrixColliderCasa47, glm::vec3(24.5f, -0.7f, -37.0f));
		casa4Collider7.c = glm::vec3(modelMatrixColliderCasa47[3]);
		casa4Collider7.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.7", casa4Collider7, casa1->matrix);

		AbstractModel::OBB casa4Collider8;
		glm::mat4 modelMatrixColliderCasa48 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider8.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa48 = glm::translate(modelMatrixColliderCasa48, casa1->getObb().c);
		modelMatrixColliderCasa48 = glm::translate(modelMatrixColliderCasa48, glm::vec3(24.8f, -0.4f, -37.0f));
		casa4Collider8.c = glm::vec3(modelMatrixColliderCasa48[3]);
		casa4Collider8.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.8", casa4Collider8, casa1->matrix);

		AbstractModel::OBB casa4Collider9;
		glm::mat4 modelMatrixColliderCasa49 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider9.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa49 = glm::translate(modelMatrixColliderCasa49, casa1->getObb().c);
		modelMatrixColliderCasa49 = glm::translate(modelMatrixColliderCasa49, glm::vec3(25.1f, -0.1f, -37.0f));
		casa4Collider9.c = glm::vec3(modelMatrixColliderCasa49[3]);
		casa4Collider9.e = casa1->getObb().e * glm::vec3(0.1f, 0.1f, 0.3f);
		addOrUpdateColliders(collidersOBB, "Casa4.9", casa4Collider9, casa1->matrix);

		AbstractModel::OBB casa4Collider10;
		glm::mat4 modelMatrixColliderCasa410 = glm::mat4(casa1->matrix);
		// Set the orientation of collider before doing the scale
		casa4Collider10.u = glm::quat_cast(casa1->matrix);
		modelMatrixColliderCasa410 = glm::translate(modelMatrixColliderCasa410, casa1->getObb().c);
		modelMatrixColliderCasa410 = glm::translate(modelMatrixColliderCasa410, glm::vec3(26.0f, 0.2f, -37.0f));
		casa4Collider10.c = glm::vec3(modelMatrixColliderCasa410[3]);
		casa4Collider10.e = casa1->getObb().e * glm::vec3(0.4f, 0.1f, 0.4f);
		addOrUpdateColliders(collidersOBB, "Casa4.10", casa4Collider10, casa1->matrix);

		AbstractModel::OBB fortalezaCollider;
		glm::mat4 modelMatrixColliderFortaleza = glm::mat4(fortaleza->matrix);
		// Set the orientation of collider before doing the scale
		fortalezaCollider.u = glm::quat_cast(fortaleza->matrix);
		modelMatrixColliderFortaleza = glm::translate(modelMatrixColliderFortaleza, fortaleza->getObb().c);
		modelMatrixColliderFortaleza = glm::translate(modelMatrixColliderFortaleza, glm::vec3(-2.0f, 0.0f, 0.0f));
		fortalezaCollider.c = glm::vec3(modelMatrixColliderFortaleza[3]);
		fortalezaCollider.e = fortaleza->getObb().e * glm::vec3(1.2f, 2.f, 1.9f);
		addOrUpdateColliders(collidersOBB, "fortaleza", fortalezaCollider, fortaleza->matrix);

		AbstractModel::OBB fortaleza1Collider;
		glm::mat4 modelMatrixColliderFortaleza1 = glm::mat4(fortaleza->matrix);
		// Set the orientation of collider before doing the scale
		fortaleza1Collider.u = glm::quat_cast(fortaleza->matrix);
		modelMatrixColliderFortaleza1 = glm::translate(modelMatrixColliderFortaleza1, fortaleza->getObb().c);
		modelMatrixColliderFortaleza1 = glm::translate(modelMatrixColliderFortaleza1, glm::vec3(3.0f, 0.0f, 0.3f));
		fortaleza1Collider.c = glm::vec3(modelMatrixColliderFortaleza1[3]);
		fortaleza1Collider.e = fortaleza->getObb().e * glm::vec3(0.6f, 2.f, 1.1f);
		addOrUpdateColliders(collidersOBB, "fortaleza1", fortaleza1Collider, fortaleza->matrix);

		//Perks
		
		AbstractModel::OBB speedColaCollider;
		glm::mat4 modelMatrixColliderspeedCola = glm::mat4(speedCola->matrix);
		// Set the orientation of collider before doing the scale
		speedColaCollider.u = glm::quat_cast(speedCola->matrix);
		modelMatrixColliderspeedCola = glm::translate(modelMatrixColliderspeedCola, speedCola->getObb().c);
		modelMatrixColliderspeedCola = glm::translate(modelMatrixColliderspeedCola, glm::vec3(0.0f, 0.0f, 0.0f));
		speedColaCollider.c = glm::vec3(modelMatrixColliderspeedCola[3]);
		speedColaCollider.e = speedCola->getObb().e * glm::vec3(0.05f, 0.05f, 0.05f);
		addOrUpdateColliders(collidersOBB, "speedCola", speedColaCollider, speedCola->matrix);

		AbstractModel::OBB juggerNogCollider;
		glm::mat4 modelMatrixColliderjuggerNog = glm::mat4(juggerNog->matrix);
		// Set the orientation of collider before doing the scale
		juggerNogCollider.u = glm::quat_cast(juggerNog->matrix);
		modelMatrixColliderjuggerNog = glm::translate(modelMatrixColliderjuggerNog, juggerNog->getObb().c);
		modelMatrixColliderjuggerNog = glm::translate(modelMatrixColliderjuggerNog, glm::vec3(0.0f, 0.0f, 0.0f));
		juggerNogCollider.c = glm::vec3(modelMatrixColliderjuggerNog[3]);
		juggerNogCollider.e = juggerNog->getObb().e * glm::vec3(0.05f, 0.05f, 0.05f);
		addOrUpdateColliders(collidersOBB, "juggerNog", juggerNogCollider, juggerNog->matrix);

		AbstractModel::OBB doubleTapCollider;
		glm::mat4 modelMatrixColliderdoubleTap = glm::mat4(doubleTap->matrix);
		// Set the orientation of collider before doing the scale
		doubleTapCollider.u = glm::quat_cast(doubleTap->matrix);
		modelMatrixColliderdoubleTap = glm::translate(modelMatrixColliderdoubleTap, doubleTap->getObb().c);
		modelMatrixColliderdoubleTap = glm::translate(modelMatrixColliderdoubleTap, glm::vec3(0.0f, 0.0f, 0.0f));
		doubleTapCollider.c = glm::vec3(modelMatrixColliderdoubleTap[3]);
		doubleTapCollider.e = doubleTap->getObb().e * glm::vec3(0.05f, 0.05f, 0.05f);
		addOrUpdateColliders(collidersOBB, "doubleTap", doubleTapCollider, doubleTap->matrix);

		AbstractModel::OBB quickReviveCollider;
		glm::mat4 modelMatrixColliderquickRevive = glm::mat4(quickRevive->matrix);
		// Set the orientation of collider before doing the scale
		quickReviveCollider.u = glm::quat_cast(quickRevive->matrix);
		modelMatrixColliderquickRevive = glm::translate(modelMatrixColliderquickRevive, quickRevive->getObb().c);
		modelMatrixColliderquickRevive = glm::translate(modelMatrixColliderquickRevive, glm::vec3(0.0f, 0.0f, 0.0f));
		quickReviveCollider.c = glm::vec3(modelMatrixColliderquickRevive[3]);
		quickReviveCollider.e = quickRevive->getObb().e * glm::vec3(0.05f, 0.05f, 0.05f);
		addOrUpdateColliders(collidersOBB, "quickRevive", quickReviveCollider, quickRevive->matrix);


		//Collider Laberinto *****************************************************************************
		AbstractModel::OBB laberintoCollider0;
		glm::mat4 modelMatrixColliderLaberinto0 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider0.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto0 = glm::translate(modelMatrixColliderLaberinto0, meta->getObb().c);
		modelMatrixColliderLaberinto0 = glm::translate(modelMatrixColliderLaberinto0, glm::vec3(445.0f, 5.0f, 167.0f));
		laberintoCollider0.c = glm::vec3(modelMatrixColliderLaberinto0[3]);
		laberintoCollider0.e = meta->getObb().e * glm::vec3(0.31, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto0", laberintoCollider0, meta->matrix);

		AbstractModel::OBB laberintoCollider1;
		glm::mat4 modelMatrixColliderLaberinto1 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider1.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto1 = glm::translate(modelMatrixColliderLaberinto1, meta->getObb().c);
		modelMatrixColliderLaberinto1 = glm::translate(modelMatrixColliderLaberinto1, glm::vec3(445.0f, 5.0f, 202.0f));
		laberintoCollider1.c = glm::vec3(modelMatrixColliderLaberinto1[3]);
		laberintoCollider1.e = meta->getObb().e * glm::vec3(0.25, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto1", laberintoCollider1, meta->matrix);

		AbstractModel::OBB laberintoCollider2;
		glm::mat4 modelMatrixColliderLaberinto2 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider2.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto2 = glm::translate(modelMatrixColliderLaberinto2, meta->getObb().c);
		modelMatrixColliderLaberinto2 = glm::translate(modelMatrixColliderLaberinto2, glm::vec3(450.0f, 5.0f, 238.0f));
		laberintoCollider2.c = glm::vec3(modelMatrixColliderLaberinto2[3]);
		laberintoCollider2.e = meta->getObb().e * glm::vec3(0.19, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto2", laberintoCollider2, meta->matrix);

		AbstractModel::OBB laberintoCollider3;
		glm::mat4 modelMatrixColliderLaberinto3 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider3.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto3 = glm::translate(modelMatrixColliderLaberinto3, meta->getObb().c);
		modelMatrixColliderLaberinto3 = glm::translate(modelMatrixColliderLaberinto3, glm::vec3(455.0f, 5.0f, 274.0f));
		laberintoCollider3.c = glm::vec3(modelMatrixColliderLaberinto3[3]);
		laberintoCollider3.e = meta->getObb().e * glm::vec3(0.16, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto3", laberintoCollider3, meta->matrix);

		AbstractModel::OBB laberintoCollider4;
		glm::mat4 modelMatrixColliderLaberinto4 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider4.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto4 = glm::translate(modelMatrixColliderLaberinto4, meta->getObb().c);
		modelMatrixColliderLaberinto4 = glm::translate(modelMatrixColliderLaberinto4, glm::vec3(525.0f, 5.0f, 310.0f));
		laberintoCollider4.c = glm::vec3(modelMatrixColliderLaberinto4[3]);
		laberintoCollider4.e = meta->getObb().e * glm::vec3(0.22, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto4", laberintoCollider4, meta->matrix);
		//****
		AbstractModel::OBB laberintoCollider5;
		glm::mat4 modelMatrixColliderLaberinto5 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider5.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto5 = glm::translate(modelMatrixColliderLaberinto5, meta->getObb().c);
		modelMatrixColliderLaberinto5 = glm::translate(modelMatrixColliderLaberinto5, glm::vec3(808.0f, 5.0f, 167.0f));
		laberintoCollider5.c = glm::vec3(modelMatrixColliderLaberinto5[3]);
		laberintoCollider5.e = meta->getObb().e * glm::vec3(0.30, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto5", laberintoCollider5, meta->matrix);

		AbstractModel::OBB laberintoCollider6;
		glm::mat4 modelMatrixColliderLaberinto6 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider6.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto6 = glm::translate(modelMatrixColliderLaberinto6, meta->getObb().c);
		modelMatrixColliderLaberinto6 = glm::translate(modelMatrixColliderLaberinto6, glm::vec3(810.0f, 5.0f, 202.0f));
		laberintoCollider6.c = glm::vec3(modelMatrixColliderLaberinto6[3]);
		laberintoCollider6.e = meta->getObb().e * glm::vec3(0.25, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto6", laberintoCollider6, meta->matrix);

		AbstractModel::OBB laberintoCollider7;
		glm::mat4 modelMatrixColliderLaberinto7 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider7.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto7 = glm::translate(modelMatrixColliderLaberinto7, meta->getObb().c);
		modelMatrixColliderLaberinto7 = glm::translate(modelMatrixColliderLaberinto7, glm::vec3(780.0f, 5.0f, 238.0f));
		laberintoCollider7.c = glm::vec3(modelMatrixColliderLaberinto7[3]);
		laberintoCollider7.e = meta->getObb().e * glm::vec3(0.25, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto7", laberintoCollider7, meta->matrix);

		AbstractModel::OBB laberintoCollider8;
		glm::mat4 modelMatrixColliderLaberinto8 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider8.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto8 = glm::translate(modelMatrixColliderLaberinto8, meta->getObb().c);
		modelMatrixColliderLaberinto8 = glm::translate(modelMatrixColliderLaberinto8, glm::vec3(755.0f, 5.0f, 274.0f));
		laberintoCollider8.c = glm::vec3(modelMatrixColliderLaberinto8[3]);
		laberintoCollider8.e = meta->getObb().e * glm::vec3(0.25, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto8", laberintoCollider8, meta->matrix);

		AbstractModel::OBB laberintoCollider9;
		glm::mat4 modelMatrixColliderLaberinto9 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider9.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto9 = glm::translate(modelMatrixColliderLaberinto9, meta->getObb().c);
		modelMatrixColliderLaberinto9 = glm::translate(modelMatrixColliderLaberinto9, glm::vec3(780.0f, 5.0f, 310.0f));
		laberintoCollider9.c = glm::vec3(modelMatrixColliderLaberinto9[3]);
		laberintoCollider9.e = meta->getObb().e * glm::vec3(0.14, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto9", laberintoCollider9, meta->matrix);

		//77777777777777777

		AbstractModel::OBB laberintoCollider10;
		glm::mat4 modelMatrixColliderLaberinto10 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider10.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto10 = glm::translate(modelMatrixColliderLaberinto10, meta->getObb().c);
		modelMatrixColliderLaberinto10 = glm::translate(modelMatrixColliderLaberinto10, glm::vec3(779.0f, 5.0f, 346.0f));
		laberintoCollider10.c = glm::vec3(modelMatrixColliderLaberinto10[3]);
		laberintoCollider10.e = meta->getObb().e * glm::vec3(0.08, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto10", laberintoCollider10, meta->matrix);

		AbstractModel::OBB laberintoCollider11;
		glm::mat4 modelMatrixColliderLaberinto11 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider11.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto11 = glm::translate(modelMatrixColliderLaberinto11, meta->getObb().c);
		modelMatrixColliderLaberinto11 = glm::translate(modelMatrixColliderLaberinto11, glm::vec3(765.0f, 5.0f, 386.0f));
		laberintoCollider11.c = glm::vec3(modelMatrixColliderLaberinto11[3]);
		laberintoCollider11.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto11", laberintoCollider11, meta->matrix);

		AbstractModel::OBB laberintoCollider12;
		glm::mat4 modelMatrixColliderLaberinto12 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider12.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto12 = glm::translate(modelMatrixColliderLaberinto12, meta->getObb().c);
		modelMatrixColliderLaberinto12 = glm::translate(modelMatrixColliderLaberinto12, glm::vec3(735.0f, 5.0f, 420.0f));
		laberintoCollider12.c = glm::vec3(modelMatrixColliderLaberinto12[3]);
		laberintoCollider12.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto12", laberintoCollider12, meta->matrix);

		AbstractModel::OBB laberintoCollider13;
		glm::mat4 modelMatrixColliderLaberinto13 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider13.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto13 = glm::translate(modelMatrixColliderLaberinto13, meta->getObb().c);
		modelMatrixColliderLaberinto13 = glm::translate(modelMatrixColliderLaberinto13, glm::vec3(705.0f, 5.0f, 456.0f));
		laberintoCollider13.c = glm::vec3(modelMatrixColliderLaberinto13[3]);
		laberintoCollider13.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto13", laberintoCollider13, meta->matrix);

		AbstractModel::OBB laberintoCollider14;
		glm::mat4 modelMatrixColliderLaberinto14 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider14.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto14 = glm::translate(modelMatrixColliderLaberinto14, meta->getObb().c);
		modelMatrixColliderLaberinto14 = glm::translate(modelMatrixColliderLaberinto14, glm::vec3(675.0f, 5.0f, 493.0f));
		laberintoCollider14.c = glm::vec3(modelMatrixColliderLaberinto14[3]);
		laberintoCollider14.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto14", laberintoCollider14, meta->matrix);

		AbstractModel::OBB laberintoCollider15;
		glm::mat4 modelMatrixColliderLaberinto15 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider15.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto15 = glm::translate(modelMatrixColliderLaberinto15, meta->getObb().c);
		modelMatrixColliderLaberinto15 = glm::translate(modelMatrixColliderLaberinto15, glm::vec3(660.0f, 5.0f, 529.0f));
		laberintoCollider15.c = glm::vec3(modelMatrixColliderLaberinto15[3]);
		laberintoCollider15.e = meta->getObb().e * glm::vec3(0.03, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto15", laberintoCollider15, meta->matrix);
		
		//jjjjjjjjjjjjjjjjj

		AbstractModel::OBB laberintoCollider16;
		glm::mat4 modelMatrixColliderLaberinto16 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider16.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto16 = glm::translate(modelMatrixColliderLaberinto16, meta->getObb().c);
		modelMatrixColliderLaberinto16 = glm::translate(modelMatrixColliderLaberinto16, glm::vec3(630.0f, 5.0f, 640.0f));
		laberintoCollider16.c = glm::vec3(modelMatrixColliderLaberinto16[3]);
		laberintoCollider16.e = meta->getObb().e * glm::vec3(0.08, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto16", laberintoCollider16, meta->matrix);

		AbstractModel::OBB laberintoCollider17;
		glm::mat4 modelMatrixColliderLaberinto17 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider17.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto17 = glm::translate(modelMatrixColliderLaberinto17, meta->getObb().c);
		modelMatrixColliderLaberinto17 = glm::translate(modelMatrixColliderLaberinto17, glm::vec3(630.0f, 5.0f, 675.0f));
		laberintoCollider17.c = glm::vec3(modelMatrixColliderLaberinto17[3]);
		laberintoCollider17.e = meta->getObb().e * glm::vec3(0.14, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto17", laberintoCollider17, meta->matrix);

		AbstractModel::OBB laberintoCollider18;
		glm::mat4 modelMatrixColliderLaberinto18 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider18.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto18 = glm::translate(modelMatrixColliderLaberinto18, meta->getObb().c);
		modelMatrixColliderLaberinto18 = glm::translate(modelMatrixColliderLaberinto18, glm::vec3(630.0f, 5.0f, 710.0f));
		laberintoCollider18.c = glm::vec3(modelMatrixColliderLaberinto18[3]);
		laberintoCollider18.e = meta->getObb().e * glm::vec3(0.63, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto18", laberintoCollider18, meta->matrix);

		//kkkkkkkkkkkkkk

		AbstractModel::OBB laberintoCollider19;
		glm::mat4 modelMatrixColliderLaberinto19 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider19.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto19 = glm::translate(modelMatrixColliderLaberinto19, meta->getObb().c);
		modelMatrixColliderLaberinto19 = glm::translate(modelMatrixColliderLaberinto19, glm::vec3(524.0f, 5.0f, 346.0f));
		laberintoCollider19.c = glm::vec3(modelMatrixColliderLaberinto19[3]);
		laberintoCollider19.e = meta->getObb().e * glm::vec3(0.17, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto19", laberintoCollider19, meta->matrix);

		AbstractModel::OBB laberintoCollider20;
		glm::mat4 modelMatrixColliderLaberinto20 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider20.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto20 = glm::translate(modelMatrixColliderLaberinto20, meta->getObb().c);
		modelMatrixColliderLaberinto20 = glm::translate(modelMatrixColliderLaberinto20, glm::vec3(525.0f, 5.0f, 386.0f));
		laberintoCollider20.c = glm::vec3(modelMatrixColliderLaberinto20[3]);
		laberintoCollider20.e = meta->getObb().e * glm::vec3(0.11, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto20", laberintoCollider20, meta->matrix);

		AbstractModel::OBB laberintoCollider21;
		glm::mat4 modelMatrixColliderLaberinto21 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider21.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto21 = glm::translate(modelMatrixColliderLaberinto21, meta->getObb().c);
		modelMatrixColliderLaberinto21 = glm::translate(modelMatrixColliderLaberinto21, glm::vec3(525.0f, 5.0f, 420.0f));
		laberintoCollider21.c = glm::vec3(modelMatrixColliderLaberinto21[3]);
		laberintoCollider21.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto21", laberintoCollider21, meta->matrix);

		AbstractModel::OBB laberintoCollider22;
		glm::mat4 modelMatrixColliderLaberinto22 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider22.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto22 = glm::translate(modelMatrixColliderLaberinto22, meta->getObb().c);
		modelMatrixColliderLaberinto22 = glm::translate(modelMatrixColliderLaberinto22, glm::vec3(555.0f, 5.0f, 456.0f));
		laberintoCollider22.c = glm::vec3(modelMatrixColliderLaberinto22[3]);
		laberintoCollider22.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto22", laberintoCollider22, meta->matrix);

		AbstractModel::OBB laberintoCollider23;
		glm::mat4 modelMatrixColliderLaberinto23 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider23.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto23 = glm::translate(modelMatrixColliderLaberinto23, meta->getObb().c);
		modelMatrixColliderLaberinto23 = glm::translate(modelMatrixColliderLaberinto23, glm::vec3(586.0f, 5.0f, 493.0f));
		laberintoCollider23.c = glm::vec3(modelMatrixColliderLaberinto23[3]);
		laberintoCollider23.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto23", laberintoCollider23, meta->matrix);

		AbstractModel::OBB laberintoCollider24;
		glm::mat4 modelMatrixColliderLaberinto24 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider24.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto24 = glm::translate(modelMatrixColliderLaberinto24, meta->getObb().c);
		modelMatrixColliderLaberinto24 = glm::translate(modelMatrixColliderLaberinto24, glm::vec3(600.0f, 5.0f, 529.0f));
		laberintoCollider24.c = glm::vec3(modelMatrixColliderLaberinto24[3]);
		laberintoCollider24.e = meta->getObb().e * glm::vec3(0.03, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto24", laberintoCollider24, meta->matrix);

		//ffffff

		AbstractModel::OBB laberintoCollider25;
		glm::mat4 modelMatrixColliderLaberinto25 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider25.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto25 = glm::translate(modelMatrixColliderLaberinto25, meta->getObb().c);
		modelMatrixColliderLaberinto25 = glm::translate(modelMatrixColliderLaberinto25, glm::vec3(525.0f, 5.0f, 565.0f));
		laberintoCollider25.c = glm::vec3(modelMatrixColliderLaberinto25[3]);
		laberintoCollider25.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto25", laberintoCollider25, meta->matrix);

		AbstractModel::OBB laberintoCollider26;
		glm::mat4 modelMatrixColliderLaberinto26 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider26.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto26 = glm::translate(modelMatrixColliderLaberinto26, meta->getObb().c);
		modelMatrixColliderLaberinto26 = glm::translate(modelMatrixColliderLaberinto26, glm::vec3(525.0f, 5.0f, 601.0f));
		laberintoCollider26.c = glm::vec3(modelMatrixColliderLaberinto26[3]);
		laberintoCollider26.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto26", laberintoCollider26, meta->matrix);

		AbstractModel::OBB laberintoCollider27;
		glm::mat4 modelMatrixColliderLaberinto27 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider27.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto27 = glm::translate(modelMatrixColliderLaberinto27, meta->getObb().c);
		modelMatrixColliderLaberinto27 = glm::translate(modelMatrixColliderLaberinto27, glm::vec3(403.0f, 5.0f, 565.0f));
		laberintoCollider27.c = glm::vec3(modelMatrixColliderLaberinto27[3]);
		laberintoCollider27.e = meta->getObb().e * glm::vec3(0.12, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto27", laberintoCollider27, meta->matrix);

		AbstractModel::OBB laberintoCollider28;
		glm::mat4 modelMatrixColliderLaberinto28 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider28.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto28 = glm::translate(modelMatrixColliderLaberinto28, meta->getObb().c);
		modelMatrixColliderLaberinto28 = glm::translate(modelMatrixColliderLaberinto28, glm::vec3(433.0f, 5.0f, 601.0f));
		laberintoCollider28.c = glm::vec3(modelMatrixColliderLaberinto28[3]);
		laberintoCollider28.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto28", laberintoCollider28, meta->matrix);

		AbstractModel::OBB laberintoCollider29;
		glm::mat4 modelMatrixColliderLaberinto29 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider29.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto29 = glm::translate(modelMatrixColliderLaberinto29, meta->getObb().c);
		modelMatrixColliderLaberinto29 = glm::translate(modelMatrixColliderLaberinto29, glm::vec3(328.0f, 5.0f, 601.0f));
		laberintoCollider29.c = glm::vec3(modelMatrixColliderLaberinto29[3]);
		laberintoCollider29.e = meta->getObb().e * glm::vec3(0.03, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto29", laberintoCollider29, meta->matrix);

		AbstractModel::OBB laberintoCollider30;
		glm::mat4 modelMatrixColliderLaberinto30 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider30.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto30 = glm::translate(modelMatrixColliderLaberinto30, meta->getObb().c);
		modelMatrixColliderLaberinto30 = glm::translate(modelMatrixColliderLaberinto30, glm::vec3(735.0f, 5.0f, 601.0f));
		laberintoCollider30.c = glm::vec3(modelMatrixColliderLaberinto30[3]);
		laberintoCollider30.e = meta->getObb().e * glm::vec3(0.05, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto30", laberintoCollider30, meta->matrix);

		AbstractModel::OBB laberintoCollider31;
		glm::mat4 modelMatrixColliderLaberinto31 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider31.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto31 = glm::translate(modelMatrixColliderLaberinto31, meta->getObb().c);
		modelMatrixColliderLaberinto31 = glm::translate(modelMatrixColliderLaberinto31, glm::vec3(855.0f, 5.0f, 601.0f));
		laberintoCollider31.c = glm::vec3(modelMatrixColliderLaberinto31[3]);
		laberintoCollider31.e = meta->getObb().e * glm::vec3(0.11, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto31", laberintoCollider31, meta->matrix);

		AbstractModel::OBB laberintoCollider32;
		glm::mat4 modelMatrixColliderLaberinto32 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider32.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto32 = glm::translate(modelMatrixColliderLaberinto32, meta->getObb().c);
		modelMatrixColliderLaberinto32 = glm::translate(modelMatrixColliderLaberinto32, glm::vec3(887.0f, 5.0f, 565.0f));
		laberintoCollider32.c = glm::vec3(modelMatrixColliderLaberinto32[3]);
		laberintoCollider32.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto32", laberintoCollider32, meta->matrix);

		AbstractModel::OBB laberintoCollider33;
		glm::mat4 modelMatrixColliderLaberinto33 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider33.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto33 = glm::translate(modelMatrixColliderLaberinto33, meta->getObb().c);
		modelMatrixColliderLaberinto33 = glm::translate(modelMatrixColliderLaberinto33, glm::vec3(404.0f, 5.0f, 530.0f));
		laberintoCollider33.c = glm::vec3(modelMatrixColliderLaberinto33[3]);
		laberintoCollider33.e = meta->getObb().e * glm::vec3(0.06, 0.05, 0.01);
		addOrUpdateColliders(collidersOBB, "laberinto33", laberintoCollider33, meta->matrix);
		
		AbstractModel::OBB laberintoCollider34;
		glm::mat4 modelMatrixColliderLaberinto34 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider34.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto34 = glm::translate(modelMatrixColliderLaberinto34, meta->getObb().c);
		modelMatrixColliderLaberinto34 = glm::translate(modelMatrixColliderLaberinto34, glm::vec3(280.0f, 5.0f, 440.0f));
		laberintoCollider34.c = glm::vec3(modelMatrixColliderLaberinto34[3]);
		laberintoCollider34.e = meta->getObb().e * glm::vec3(0.001, 0.05, 3.5);
		addOrUpdateColliders(collidersOBB, "laberinto34", laberintoCollider34, meta->matrix);

		AbstractModel::OBB laberintoCollider35;
		glm::mat4 modelMatrixColliderLaberinto35 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider35.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto35 = glm::translate(modelMatrixColliderLaberinto35, meta->getObb().c);
		modelMatrixColliderLaberinto35 = glm::translate(modelMatrixColliderLaberinto35, glm::vec3(310.0f, 5.0f, 405.0f));
		laberintoCollider35.c = glm::vec3(modelMatrixColliderLaberinto35[3]);
		laberintoCollider35.e = meta->getObb().e * glm::vec3(0.001, 0.05, 2.5);
		addOrUpdateColliders(collidersOBB, "laberinto35", laberintoCollider35, meta->matrix);

		AbstractModel::OBB laberintoCollider36;
		glm::mat4 modelMatrixColliderLaberinto36 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider36.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto36 = glm::translate(modelMatrixColliderLaberinto36, meta->getObb().c);
		modelMatrixColliderLaberinto36 = glm::translate(modelMatrixColliderLaberinto36, glm::vec3(310.0f, 5.0f, 660.0f));
		laberintoCollider36.c = glm::vec3(modelMatrixColliderLaberinto36[3]);
		laberintoCollider36.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.3);
		addOrUpdateColliders(collidersOBB, "laberinto36", laberintoCollider36, meta->matrix);

		AbstractModel::OBB laberintoCollider37;
		glm::mat4 modelMatrixColliderLaberinto37 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider37.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto37 = glm::translate(modelMatrixColliderLaberinto37, meta->getObb().c);
		modelMatrixColliderLaberinto37 = glm::translate(modelMatrixColliderLaberinto37, glm::vec3(341.0f, 5.0f, 400.0f));
		laberintoCollider37.c = glm::vec3(modelMatrixColliderLaberinto37[3]);
		laberintoCollider37.e = meta->getObb().e * glm::vec3(0.001, 0.05, 2.0);
		addOrUpdateColliders(collidersOBB, "laberinto37", laberintoCollider37, meta->matrix);

		AbstractModel::OBB laberintoCollider38;
		glm::mat4 modelMatrixColliderLaberinto38 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider38.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto38 = glm::translate(modelMatrixColliderLaberinto38, meta->getObb().c);
		modelMatrixColliderLaberinto38 = glm::translate(modelMatrixColliderLaberinto38, glm::vec3(341.0f, 5.0f, 640.0f));
		laberintoCollider38.c = glm::vec3(modelMatrixColliderLaberinto38[3]);
		laberintoCollider38.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.48);
		addOrUpdateColliders(collidersOBB, "laberinto38", laberintoCollider38, meta->matrix);

		AbstractModel::OBB laberintoCollider39;
		glm::mat4 modelMatrixColliderLaberinto39 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider39.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto39 = glm::translate(modelMatrixColliderLaberinto39, meta->getObb().c);
		modelMatrixColliderLaberinto39 = glm::translate(modelMatrixColliderLaberinto39, glm::vec3(371.0f, 5.0f, 405.0f));
		laberintoCollider39.c = glm::vec3(modelMatrixColliderLaberinto39[3]);
		laberintoCollider39.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.6);
		addOrUpdateColliders(collidersOBB, "laberinto39", laberintoCollider39, meta->matrix);

		AbstractModel::OBB laberintoCollider40;
		glm::mat4 modelMatrixColliderLaberinto40 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider40.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto40 = glm::translate(modelMatrixColliderLaberinto40, meta->getObb().c);
		modelMatrixColliderLaberinto40 = glm::translate(modelMatrixColliderLaberinto40, glm::vec3(371.0f, 5.0f, 625.0f));
		laberintoCollider40.c = glm::vec3(modelMatrixColliderLaberinto40[3]);
		laberintoCollider40.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.65);
		addOrUpdateColliders(collidersOBB, "laberinto40", laberintoCollider40, meta->matrix);

		AbstractModel::OBB laberintoCollider41;
		glm::mat4 modelMatrixColliderLaberinto41 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider41.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto41 = glm::translate(modelMatrixColliderLaberinto41, meta->getObb().c);
		modelMatrixColliderLaberinto41 = glm::translate(modelMatrixColliderLaberinto41, glm::vec3(403.0f, 5.0f, 405.0f));
		laberintoCollider41.c = glm::vec3(modelMatrixColliderLaberinto41[3]);
		laberintoCollider41.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.2);
		addOrUpdateColliders(collidersOBB, "laberinto41", laberintoCollider41, meta->matrix);

		AbstractModel::OBB laberintoCollider42;
		glm::mat4 modelMatrixColliderLaberinto42 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider42.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto42 = glm::translate(modelMatrixColliderLaberinto42, meta->getObb().c);
		modelMatrixColliderLaberinto42 = glm::translate(modelMatrixColliderLaberinto42, glm::vec3(403.0f, 5.0f, 645.0f));
		laberintoCollider42.c = glm::vec3(modelMatrixColliderLaberinto42[3]);
		laberintoCollider42.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto42", laberintoCollider42, meta->matrix);

		AbstractModel::OBB laberintoCollider43;
		glm::mat4 modelMatrixColliderLaberinto43 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider43.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto43 = glm::translate(modelMatrixColliderLaberinto43, meta->getObb().c);
		modelMatrixColliderLaberinto43 = glm::translate(modelMatrixColliderLaberinto43, glm::vec3(433.0f, 5.0f, 435.0f));
		laberintoCollider43.c = glm::vec3(modelMatrixColliderLaberinto43[3]);
		laberintoCollider43.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.1);
		addOrUpdateColliders(collidersOBB, "laberinto43", laberintoCollider43, meta->matrix);

		AbstractModel::OBB laberintoCollider44;
		glm::mat4 modelMatrixColliderLaberinto44 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider44.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto44 = glm::translate(modelMatrixColliderLaberinto44, meta->getObb().c);
		modelMatrixColliderLaberinto44 = glm::translate(modelMatrixColliderLaberinto44, glm::vec3(433.0f, 5.0f, 655.0f));
		laberintoCollider44.c = glm::vec3(modelMatrixColliderLaberinto44[3]);
		laberintoCollider44.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.3);
		addOrUpdateColliders(collidersOBB, "laberinto44", laberintoCollider44, meta->matrix);

		AbstractModel::OBB laberintoCollider45;
		glm::mat4 modelMatrixColliderLaberinto45 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider45.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto45 = glm::translate(modelMatrixColliderLaberinto45, meta->getObb().c);
		modelMatrixColliderLaberinto45 = glm::translate(modelMatrixColliderLaberinto45, glm::vec3(463.0f, 5.0f, 467.0f));
		laberintoCollider45.c = glm::vec3(modelMatrixColliderLaberinto45[3]);
		laberintoCollider45.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.1);
		addOrUpdateColliders(collidersOBB, "laberinto45", laberintoCollider45, meta->matrix);

		AbstractModel::OBB laberintoCollider46;
		glm::mat4 modelMatrixColliderLaberinto46 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider46.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto46 = glm::translate(modelMatrixColliderLaberinto46, meta->getObb().c);
		modelMatrixColliderLaberinto46 = glm::translate(modelMatrixColliderLaberinto46, glm::vec3(463.0f, 5.0f, 645.0f));
		laberintoCollider46.c = glm::vec3(modelMatrixColliderLaberinto46[3]);
		laberintoCollider46.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto46", laberintoCollider46, meta->matrix);

		AbstractModel::OBB laberintoCollider47;
		glm::mat4 modelMatrixColliderLaberinto47 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider47.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto47 = glm::translate(modelMatrixColliderLaberinto47, meta->getObb().c);
		modelMatrixColliderLaberinto47 = glm::translate(modelMatrixColliderLaberinto47, glm::vec3(493.0f, 5.0f, 495.0f));
		laberintoCollider47.c = glm::vec3(modelMatrixColliderLaberinto47[3]);
		laberintoCollider47.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.85);
		addOrUpdateColliders(collidersOBB, "laberinto47", laberintoCollider47, meta->matrix);

		AbstractModel::OBB laberintoCollider48;
		glm::mat4 modelMatrixColliderLaberinto48 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider48.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto48 = glm::translate(modelMatrixColliderLaberinto48, meta->getObb().c);
		modelMatrixColliderLaberinto48 = glm::translate(modelMatrixColliderLaberinto48, glm::vec3(493.0f, 5.0f, 645.0f));
		laberintoCollider48.c = glm::vec3(modelMatrixColliderLaberinto48[3]);
		laberintoCollider48.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto48", laberintoCollider48, meta->matrix);

		AbstractModel::OBB laberintoCollider49;
		glm::mat4 modelMatrixColliderLaberinto49 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider49.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto49 = glm::translate(modelMatrixColliderLaberinto49, meta->getObb().c);
		modelMatrixColliderLaberinto49 = glm::translate(modelMatrixColliderLaberinto49, glm::vec3(523.0f, 5.0f, 500.0f));
		laberintoCollider49.c = glm::vec3(modelMatrixColliderLaberinto49[3]);
		laberintoCollider49.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto49", laberintoCollider49, meta->matrix);

		AbstractModel::OBB laberintoCollider50;
		glm::mat4 modelMatrixColliderLaberinto50 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider50.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto50 = glm::translate(modelMatrixColliderLaberinto50, meta->getObb().c);
		modelMatrixColliderLaberinto50 = glm::translate(modelMatrixColliderLaberinto50, glm::vec3(523.0f, 5.0f, 660.0f));
		laberintoCollider50.c = glm::vec3(modelMatrixColliderLaberinto50[3]);
		laberintoCollider50.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.3);
		addOrUpdateColliders(collidersOBB, "laberinto50", laberintoCollider50, meta->matrix);

		AbstractModel::OBB laberintoCollider51;
		glm::mat4 modelMatrixColliderLaberinto51 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider51.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto51 = glm::translate(modelMatrixColliderLaberinto51, meta->getObb().c);
		modelMatrixColliderLaberinto51 = glm::translate(modelMatrixColliderLaberinto51, glm::vec3(553.0f, 5.0f, 530.0f));
		laberintoCollider51.c = glm::vec3(modelMatrixColliderLaberinto51[3]);
		laberintoCollider51.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto51", laberintoCollider51, meta->matrix);

		AbstractModel::OBB laberintoCollider52;
		glm::mat4 modelMatrixColliderLaberinto52 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider52.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto52 = glm::translate(modelMatrixColliderLaberinto52, meta->getObb().c);
		modelMatrixColliderLaberinto52 = glm::translate(modelMatrixColliderLaberinto52, glm::vec3(553.0f, 5.0f, 640.0f));
		laberintoCollider52.c = glm::vec3(modelMatrixColliderLaberinto52[3]);
		laberintoCollider52.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto52", laberintoCollider52, meta->matrix);

		AbstractModel::OBB laberintoCollider53;
		glm::mat4 modelMatrixColliderLaberinto53 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider53.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto53 = glm::translate(modelMatrixColliderLaberinto53, meta->getObb().c);
		modelMatrixColliderLaberinto53 = glm::translate(modelMatrixColliderLaberinto53, glm::vec3(583.0f, 5.0f, 425.0f));
		laberintoCollider53.c = glm::vec3(modelMatrixColliderLaberinto53[3]);
		laberintoCollider53.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.38);
		addOrUpdateColliders(collidersOBB, "laberinto53", laberintoCollider53, meta->matrix);

		AbstractModel::OBB laberintoCollider54;
		glm::mat4 modelMatrixColliderLaberinto54 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider54.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto54 = glm::translate(modelMatrixColliderLaberinto54, meta->getObb().c);
		modelMatrixColliderLaberinto54 = glm::translate(modelMatrixColliderLaberinto54, glm::vec3(583.0f, 5.0f, 580.0f));
		laberintoCollider54.c = glm::vec3(modelMatrixColliderLaberinto54[3]);
		laberintoCollider54.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.6);
		addOrUpdateColliders(collidersOBB, "laberinto54", laberintoCollider54, meta->matrix);

		AbstractModel::OBB laberintoCollider55;
		glm::mat4 modelMatrixColliderLaberinto55 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider55.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto55 = glm::translate(modelMatrixColliderLaberinto55, meta->getObb().c);
		modelMatrixColliderLaberinto55 = glm::translate(modelMatrixColliderLaberinto55, glm::vec3(583.0f, 5.0f, 255.0f));
		laberintoCollider55.c = glm::vec3(modelMatrixColliderLaberinto55[3]);
		laberintoCollider55.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.6);
		addOrUpdateColliders(collidersOBB, "laberinto55", laberintoCollider55, meta->matrix);

		AbstractModel::OBB laberintoCollider56;
		glm::mat4 modelMatrixColliderLaberinto56 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider56.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto56 = glm::translate(modelMatrixColliderLaberinto56, meta->getObb().c);
		modelMatrixColliderLaberinto56 = glm::translate(modelMatrixColliderLaberinto56, glm::vec3(613.0f, 5.0f, 420.0f));
		laberintoCollider56.c = glm::vec3(modelMatrixColliderLaberinto56[3]);
		laberintoCollider56.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.8);
		addOrUpdateColliders(collidersOBB, "laberinto56", laberintoCollider56, meta->matrix);

		AbstractModel::OBB laberintoCollider57;
		glm::mat4 modelMatrixColliderLaberinto57 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider57.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto57 = glm::translate(modelMatrixColliderLaberinto57, meta->getObb().c);
		modelMatrixColliderLaberinto57 = glm::translate(modelMatrixColliderLaberinto57, glm::vec3(613.0f, 5.0f, 215.0f));
		laberintoCollider57.c = glm::vec3(modelMatrixColliderLaberinto57[3]);
		laberintoCollider57.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.7);
		addOrUpdateColliders(collidersOBB, "laberinto57", laberintoCollider57, meta->matrix);

		Model::OBB laberintoCollider58;
		glm::mat4 modelMatrixColliderLaberinto58 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider58.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto58 = glm::translate(modelMatrixColliderLaberinto58, meta->getObb().c);
		modelMatrixColliderLaberinto58 = glm::translate(modelMatrixColliderLaberinto58, glm::vec3(613.0f, 5.0f, 510.0f));
		laberintoCollider58.c = glm::vec3(modelMatrixColliderLaberinto58[3]);
		laberintoCollider58.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.15);
		addOrUpdateColliders(collidersOBB, "laberinto58", laberintoCollider58, meta->matrix);

		//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

		AbstractModel::OBB laberintoCollider59;
		glm::mat4 modelMatrixColliderLaberinto59 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider59.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto59 = glm::translate(modelMatrixColliderLaberinto59, meta->getObb().c);
		modelMatrixColliderLaberinto59 = glm::translate(modelMatrixColliderLaberinto59, glm::vec3(643.0f, 5.0f, 400.0f));
		laberintoCollider59.c = glm::vec3(modelMatrixColliderLaberinto59[3]);
		laberintoCollider59.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.0);
		addOrUpdateColliders(collidersOBB, "laberinto59", laberintoCollider59, meta->matrix);

		AbstractModel::OBB laberintoCollider60;
		glm::mat4 modelMatrixColliderLaberinto60 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider60.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto60 = glm::translate(modelMatrixColliderLaberinto60, meta->getObb().c);
		modelMatrixColliderLaberinto60 = glm::translate(modelMatrixColliderLaberinto60, glm::vec3(643.0f, 5.0f, 200.0f));
		laberintoCollider60.c = glm::vec3(modelMatrixColliderLaberinto60[3]);
		laberintoCollider60.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto60", laberintoCollider60, meta->matrix);

		Model::OBB laberintoCollider61;
		glm::mat4 modelMatrixColliderLaberinto61 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider61.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto61 = glm::translate(modelMatrixColliderLaberinto61, meta->getObb().c);
		modelMatrixColliderLaberinto61 = glm::translate(modelMatrixColliderLaberinto61, glm::vec3(643.0f, 5.0f, 510.0f));
		laberintoCollider61.c = glm::vec3(modelMatrixColliderLaberinto61[3]);
		laberintoCollider61.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.15);
		addOrUpdateColliders(collidersOBB, "laberinto61", laberintoCollider61, meta->matrix);

		AbstractModel::OBB laberintoCollider62;
		glm::mat4 modelMatrixColliderLaberinto62 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider62.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto62 = glm::translate(modelMatrixColliderLaberinto62, meta->getObb().c);
		modelMatrixColliderLaberinto62 = glm::translate(modelMatrixColliderLaberinto62, glm::vec3(673.0f, 5.0f, 580.0f));
		laberintoCollider62.c = glm::vec3(modelMatrixColliderLaberinto62[3]);
		laberintoCollider62.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.6);
		addOrUpdateColliders(collidersOBB, "laberinto62", laberintoCollider62, meta->matrix);

		AbstractModel::OBB laberintoCollider63;
		glm::mat4 modelMatrixColliderLaberinto63 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider63.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto63 = glm::translate(modelMatrixColliderLaberinto63, meta->getObb().c);
		modelMatrixColliderLaberinto63 = glm::translate(modelMatrixColliderLaberinto63, glm::vec3(673.0f, 5.0f, 370.0f));
		laberintoCollider63.c = glm::vec3(modelMatrixColliderLaberinto63[3]);
		laberintoCollider63.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.0);
		addOrUpdateColliders(collidersOBB, "laberinto63", laberintoCollider63, meta->matrix);

		AbstractModel::OBB laberintoCollider64;
		glm::mat4 modelMatrixColliderLaberinto64 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider64.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto64 = glm::translate(modelMatrixColliderLaberinto64, meta->getObb().c);
		modelMatrixColliderLaberinto64 = glm::translate(modelMatrixColliderLaberinto64, glm::vec3(703.0f, 5.0f, 530.0f));
		laberintoCollider64.c = glm::vec3(modelMatrixColliderLaberinto64[3]);
		laberintoCollider64.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto64", laberintoCollider64, meta->matrix);

		AbstractModel::OBB laberintoCollider65;
		glm::mat4 modelMatrixColliderLaberinto65 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider65.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto65 = glm::translate(modelMatrixColliderLaberinto65, meta->getObb().c);
		modelMatrixColliderLaberinto65 = glm::translate(modelMatrixColliderLaberinto65, glm::vec3(703.0f, 5.0f, 640.0f));
		laberintoCollider65.c = glm::vec3(modelMatrixColliderLaberinto65[3]);
		laberintoCollider65.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.4);
		addOrUpdateColliders(collidersOBB, "laberinto65", laberintoCollider65, meta->matrix);

		AbstractModel::OBB laberintoCollider66;
		glm::mat4 modelMatrixColliderLaberinto66 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider66.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto66 = glm::translate(modelMatrixColliderLaberinto66, meta->getObb().c);
		modelMatrixColliderLaberinto66 = glm::translate(modelMatrixColliderLaberinto66, glm::vec3(703.0f, 5.0f, 365.0f));
		laberintoCollider66.c = glm::vec3(modelMatrixColliderLaberinto66[3]);
		laberintoCollider66.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.6);
		addOrUpdateColliders(collidersOBB, "laberinto66", laberintoCollider66, meta->matrix);

		Model::OBB laberintoCollider67;
		glm::mat4 modelMatrixColliderLaberinto67 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider67.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto67 = glm::translate(modelMatrixColliderLaberinto67, meta->getObb().c);
		modelMatrixColliderLaberinto67 = glm::translate(modelMatrixColliderLaberinto67, glm::vec3(733.0f, 5.0f, 655.0f));
		laberintoCollider67.c = glm::vec3(modelMatrixColliderLaberinto67[3]);
		laberintoCollider67.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.25);
		addOrUpdateColliders(collidersOBB, "laberinto67", laberintoCollider67, meta->matrix);

		Model::OBB laberintoCollider68;
		glm::mat4 modelMatrixColliderLaberinto68 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider68.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto68 = glm::translate(modelMatrixColliderLaberinto68, meta->getObb().c);
		modelMatrixColliderLaberinto68 = glm::translate(modelMatrixColliderLaberinto68, glm::vec3(733.0f, 5.0f, 525.0f));
		laberintoCollider68.c = glm::vec3(modelMatrixColliderLaberinto68[3]);
		laberintoCollider68.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.85);
		addOrUpdateColliders(collidersOBB, "laberinto68", laberintoCollider68, meta->matrix);

		Model::OBB laberintoCollider69;
		glm::mat4 modelMatrixColliderLaberinto69 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider69.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto69 = glm::translate(modelMatrixColliderLaberinto69, meta->getObb().c);
		modelMatrixColliderLaberinto69 = glm::translate(modelMatrixColliderLaberinto69, glm::vec3(765.0f, 5.0f, 640.0f));
		laberintoCollider69.c = glm::vec3(modelMatrixColliderLaberinto69[3]);
		laberintoCollider69.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto69", laberintoCollider69, meta->matrix);

		Model::OBB laberintoCollider70;
		glm::mat4 modelMatrixColliderLaberinto70 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider70.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto70 = glm::translate(modelMatrixColliderLaberinto70, meta->getObb().c);
		modelMatrixColliderLaberinto70 = glm::translate(modelMatrixColliderLaberinto70, glm::vec3(765.0f, 5.0f, 500.0f));
		laberintoCollider70.c = glm::vec3(modelMatrixColliderLaberinto70[3]);
		laberintoCollider70.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.9);
		addOrUpdateColliders(collidersOBB, "laberinto70", laberintoCollider70, meta->matrix);

		Model::OBB laberintoCollider71;
		glm::mat4 modelMatrixColliderLaberinto71 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider71.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto71 = glm::translate(modelMatrixColliderLaberinto71, meta->getObb().c);
		modelMatrixColliderLaberinto71 = glm::translate(modelMatrixColliderLaberinto71, glm::vec3(795.0f, 5.0f, 640.0f));
		laberintoCollider71.c = glm::vec3(modelMatrixColliderLaberinto71[3]);
		laberintoCollider71.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto71", laberintoCollider71, meta->matrix);

		Model::OBB laberintoCollider72;
		glm::mat4 modelMatrixColliderLaberinto72 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider72.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto72 = glm::translate(modelMatrixColliderLaberinto72, meta->getObb().c);
		modelMatrixColliderLaberinto72 = glm::translate(modelMatrixColliderLaberinto72, glm::vec3(795.0f, 5.0f, 495.0f));
		laberintoCollider72.c = glm::vec3(modelMatrixColliderLaberinto72[3]);
		laberintoCollider72.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.3);
		addOrUpdateColliders(collidersOBB, "laberinto72", laberintoCollider72, meta->matrix);

		Model::OBB laberintoCollider73;
		glm::mat4 modelMatrixColliderLaberinto73 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider73.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto73 = glm::translate(modelMatrixColliderLaberinto73, meta->getObb().c);
		modelMatrixColliderLaberinto73 = glm::translate(modelMatrixColliderLaberinto73, glm::vec3(825.0f, 5.0f, 655.0f));
		laberintoCollider73.c = glm::vec3(modelMatrixColliderLaberinto73[3]);
		laberintoCollider73.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.3);
		addOrUpdateColliders(collidersOBB, "laberinto73", laberintoCollider73, meta->matrix);

		Model::OBB laberintoCollider74;
		glm::mat4 modelMatrixColliderLaberinto74 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider74.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto74 = glm::translate(modelMatrixColliderLaberinto74, meta->getObb().c);
		modelMatrixColliderLaberinto74 = glm::translate(modelMatrixColliderLaberinto74, glm::vec3(825.0f, 5.0f, 457.0f));
		laberintoCollider74.c = glm::vec3(modelMatrixColliderLaberinto74[3]);
		laberintoCollider74.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.4);
		addOrUpdateColliders(collidersOBB, "laberinto74", laberintoCollider74, meta->matrix);

		Model::OBB laberintoCollider75;
		glm::mat4 modelMatrixColliderLaberinto75 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider75.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto75 = glm::translate(modelMatrixColliderLaberinto75, meta->getObb().c);
		modelMatrixColliderLaberinto75 = glm::translate(modelMatrixColliderLaberinto75, glm::vec3(855.0f, 5.0f, 645.0f));
		laberintoCollider75.c = glm::vec3(modelMatrixColliderLaberinto75[3]);
		laberintoCollider75.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto75", laberintoCollider75, meta->matrix);

		Model::OBB laberintoCollider76;
		glm::mat4 modelMatrixColliderLaberinto76 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider76.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto76 = glm::translate(modelMatrixColliderLaberinto76, meta->getObb().c);
		modelMatrixColliderLaberinto76 = glm::translate(modelMatrixColliderLaberinto76, glm::vec3(855.0f, 5.0f, 437.0f));
		laberintoCollider76.c = glm::vec3(modelMatrixColliderLaberinto76[3]);
		laberintoCollider76.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.6);
		addOrUpdateColliders(collidersOBB, "laberinto76", laberintoCollider76, meta->matrix);

		Model::OBB laberintoCollider77;
		glm::mat4 modelMatrixColliderLaberinto77 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider77.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto77 = glm::translate(modelMatrixColliderLaberinto77, meta->getObb().c);
		modelMatrixColliderLaberinto77 = glm::translate(modelMatrixColliderLaberinto77, glm::vec3(885.0f, 5.0f, 657.0f));
		laberintoCollider77.c = glm::vec3(modelMatrixColliderLaberinto77[3]);
		laberintoCollider77.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.3);
		addOrUpdateColliders(collidersOBB, "laberinto77", laberintoCollider77, meta->matrix);

		Model::OBB laberintoCollider78;
		glm::mat4 modelMatrixColliderLaberinto78 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider78.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto78 = glm::translate(modelMatrixColliderLaberinto78, meta->getObb().c);
		modelMatrixColliderLaberinto78 = glm::translate(modelMatrixColliderLaberinto78, glm::vec3(885.0f, 5.0f, 408.0f));
		laberintoCollider78.c = glm::vec3(modelMatrixColliderLaberinto78[3]);
		laberintoCollider78.e = meta->getObb().e * glm::vec3(0.001, 0.05, 1.6);
		addOrUpdateColliders(collidersOBB, "laberinto78", laberintoCollider78, meta->matrix);

		Model::OBB laberintoCollider79;
		glm::mat4 modelMatrixColliderLaberinto79 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider79.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto79 = glm::translate(modelMatrixColliderLaberinto79, meta->getObb().c);
		modelMatrixColliderLaberinto79 = glm::translate(modelMatrixColliderLaberinto79, glm::vec3(915.0f, 5.0f, 642.0f));
		laberintoCollider79.c = glm::vec3(modelMatrixColliderLaberinto79[3]);
		laberintoCollider79.e = meta->getObb().e * glm::vec3(0.001, 0.05, 0.5);
		addOrUpdateColliders(collidersOBB, "laberinto79", laberintoCollider79, meta->matrix);

		Model::OBB laberintoCollider80;
		glm::mat4 modelMatrixColliderLaberinto80 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider80.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto80 = glm::translate(modelMatrixColliderLaberinto80, meta->getObb().c);
		modelMatrixColliderLaberinto80 = glm::translate(modelMatrixColliderLaberinto80, glm::vec3(915.0f, 5.0f, 400.0f));
		laberintoCollider80.c = glm::vec3(modelMatrixColliderLaberinto80[3]);
		laberintoCollider80.e = meta->getObb().e * glm::vec3(0.001, 0.05, 2.0);
		addOrUpdateColliders(collidersOBB, "laberinto80", laberintoCollider80, meta->matrix);

		Model::OBB laberintoCollider81;
		glm::mat4 modelMatrixColliderLaberinto81 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider81.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto81 = glm::translate(modelMatrixColliderLaberinto81, meta->getObb().c);
		modelMatrixColliderLaberinto81 = glm::translate(modelMatrixColliderLaberinto81, glm::vec3(947.0f, 5.0f, 435.0f));
		laberintoCollider81.c = glm::vec3(modelMatrixColliderLaberinto81[3]);
		laberintoCollider81.e = meta->getObb().e * glm::vec3(0.001, 0.05, 3.0);
		addOrUpdateColliders(collidersOBB, "laberinto81", laberintoCollider81, meta->matrix);

		Model::OBB laberintoCollider82;
		glm::mat4 modelMatrixColliderLaberinto82 = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		laberintoCollider82.u = glm::quat_cast(meta->matrix);
		//modelMatrixColliderMeta = glm::scale(modelMatrixColliderMeta, glm::vec3(0.001, 0.001, 0.001));
		modelMatrixColliderLaberinto82 = glm::translate(modelMatrixColliderLaberinto82, meta->getObb().c);
		modelMatrixColliderLaberinto82 = glm::translate(modelMatrixColliderLaberinto82, glm::vec3(977.0f, 5.0f, 445.0f));
		laberintoCollider82.c = glm::vec3(modelMatrixColliderLaberinto82[3]);
		laberintoCollider82.e = meta->getObb().e * glm::vec3(0.001, 0.05, 3.7);
		addOrUpdateColliders(collidersOBB, "laberinto82", laberintoCollider82, meta->matrix);

		//******************************************************************************************************

		// Collider de Spider
		AbstractModel::OBB spiderCollider;
		glm::mat4 modelmatrixColliderSpider = glm::mat4(modelMatrixSpider);
		modelmatrixColliderSpider = glm::rotate(modelmatrixColliderSpider,glm::radians(-90.0f), glm::vec3(1, 0, 0));
		// Set the orientation of collider before doing the scale
		spiderCollider.u = glm::quat_cast(modelmatrixColliderSpider);
		modelmatrixColliderSpider = glm::scale(modelmatrixColliderSpider, glm::vec3(0.021, 0.021, 0.021));
		modelmatrixColliderSpider = glm::translate(modelmatrixColliderSpider,glm::vec3(spiderModelAnimate.getObb().c.x,
			spiderModelAnimate.getObb().c.y,
			spiderModelAnimate.getObb().c.z + 28));
		spiderCollider.e = spiderModelAnimate.getObb().e * glm::vec3(0.04, 0.04, 0.06);
		spiderCollider.c = glm::vec3(modelmatrixColliderSpider[3]);
		addOrUpdateColliders(collidersOBB, "spider", spiderCollider, modelMatrixSpider);

		//***************************************************************************
		// Collider Monedas
		for (std::map<string, glm::mat4>::iterator it = moneda->matrices.begin(); it != moneda->matrices.end(); it++) {
			AbstractModel::SBB monedaCollider;
			glm::mat4 modelMatrixColliderMoneda = glm::mat4(it->second);
			modelMatrixColliderMoneda = glm::translate(modelMatrixColliderMoneda, glm::vec3(0.f, 0.f, 0.f));
			modelMatrixColliderMoneda = glm::translate(modelMatrixColliderMoneda, moneda->getSbb().c);
			monedaCollider.c = modelMatrixColliderMoneda[3];
			monedaCollider.ratio = moneda->getSbb().ratio;
			addOrUpdateColliders(collidersSBB, it->first, monedaCollider, it->second);
		}

		//---------------------------------------------------------------------
		// Collider Roca
		if (roca->show) {
			AbstractModel::SBB rocaCollider;
			glm::mat4 modelMatrixColliderMoneda = glm::mat4(roca->matrix);
			modelMatrixColliderMoneda = glm::translate(modelMatrixColliderMoneda, glm::vec3(0.f, -.3f, 0.f));
			modelMatrixColliderMoneda = glm::scale(modelMatrixColliderMoneda, glm::vec3(0.3f, 0.3f, 0.3f));
			modelMatrixColliderMoneda = glm::translate(modelMatrixColliderMoneda, moneda->getSbb().c);
			rocaCollider.c = modelMatrixColliderMoneda[3];
			rocaCollider.ratio = roca->getSbb().ratio * 0.3f;
			addOrUpdateColliders(collidersSBB, "roca", rocaCollider, roca->matrix);
		}
		
		//---------------------------------------------------------------------
		// Collider Eventos Roca
		AbstractModel::OBB rocaEventCollider0;
		glm::mat4 modelMatrixColliderRocaEvent = glm::mat4(meta->matrix);
		// Set the orientation of collider before doing the scale
		rocaEventCollider0.u = glm::quat_cast(meta->matrix);
		modelMatrixColliderRocaEvent = glm::translate(modelMatrixColliderRocaEvent, meta->getObb().c);
		modelMatrixColliderRocaEvent = glm::translate(modelMatrixColliderRocaEvent, glm::vec3(640.f, 5.0f, 255.f));
		rocaEventCollider0.c = glm::vec3(modelMatrixColliderRocaEvent[3]);
		rocaEventCollider0.e = meta->getObb().e * glm::vec3(0.001, .05f, .18f);
		addOrUpdateColliders(collidersOBB, "rocaEvent-0", rocaEventCollider0, meta->matrix);

		/*******************************************
		 * Render de colliders
		 *******************************************/
		for (std::map<std::string, std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> >::iterator it =
			collidersOBB.begin(); it != collidersOBB.end(); it++) {
			glm::mat4 matrixCollider = glm::mat4(1.0);
			matrixCollider = glm::translate(matrixCollider, std::get<0>(it->second).c);
			matrixCollider = matrixCollider * glm::mat4(std::get<0>(it->second).u);
			matrixCollider = glm::scale(matrixCollider, std::get<0>(it->second).e * 2.0f);
			boxCollider.setColor(glm::vec4(1.0, 1.0, 1.0, 1.0));
			boxCollider.enableWireMode();
			boxCollider.render(matrixCollider);
		}

		for (std::map<std::string, std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> >::iterator it =
			collidersSBB.begin(); it != collidersSBB.end(); it++) {
			glm::mat4 matrixCollider = glm::mat4(1.0);
			matrixCollider = glm::translate(matrixCollider, std::get<0>(it->second).c);
			matrixCollider = glm::scale(matrixCollider, glm::vec3(std::get<0>(it->second).ratio * 2.0f));
			sphereCollider.setColor(glm::vec4(1.0, 1.0, 1.0, 1.0));
			sphereCollider.enableWireMode();
			sphereCollider.render(matrixCollider);
		}

		/*******************************************
		 * Test Colisions
		 *******************************************/
		if (!isJump)
			isPlataform = false;
		for (std::map<std::string,
			std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> >::iterator it =
			collidersOBB.begin(); it != collidersOBB.end(); it++) {
			bool isCollision = false;
			for (std::map<std::string,
				std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> >::iterator jt =
				collidersOBB.begin(); jt != collidersOBB.end(); jt++) {
				if (it != jt
					&& testOBBOBB(std::get<0>(it->second),
						std::get<0>(jt->second))) {
					std::cout << "Colision " << it->first << " with "
						<< jt->first << std::endl;
					if (it->first.compare("spider") == 0){ 
						if (jt->first.compare("PuentePiso") == 0) {
							isPlataform = true;
							platformHeight = std::get<1>(jt->second)[3][1];
						}
						else if (jt->first.find("rocaEvent-") == 0) {
							roca->InitMatrices(&terrain);
							roca->show = true;
						}
						else
							isCollision = true;
					}
					
				}
			}
			addOrUpdateCollisionDetection(collisionDetection, it->first, isCollision);
		}

		for (std::map<std::string,
			std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> >::iterator it =
			collidersSBB.begin(); it != collidersSBB.end(); it++) {
			bool isCollision = false;
			for (std::map<std::string,
				std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> >::iterator jt =
				collidersSBB.begin(); jt != collidersSBB.end(); jt++) {
				if (it != jt
					&& testSphereSphereIntersection(std::get<0>(it->second),
						std::get<0>(jt->second))) {
					//std::cout << "Colision " << it->first << " with " << jt->first << std::endl;
					isCollision = true;
				}
			}
			addOrUpdateCollisionDetection(collisionDetection, it->first, isCollision);
		}

		for (std::map<std::string,
			std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> >::iterator it =
			collidersSBB.begin(); it != collidersSBB.end(); it++) {
			bool isCollision = false;
			std::map<std::string,
				std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> >::iterator jt =
				collidersOBB.begin();
			for (; jt != collidersOBB.end(); jt++) {
				if (testSphereOBox(std::get<0>(it->second),
					std::get<0>(jt->second))) {
					//std::cout << "Colision " << it->first << " with " << jt->first << std::endl;
					if (jt->first.compare("spider") == 0) {
						if (it->first.find("moneda-") == 0) {
							moneda->removeMoneda(it->first);
							collidersSBB.erase(it->first);
							sourcesPlay[4] = true;
							puntos++;
						}
						else if (it->first.compare("roca") == 0) {
							roca->show = false;
							collidersSBB.erase(it->first);
							vida--;
						}
						else
							isCollision = true;
					}
					else if (it->first.compare("roca") == 0) {
						if (jt->first.find("rocaEvent-") == 0) {
							roca->show = false;
							collidersSBB.erase(it->first);
						}
					}
					else
						isCollision = true;
					addOrUpdateCollisionDetection(collisionDetection, jt->first, isCollision);
				}
			}
			addOrUpdateCollisionDetection(collisionDetection, it->first, isCollision);
		}

		std::map<std::string, bool>::iterator colIt;
		for (colIt = collisionDetection.begin(); colIt != collisionDetection.end();
			colIt++) {
			std::map<std::string,
				std::tuple<AbstractModel::SBB, glm::mat4, glm::mat4> >::iterator it =
				collidersSBB.find(colIt->first);
			std::map<std::string,
				std::tuple<AbstractModel::OBB, glm::mat4, glm::mat4> >::iterator jt =
				collidersOBB.find(colIt->first);
			if (it != collidersSBB.end()) {
				if (!colIt->second)
					addOrUpdateColliders(collidersSBB, it->first);
			}
			if (jt != collidersOBB.end()) {
				if (!colIt->second)
					addOrUpdateColliders(collidersOBB, jt->first);
				else {
					if (jt->first.compare("spider") == 0) {
						modelMatrixSpider = std::get<1>(jt->second);
					}
				}
			}
		}

		glfwSwapBuffers(window);


		/****************************+
		 * Open AL sound data
		 */
		
		source0Pos[0] = doubleTap->matrix[3].x;
		source0Pos[1] = doubleTap->matrix[3].y;
		source0Pos[2] = doubleTap->matrix[3].z;
		alSourcefv(source[0], AL_POSITION, source0Pos);

		source1Pos[0] = juggerNog->matrix[3].x;
		source1Pos[1] = juggerNog->matrix[3].y;
		source1Pos[2] = juggerNog->matrix[3].z;
		alSourcefv(source[1], AL_POSITION, source1Pos);

		source2Pos[0] = quickRevive->matrix[3].x;
		source2Pos[1] = quickRevive->matrix[3].y;
		source2Pos[2] = quickRevive->matrix[3].z;
		alSourcefv(source[2], AL_POSITION, source2Pos);

		source3Pos[0] = speedCola->matrix[3].x;
		source3Pos[1] = speedCola->matrix[3].y;
		source3Pos[2] = speedCola->matrix[3].z;
		alSourcefv(source[3], AL_POSITION, source3Pos);

		source4Pos[0] = modelMatrixSpider[3].x;
		source4Pos[1] = modelMatrixSpider[3].y;
		source4Pos[2] = modelMatrixSpider[3].z;
		alSourcefv(source[4], AL_POSITION, source4Pos);

		// Listener for the Thris person camera
		listenerPos[0] = modelMatrixSpider[3].x;
		listenerPos[1] = modelMatrixSpider[3].y;
		listenerPos[2] = modelMatrixSpider[3].z;
		alListenerfv(AL_POSITION, listenerPos);

		glm::vec3 upModel = glm::normalize(modelMatrixSpider[1]);
		glm::vec3 frontModel = glm::normalize(modelMatrixSpider[2]);

		listenerOri[0] = frontModel.x;
		listenerOri[1] = frontModel.y;
		listenerOri[2] = frontModel.z;
		listenerOri[3] = upModel.x;
		listenerOri[4] = upModel.y;
		listenerOri[5] = upModel.z;

		// Listener for the First person camera
		/*listenerPos[0] = camera->getPosition().x;
		listenerPos[1] = camera->getPosition().y;
		listenerPos[2] = camera->getPosition().z;
		alListenerfv(AL_POSITION, listenerPos);
		listenerOri[0] = camera->getFront().x;
		listenerOri[1] = camera->getFront().y;
		listenerOri[2] = camera->getFront().z;
		listenerOri[3] = camera->getUp().x;
		listenerOri[4] = camera->getUp().y;
		listenerOri[5] = camera->getUp().z;*/
		alListenerfv(AL_ORIENTATION, listenerOri);

		for (unsigned int i = 0; i < sourcesPlay.size(); i++) {
			if (sourcesPlay[i]) {
				sourcesPlay[i] = false;
				alSourcePlay(source[i]);
			}
		}
	}
}

void prepareScene() {

	skyboxSphere.setShader(&shaderSkybox);

	models->prepareModels(&shaderMulLighting);

	terrain.setShader(&shaderTerrain);

	//Mayow
	spiderModelAnimate.setShader(&shaderMulLighting);
}

void prepareDepthScene() {

	skyboxSphere.setShader(&shaderDepth);

	terrain.setShader(&shaderDepth);

	models->prepareModels(&shaderDepth);

	//Mayow
	spiderModelAnimate.setShader(&shaderDepth);
}

void renderScene(bool renderParticles) {
	/*******************************************
	 * Terrain Cesped
	 *******************************************/
	glm::mat4 modelCesped = glm::mat4(1.0);
	modelCesped = glm::translate(modelCesped, glm::vec3(0.0, 0.0, 0.0));
	modelCesped = glm::scale(modelCesped, glm::vec3(200.0, 0.001, 200.0));
	// Se activa la textura del background
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureTerrainBackground->id);
	shaderTerrain.setInt("backgroundTexture", 0);
	// Se activa la textura de tierra
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureTerrainR->id);
	shaderTerrain.setInt("rTexture", 1);
	// Se activa la textura de hierba
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, textureTerrainG->id);
	shaderTerrain.setInt("gTexture", 2);
	// Se activa la textura del camino
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, textureTerrainB->id);
	shaderTerrain.setInt("bTexture", 3);
	// Se activa la textura del blend map
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, textureTerrainBlendMap->id);
	shaderTerrain.setInt("blendMapTexture", 4);
	shaderTerrain.setVectorFloat2("scaleUV", glm::value_ptr(glm::vec2(40, 40)));
	terrain.render();
	shaderTerrain.setVectorFloat2("scaleUV", glm::value_ptr(glm::vec2(0, 0)));
	glBindTexture(GL_TEXTURE_2D, 0);

	/*******************************************
	 * Custom objects obj
	 *******************************************/
	// Forze to enable the unit texture to 0 always ----------------- IMPORTANT
	//glActiveTexture(GL_TEXTURE0);

	models->updateModels();
	models->renderModels();

	/*******************************************
	 * Custom Anim objects obj
	 *******************************************/
	float altura;
	altura = isPlataform ? platformHeight : terrain.getHeightTerrain(modelMatrixSpider[3][0], modelMatrixSpider[3][2]);
	modelMatrixSpider[3][1] = -GRAVITY * tmv * tmv + 3.5 * tmv + altura;
	tmv = currTime - startTimeJump;
	if (modelMatrixSpider[3][1] < altura) {
		isJump = false;
		modelMatrixSpider[3][1] = altura;
	}
	glm::mat4 modelMatrixSpiderBody = glm::mat4(modelMatrixSpider);
	modelMatrixSpiderBody = glm::scale(modelMatrixSpiderBody, glm::vec3(0.0006, 0.0006, 0.0006));
	spiderModelAnimate.setAnimationIndex(animationIndex);
	spiderModelAnimate.render(modelMatrixSpiderBody);

	/**********
	 * Render de las transparencias
	 */
	models->renderBlending(camera);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	for (int i = 0; i < casita->matrices.size(); i++) {
		if (casita->casas[i].fire) {
			/**********
			 * Init Render particles systems
			 */
			lastTimeParticlesAnimationFire = currTimeParticlesAnimationFire;
			currTimeParticlesAnimationFire = TimeManager::Instance().GetTime();

			shaderParticlesFire.setInt("Pass", 1);
			shaderParticlesFire.setFloat("Time", currTimeParticlesAnimationFire);
			shaderParticlesFire.setFloat("DeltaT", currTimeParticlesAnimationFire - lastTimeParticlesAnimationFire);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_1D, texId);
			glEnable(GL_RASTERIZER_DISCARD);
			glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, feedback[drawBuf]);
			glBeginTransformFeedback(GL_POINTS);
			glBindVertexArray(particleArray[1 - drawBuf]);
			glVertexAttribDivisor(0, 0);
			glVertexAttribDivisor(1, 0);
			glVertexAttribDivisor(2, 0);
			glDrawArrays(GL_POINTS, 0, nParticlesFire);
			glEndTransformFeedback();
			glDisable(GL_RASTERIZER_DISCARD);

			shaderParticlesFire.setInt("Pass", 2);
			//modelFireParticles = glm::translate(modelFireParticles, glm::vec3(6.9f, 8.65f, -10.3f));
			glm::mat4 modelFireParticles = glm::translate(casita->matrices[i], glm::vec3(0.54f, 2.25f, 0.1f));
			modelFireParticles = glm::scale(modelFireParticles, glm::vec3(0.33f));
			shaderParticlesFire.setMatrix4("model", 1, false, glm::value_ptr(modelFireParticles));
			shaderParticlesFire.setVectorFloat3("colorHumo", glm::value_ptr(glm::vec3(0.f)));

			shaderParticlesFire.turnOn();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textureParticleFire->id);
			glDepthMask(GL_FALSE);
			glBindVertexArray(particleArray[drawBuf]);
			glVertexAttribDivisor(0, 1);
			glVertexAttribDivisor(1, 1);
			glVertexAttribDivisor(2, 1);
			glDrawArraysInstanced(GL_TRIANGLES, 0, 6, nParticlesFire);
			glBindVertexArray(0);
			glDepthMask(GL_TRUE);
			drawBuf = 1 - drawBuf;
			shaderParticlesFire.turnOff();
		}
	}
	/****************************+
			 * Open AL sound data
			 */
			 //source1Pos[0] = modelFireParticles[3].x;
			 //source1Pos[1] = modelFireParticles[3].y;
			 //source1Pos[2] = modelFireParticles[3].z;
			 //alSourcefv(source[1], AL_POSITION, source1Pos);
				
			 /**********
			  * End Render particles systems
			  */
	glEnable(GL_CULL_FACE);
}

int main(int argc, char **argv) {
	init(800, 700, "MarioCraft v2", false);
	applicationLoop();
	destroy();
	return 1;
}
