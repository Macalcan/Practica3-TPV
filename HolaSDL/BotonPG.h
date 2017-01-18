#pragma once
#include "ObjetoPG.h"
class BotonPG : public ObjetoPG
{
public:
	BotonPG(juegoPG* jueg, juegoPG::Texturas_t texturas, int px, int py);
	typedef void CallBack_t(juegoPG* jg);
	bool onClick();
	~BotonPG();
};

