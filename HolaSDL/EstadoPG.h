#pragma once
#include "EstadoJuego.h"
#include "juegoPG.h"
#include "ObjetoJuego.h"

class EstadoPG : public EstadoJuego
{
public:
	EstadoPG();
	EstadoPG(juegoPG* ju);
	virtual bool onClick();
	virtual void update();
	virtual void draw();
	~EstadoPG();
protected:
	int x;
	int y;
	juegoPG* juego;
	vector <ObjetoJuego*> objetos; //array de los objetos
};

