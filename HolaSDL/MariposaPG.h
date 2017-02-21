#ifndef _H_MariposaPG_H
#define _H_MariposaPG_H
#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class MariposaPG : public ObjetoPG
{
public:
	MariposaPG(juegoPG* juego, Texturas_t texturas, int px, int py);
	void draw();
	void update();
	bool onClick();
	~MariposaPG();

private: 
	int contClicks;
	int frame;
	int frameActual;
	SDL_Rect RFrame;
	SDL_Rect rectMarip;
	
	int posx, posy;
};
#endif

