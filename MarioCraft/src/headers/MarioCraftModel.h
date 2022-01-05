#pragma once
#include "libs.h"

enum MCenum { DEPTH, COLL_OBB, COLL_SBB };

using  namespace std;

class MarioCraftModel : public Model {
private:
	string rutaObj;
public:
	bool normalRender = true;
	bool depth;
	bool collider;
	union {
		AbstractModel::OBB * OBB;
		AbstractModel::SBB * SBB;
	} coll;
	glm::mat4 matrix;

	MarioCraftModel();
	~MarioCraftModel();
	MarioCraftModel* Init(glm::mat4);
	MarioCraftModel* Rotate(float, float, float, float);
	MarioCraftModel* Translate(float, float, float);
	MarioCraftModel* Scale(float, float, float);
	virtual void Render();
	virtual void keyboardInput();
	virtual void animate();
	void setShader(Shader*);
	void mcEnable(MCenum);
};