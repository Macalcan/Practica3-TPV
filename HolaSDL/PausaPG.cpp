#include "PausaPG.h"



PausaPG::PausaPG(juegoPG* juego) : EstadoPG(juego)
{
	
	initObjetos();
}

void PausaPG::initObjetos(){
	 x = 450 / 2;
	 y = 450 / 2;
	objetos.emplace_back(new BotonPG(juego, TMenu,x, y, menu));
	x = 450 / 2;
	y = 450 / 2 + 100;
	objetos.emplace_back(new BotonPG(juego, TResume, x, y, jugar));
}
PausaPG::~PausaPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
