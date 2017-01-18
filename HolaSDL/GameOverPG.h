#ifndef _H_GameOverPG_H_
#define _H_GameOverPG_H_
#pragma once
#include "EstadoPG.h"
#include "MenuPG.h"
#include "juegoPG.h"
#include "PlayPg.h"
class GameOverPG : public EstadoPG
{
	
public:
	GameOverPG(juegoPG* ju, int p);
	~GameOverPG();
	
private:
	static int puntos;
	void initObjetos();
	static void showScore(juegoPG* jug) {
		string puntuacion = "Puntuacion: ";
		puntuacion += to_string(puntos);
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Has terminado!!", puntuacion.c_str(), nullptr);
	} 
	static void menu(juegoPG* jug) { jug->stateChange(new MenuPG(jug)); }
	
};
#endif

