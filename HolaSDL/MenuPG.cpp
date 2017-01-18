#ifndef _H_MenuPG_H
#define _H_MenuPG_H

#include "MenuPG.h"
#include "BotonPG.h"

MenuPG::MenuPG(juegoPG* juego) : EstadoPG(juego)
{

	int x = 450 / 2;
	int y = 450 / 2;
	objetos.emplace_back(new BotonPG(game, salir(game), TBoton, x, y));
	objetos.emplace_back(new BotonPG(game, jugar(game), TBoton2, x, y + 100));
}


MenuPG::~MenuPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
#endif
