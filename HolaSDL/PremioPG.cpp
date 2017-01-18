#ifndef _H_PremioPG_H
#define _H_PremioPG_H
#include "PremioPG.h"
#include "PlayPG.h"
PremioPG::PremioPG(juegoPG* jueg, Texturas_t texturas, int px, int py) : ObjetoPG(jueg, texturas, px, py)
{
	
	rectObjeto.w = rectObjeto.h = 50;
	puntosIni = puntos = 15;
	intento = 3;
	

}


//--------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------//
bool PremioPG::onClick() {
	
	if (ObjetoPG::onClick()) {
		if (dynamic_cast<PlayPG*>(juego->topState())) {
			dynamic_cast<PlayPG*>(juego->topState())->newPuntos(this);
			dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);
		}
		
		reiniciaPremio();
		//visible = false;
		return true;
	}

	else if (intento > 0) {
		
		intento--;
		puntos -= 5;
		if(intento == 0){
			if (dynamic_cast<PlayPG*>(juego->topState())) 
				dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);
			reiniciaPremio();
		}
		return false;
	}

	//else return false;
}
//--------------------------------------------------------------------------------//
//getter de puntos del globo
int PremioPG::getPuntos() {
	return puntos;
}
void PremioPG::reiniciaPremio() {
	puntos = puntosIni;
	intento = 3;
	rectObjeto.x = rand() % 450;
	rectObjeto.y = rand() % 450;
	visible = false;
}

PremioPG::~PremioPG()
{
}
#endif