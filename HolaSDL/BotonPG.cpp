#include "BotonPG.h"
#ifndef _H_BotonPG_H
#define _H_BotonPG_H

BotonPG::BotonPG(juegoPG* juego, CallBack_t * cb, juegoPG::Texturas_t texturas, int px, int py) : ObjetoPG(juego, texturas, px, py)
{
	visible = true; //suponemos que se crea el boton al crear el estado por lo tanto es visible de forma inicial
	rectObjeto.h = rectObjeto.w = 100;
	cbOnClick = cb;
}

bool BotonPG::onClick(){
	if (ObjetoPG::onClick()){
		cbOnClick(juego);
		return true;
	}
	else
		return false;
}
BotonPG::~BotonPG()
{
}

#endif
