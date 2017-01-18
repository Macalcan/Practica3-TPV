#include "PausaPG.h"



PausaPG::PausaPG(juegoPG* juego) : EstadoPG(juego)
{
	int x = 450 / 2;
	int y = 450 / 2;
	initObjetos();
}

void PausaPG::initObjetos(){
	objetos.emplace_back(new BotonPG(juego, menu, TMenu, x, y));
	objetos.emplace_back(new BotonPG(juego, jugar, TResume, x, y + 100));
}
PausaPG::~PausaPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
