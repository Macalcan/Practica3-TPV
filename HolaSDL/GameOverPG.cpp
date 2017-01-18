#include "GameOverPG.h"
#include "juegoPG.h"
#include "BotonPG.h"

static int puntos = 0;

GameOverPG::GameOverPG(juegoPG* ju, int p) : EstadoPG(ju)
{
	puntos = p;
	initObjetos();
}
void GameOverPG::initObjetos(){
	x = 450 / 2;
	y = 450 / 2;
	objetos.emplace_back(new BotonPG(juego, TMenu, x, y, menu));
	x = 450 / 2;
	y = 450 / 2 + 100;
	objetos.emplace_back(new BotonPG(juego, TScore, x, y, showScore));
	
}

GameOverPG::~GameOverPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
