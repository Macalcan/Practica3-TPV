#include "GameFactory.h"
#include "GlobosPG.h"
#include "MariposaPG.h"
#include "PremioPG.h"
#include "BouncingBall.h"
#include "Vago.h"
#include "GloboA.h"

GameFactory::GameFactory(juegoPG* juego)
{
	ju = juego;
}

ObjetoJuego* GameFactory::createNormalElement(int i){
	x = rand() % 450;
	y = rand() % 450;
	if (i % 2 == 0)
		return new GlobosPG(ju, TGloboN, x, y);
	else 
		return new GloboA(ju, TGloboM, x, y);
}

ObjetoJuego* GameFactory::createSpecialElement (){
	x = rand() % 450;
	y = rand() % 450;
	
	return new  MariposaPG(ju, Tmariposa, x, y);
}

ObjetoJuego* GameFactory::createPrizeElement(){
	x = rand() % 450;
	y = rand() % 450;
	
	return new PremioPG(ju, Tpremio, x, y);
}

GameFactory::~GameFactory()
{
}
