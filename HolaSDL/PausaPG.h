#pragma once
#include "EstadoPG.h"
#include "juegoPG.h"
#include "BotonPG.h"
#include "MenuPG.h"
class PausaPG : public EstadoPG
{
public:
	PausaPG(juegoPG* juego);
	BotonPG* boton;
	static void menu(juegoPG* jug) { jug->stateChange(new MenuPG(jug); }
	static void jugar(juegoPG* jug) { jug->popState(); }
	~PausaPG();
};

