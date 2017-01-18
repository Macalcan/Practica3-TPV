#ifndef _H_GameOverPG_H_
#define _H_GameOverPG_H_
#pragma once
#include "EstadoPG.h"
#include "MenuPG.h"
#include "juegoPG.h"
class GameOverPG : public EstadoPG
{
public:
	GameOverPG(juegoPG* ju);
	~GameOverPG();
protected:
	void initObjetos();
	static void showScore(juegoPG* jug) { int puntos = 59; } //REVISAR
	static void menu(juegoPG* jug) { jug->stateChange(new MenuPG(jug)); }
	
};
#endif

