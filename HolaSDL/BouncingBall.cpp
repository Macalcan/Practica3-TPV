#include "BouncingBall.h"


BouncingBall::BouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py) : ObjetoPG(jueg, texturas, px, py)
{
	rectObjeto.h = rectObjeto.w = 50; //dimension de la pelota
	dx = 20;//rand() % 20 - 20; //rebote aleatorio inicial
	dy = -20;//rand() % 20 - 20;
	visible = true;
}

void BouncingBall::update(){
	rectObjeto.x = rectObjeto.x + dx;
	rectObjeto.y = rectObjeto.x + dy;

	if (rectObjeto.x >= 500|| rectObjeto.x <= 10)
		dx = -dx;
	if (rectObjeto.y >= 600 || rectObjeto.y <= 10)
		dy = -dy;
	
}


BouncingBall::~BouncingBall()
{
}
