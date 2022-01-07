#pragma once
#include "libs.h"
#include "MarioCraftModel.h"
enum tipoCasa { ROJA, AZUL };

typedef struct {
	tipoCasa tipo;
	float X;
	float Z;
	float rot;
	bool fire;
} CasaToad;

class CasasToad : public MarioCraftModel {
private:
public:
	MarioCraftModel* casaRoja = new MarioCraftModel();
	MarioCraftModel* casaAzul = new MarioCraftModel();

	vector<glm::mat4> matrices;
	vector<CasaToad> casas;

	CasasToad();
	~CasasToad() override;
	void Load(vector<CasaToad> casas, Shader* shader);
	void InitMatrices(Terrain *);
	void Render() override;
	void setShader(Shader*) override;
	static CasaToad newCasa(tipoCasa tipo, float X, float Z, float rot);
};

