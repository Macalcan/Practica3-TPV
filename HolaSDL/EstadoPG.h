#pragma once
#include "EstadoJuego.h"
#include "juegoPG.h"
#include "ObjetoJuego.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG();
	EstadoPG(juegoPG* ju);
	~EstadoPG();
protected:
	bool onClick();
	void update();

	juegoPG* game;
	vector <ObjetoJuego*> objetos; //array de los objetos
};

