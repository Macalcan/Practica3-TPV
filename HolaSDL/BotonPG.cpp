#include "BotonPG.h"


BotonPG::BotonPG(juegoPG* juego, Texturas_t texturas, int px, int py, CallBack_t * cb) : ObjetoPG(juego, texturas, px, py)
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


