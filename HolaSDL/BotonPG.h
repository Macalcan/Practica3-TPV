#ifndef _H_BotonPG_H
#define _H_BotonPG_H
#pragma once
#include "ObjetoPG.h"
class BotonPG : public ObjetoPG
{
public:
	typedef void CallBack_t(juegoPG* jg);

	BotonPG(juegoPG* juego, CallBack_t * cb, Texturas_t texturas, int px, int py);
	bool onClick();
	~BotonPG();

protected:
	CallBack_t * cbOnClick;
	
	
};
#endif

