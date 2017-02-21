#ifndef _H_PausaPG_H
#define _H_PausaPG_H
#pragma once
#include "EstadoPG.h"
#include "juegoPG.h"
#include "BotonPG.h"
#include "MenuPG.h"
class PausaPG : public EstadoPG
{
public:
	PausaPG(juegoPG* juego);
	~PausaPG();
protected:
	void initObjetos();
	BotonPG* boton;
	static void menu(juegoPG* jug) { jug->stateChange(new MenuPG(jug)); }
	static void jugar(juegoPG* jug) { jug->popState(); }
	
};
#endif

