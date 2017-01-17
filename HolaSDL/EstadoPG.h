#pragma once
#include "EstadoJuego.h"
#include "juegoPG.h"
#include "ObjetoJuego.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG();
	~EstadoPG();
protected:
	juegoPG* game;
	vector <ObjetoJuego*> objetos; //array de los objetos
};

