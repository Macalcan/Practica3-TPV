#include "GameOverPG.h"
#include "juegoPG.h"
#include "BotonPG.h"


GameOverPG::GameOverPG(juegoPG* ju) : EstadoPG(ju)
{
	x = 450 / 2;
	y = 450 / 2 + 100;
	
	
}
void GameOverPG::initObjetos(){
	objetos.emplace_back(new BotonPG(juego, TScore, x, y, showScore));
	objetos.emplace_back(new BotonPG(juego, TMenu, x, y, menu));
}

GameOverPG::~GameOverPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
