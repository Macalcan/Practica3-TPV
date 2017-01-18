#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"

class ObjetoPG : public ObjetoJuego
{
public:

	ObjetoPG();
	ObjetoPG(juegoPG* jueg, Texturas_t texturas, int px, int py);
	virtual ~ObjetoPG();

	virtual void draw();
	virtual bool onClick();
	bool visible;
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG

protected:
	
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* juego;
	SDL_Rect rectObjeto;
	Texturas_t texturasa;
};

