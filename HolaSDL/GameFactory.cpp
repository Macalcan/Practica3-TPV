#include "GameFactory.h"
#include "GlobosPG.h"
#include "MariposaPG.h"
#include "PremioPG.h"
#include "BouncingBall.h"
#include "Vago.h"
#include "GloboA.h"

GameFactory::GameFactory(char types, juegoPG* juego)
{
	type = types;
	ju = juego;
}

ObjetoJuego* GameFactory::createNormalElement(int i){
	x = rand() % 450;
	y = rand() % 450;
	if (i % 2 == 0)
		return new GlobosPG(ju, TGloboN, x, y);
	else 
		return new GloboA(ju, TGloboM, x, y);
	/*else if (type == 'a')
		return new GloboA(juego, TGloboM, x, y);
	else 
		return new BouncingBall(juego, TPelota, x, y);*/
}

ObjetoJuego* GameFactory::createSpecialElement (){
	x = rand() % 450;
	y = rand() % 450;
	
	return new  MariposaPG(ju, Tmariposa, x, y);
	
	/*else if(type == 'v')
		return new Vago();*/
}

ObjetoJuego* GameFactory::createPrizeElement(){
	x = rand() % 450;
	y = rand() % 450;
	
	return new PremioPG(ju, Tpremio, x, y);
	
	/*else if (type == 'v')
		return new Vago();*/
}

GameFactory::~GameFactory()
{
}
