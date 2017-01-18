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
	virtual bool onClick();
	virtual void update();
	virtual void draw();
	juegoPG* game;
	vector <ObjetoJuego*> objetos; //array de los objetos
};

