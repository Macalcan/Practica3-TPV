#include "BouncingBall.h"
#include "PlayPG.h"

BouncingBall::BouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py) : ObjetoPG(jueg, texturas, px, py)
{
	rectObjeto.h = rectObjeto.w = 50; //dimension de la pelota
	dx = rand() % 100 - 90; //rebote aleatorio inicial
	dy = rand() % 100 - 90;
	visible = true;
	puntos = rand() % 100 + 50;
	explotado = false;
}

bool BouncingBall::onClick(){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen

	if (ObjetoPG::onClick() && !explotado){
		visible = false;
		explotado = true;
		if (dynamic_cast<PlayPG*>(juego->topState())) {
			dynamic_cast<PlayPG*>(juego->topState())->newPuntos(this);
			dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);
		}
		return true;
	}
	else return false;
	
}

void BouncingBall::update(){
	rectObjeto.x += dx;
	rectObjeto.y += dy;

	if (rectObjeto.x >= 450 || rectObjeto.x <= 30){
		dx = -dx;
		if(puntos > 0)
			puntos -= 10;
	}
	if (rectObjeto.y >= 550 || rectObjeto.y <= 30){
		dy = -dy;
		if (puntos > 0)
			puntos -= 10;
	}
	
}

int BouncingBall::getPuntos(){
	return puntos;
}

BouncingBall::~BouncingBall()
{
}
