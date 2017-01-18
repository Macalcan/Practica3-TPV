#include "GameOverPG.h"
#include "juegoPG.h"
#include "BotonPG.h"


GameOverPG::GameOverPG(juegoPG* ju) : EstadoPG(ju)
{
	int x = 450 / 2;
	int y = 450 / 2;
	
	objetos.emplace_back(new BotonPG(game, showScore, TScore, x, y));
	objetos.emplace_back(new BotonPG(game, menu, TMenu, x, y + 100));
}


GameOverPG::~GameOverPG()
{
	delete objetos[0];
	objetos[0] = nullptr;
	delete objetos[1];
	objetos[1] = nullptr;
}
