#ifndef _H_MenuPG_H
#define _H_MenuPG_H

#include "MenuPG.h"
#include "BotonPG.h"

MenuPG::MenuPG(juegoPG* juego) : EstadoPG(juego)
{
	 x = 450 / 2;
	 y = 450 / 2 + 100;
	initObjetos();
}

void MenuPG::initObjetos(){
	objetos.emplace_back(new BotonPG(juego, TExit, x, y, salir(juego)));
	objetos.emplace_back(new BotonPG(juego, TPlay, x, y, jugar(juego)));
}
MenuPG::~MenuPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
#endif
