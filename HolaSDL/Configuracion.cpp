#include "Configuracion.h"
#include "MenuPG.h"

static void globos(juegoPG* jug){ jug->setFactoria(FGlobos); jug->stateChange(new MenuPG(jug)); }
static void bBalls(juegoPG* jug){ jug->setFactoria(FBouncingBalls); jug->stateChange(new MenuPG(jug)); }
static void pbb(juegoPG* jug){ jug->setFactoria(FPBB); jug->stateChange(new MenuPG(jug)); }

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
	x = 450 / 2;
	y = 450 / 2 + 250;
	objetos.emplace_back(new BotonPG(juego, TExit, x, y, pbb));
}

Configuracion::~Configuracion()
{
	/*delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;*/
}

