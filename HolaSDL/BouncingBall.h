#pragma once
#include "ObjetoPG.h"
class BouncingBall : public ObjetoPG
{
public:
	BouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py);
	int getPuntos();
	~BouncingBall();
protected:
	int dx; //valores aleatorios de rebote
	int dy;
	int puntos;
	virtual bool onClick();
	bool explotado;
	virtual void update();
};

