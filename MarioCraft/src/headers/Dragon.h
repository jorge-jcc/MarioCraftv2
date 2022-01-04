#pragma once
#include "libs.h"
#include "MarioCraftModel.h"

/*
* Dragon:
* Esta clase genera la animacion de Ender dragon (Minecraft). La animacion
* consiste en el ender aleteando (subiendo y bajando), escupiendo cubos de
* lava cada cierto tiempo (generaci�n aleatoria). y Moviendose por el escenario
* seg�n los estados indicados.
*
* Existen 2 m�todos para agregar los estados de la animaci�n
*   - addEstadoAnimacion(Desplazamiento, float = 0, float = 0)
*       Recibe cada estado a ejecutar, el tama�o del incremento o diferencial
*       y el limite o n�mero unidades a moverse en total.
*   - setEstadosAnimacion(vector<AnimacionBrincar>)
*       Recibe un vector de tipo AnimacionBrincar que puede corresponder al de
*       otro modelo JumpAnimation, en este caso, la animacion ser� exactamente
*       igual a la del modelo base.
*/


// Desplazamiento es una enumeracion que corresponde con los posibles estados 
// de la animaci�n.
// Los puntos cardinales coinciden con la proyeccion del plano xz:
//  - NORTE -> -z
//  - SUR   ->  z
//  - ESTE  ->  x
//  - OESTE -> -x
enum class MoviemientosDragon {
	INICIO, FIN,
	NORTE, SUR, ESTE, OESTE,
	GIRO_DERECHA, GIRO_IZQUIERDA
};

class Dragon : public MarioCraftModel {
private:
	MarioCraftModel* cuerpo;
	MarioCraftModel* cabeza;
	MarioCraftModel* colaParte1;
	MarioCraftModel* colaParte2;
	MarioCraftModel* colaParte3;
	MarioCraftModel* colaParte4;
	MarioCraftModel* magmaCube;
	MarioCraftModel* musloAlaDerecha;
	MarioCraftModel* musloAlaIzquierda;
	MarioCraftModel* alaDerecha;
	MarioCraftModel* alaIzquierda;
	MarioCraftModel* bocaSuperior;
	MarioCraftModel* bocaInferior;
	MarioCraftModel* musloDerecho;
	MarioCraftModel* piernaDerecha;
	MarioCraftModel* pataDerecha;
	MarioCraftModel* musloIzquierdo;
	MarioCraftModel* piernaIzquierda;
	MarioCraftModel* pataIzquierda;
	MarioCraftModel* manoDerecha;
	MarioCraftModel* manoIzquierda;

	typedef struct {
		MoviemientosDragon estado;
		float delta;
		float limite;
	} Animacion;

	enum class Alas {
		INICIO, ALETEAR_ARRIBA, ALETEAR_ABAJO
	};
	enum class Boca {
		INICIO, BAJAR, ABRIR, CERRAR, SUBIR, IZQUIERDA, DERECHA, CENTRO
	};
	enum class Magma {
		INICIO, LANZAR, ELIMINAR, ACTUALIZAR
	};
	Alas estadoAlas = Alas::INICIO;
	int i = 0; // Posicion actual del vector de animaciones
	Animacion estadoAnimacion;
	Boca estadoBoca = Boca::INICIO;
	Magma estadoMagma = Magma::INICIO;
	float anguloMuslo;
	float anguloAla;
	float anguloGiro;
	float deltaGiro;
	float anguloVerticalCabeza = 0.f;
	float anguloHorizontalCabeza = 0.f;
	float anguloBoca = 0.f;
	float anguloColaX, anguloColaY;
	float deltaX, deltaZ;
	float xInit, yInit, zInit;
	float yRotInit;
	float desplazamientoX, desplazamientoY, desplazamientoZ;
	float magmaY;
	glm::mat4 magmaAux;
	float anguloMusloPiernas;
	float anguloPiernas;
	float anguloPatas;
	float anguloManos;
public:
	vector<Animacion> animaciones;
	Dragon(string rutaObj, Shader*, float, float, float, float = 0.f);
	void animate() override;
	void Render() override;
	void update();
	void siguienteMovimiento();
	Dragon* addEstadoAnimacion(MoviemientosDragon, float = 0, float = 0);
	void setEstadosAnimacion(vector<Animacion>);
};

