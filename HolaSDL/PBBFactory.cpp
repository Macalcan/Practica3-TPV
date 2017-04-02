#include "PBBFactory.h"
#include "ProgrammableBouncingBall.h"
#include "Vago.h"

PBBFactory::PBBFactory(juegoPG* ju)
{
	juego = ju;
}

ObjetoJuego* PBBFactory::createNormalElement(int i){
	int x = rand() % 450;
	int y = rand() % 450;
	//if (i % 2 == 0)
		//return new ProgrammableBouncingBall(juego, TPelota, x, y, "prog1.vm");
	//else 
		return new ProgrammableBouncingBall(juego, TPelota, x, y, "prog2.vm");
}

ObjetoJuego* PBBFactory::createSpecialElement(){
	return new  Vago(juego, TPelota, 0, 0);

}

ObjetoJuego* PBBFactory::createPrizeElement(){

	return new Vago(juego, TPelota, 0, 0);

}
PBBFactory::~PBBFactory()
{
}
