#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class PremioPG : public ObjetoPG
{
public:
	PremioPG(juegoPG* juego, Texturas_t texturas, int px, int py);
	~PremioPG();


	
	bool onClick();

	int getPuntos();
	

private:
	void reiniciaPremio();
	
	int puntosIni;
	int puntos;
	int intento;
};

