#pragma once
#include "ObjetoPG.h"
class BotonPG : public ObjetoPG
{
public:
	typedef void CallBack_t(juegoPG* jg);

	BotonPG(juegoPG* juego, CallBack_t * cb, Texturas_t texturas, int px, int py);
	bool onClick();
	CallBack_t * cbOnClick;
	
	~BotonPG();
};

