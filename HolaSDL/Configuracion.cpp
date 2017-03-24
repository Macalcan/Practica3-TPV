#include "Configuracion.h"


Configuracion::Configuracion(juegoPG* juego) : EstadoPG(juego)
{
	initObjetos();
}

void Configuracion::initObjetos(){
	x = 450 / 2;
	y = 450 / 2;
	objetos.emplace_back(new BotonPG(juego, TPlay, x, y, globos));
	x = 450 / 2;
	y = 450 / 2 + 150;
	objetos.emplace_back(new BotonPG(juego, TExit, x, y, bBalls));
}

Configuracion::~Configuracion()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
