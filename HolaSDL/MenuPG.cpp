#include "MenuPG.h"
#include "BotonPG.h"

MenuPG::MenuPG(juegoPG* juego) : EstadoPG(juego)
{
	 
	initObjetos();
}

void MenuPG::initObjetos(){
	x = 450 / 2;
	y = 450 / 2;
	objetos.emplace_back(new BotonPG(juego, TPlay, x, y, jugar));
	x = 450 / 2;
	y = 450 / 2 + 150;
	objetos.emplace_back(new BotonPG(juego, TExit, x, y, salir));
	x = 450 / 2;
	y = 450 / 2 + 250;
	objetos.emplace_back(new BotonPG(juego, TExit, x, y, config));
}
MenuPG::~MenuPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
	/*delete objetos[2];
	objetos[2] = nullptr;*/
}

