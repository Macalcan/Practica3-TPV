#include "Gamefactory2.h"
#include "BouncingBall.h"
#include "Vago.h"

Gamefactory2::Gamefactory2(juegoPG* juego)
{
	ju = juego;
}

ObjetoJuego* Gamefactory2::createNormalElement(int i){
	x = rand() % 450;
	y = rand() % 450;
	return new BouncingBall(ju, TPelota, x, y);

}

ObjetoJuego* Gamefactory2::createSpecialElement(){
	return new  Vago(ju, TPelota, 0, 0); //REVISAR, ver como crear vago sin una textura

}

ObjetoJuego* Gamefactory2::createPrizeElement(){

	return new Vago(ju, TPelota, 0, 0);

}


Gamefactory2::~Gamefactory2()
{
}
