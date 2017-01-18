#pragma once
#include "EstadoPG.h"
#include "MenuPG.h"
#include "juegoPG.h"
class GameOverPG : public EstadoPG
{
public:
	GameOverPG(juegoPG* ju);
	static void showScore(juegoPG* jug) { int puntos = jug->getPuntos(); }
	static void menu(juegoPG* jug) { jug->stateChange(new MenuPG(jug)); }
	~GameOverPG();
};

