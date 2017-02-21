#pragma once
#include "ObjetoPG.h"
class BouncingBall : public ObjetoPG
{
public:
	BouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py);

	~BouncingBall();
protected:
	int dx; //valores aleatorios de rebote
	int dy;

	virtual void update();
};

