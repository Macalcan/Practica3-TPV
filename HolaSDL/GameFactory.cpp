#include "GameFactory.h"
#include "GlobosPG.h"
#include "MariposaPG.h"
#include "PremioPG.h"
#include "BouncingBall.h"
#include "Vago.h"
#include "GloboA.h"

GameFactory::GameFactory()
{
}

ObjetoJuego* GameFactory::createNormalElement(char type, juegoPG* juego){
	x = rand() % 450;
	y = rand() % 450;
	if (type == 'g')
		return new GlobosPG(juego, TGloboN, x, y);
	else if (type == 'a')
		return new GloboA(juego, TGloboM, x, y);
	else 
		return new BouncingBall(juego, TPelota, x, y);
}

ObjetoJuego* GameFactory::createSpecialElement (char type, juegoPG* juego){
	x = rand() % 450;
	y = rand() % 450;
	if (type == 'g')
		return new  MariposaPG(juego, Tmariposa, x, y);
	else
		return nullptr;
	/*else if(type == 'v')
		return new Vago();*/
}

ObjetoJuego* GameFactory::createPrizeElement(char type, juegoPG* juego){
	x = rand() % 450;
	y = rand() % 450;
	if (type == 'g')
		return new PremioPG(juego, Tpremio, x, y);
	else
		return nullptr;
	/*else if (type == 'v')
		return new Vago();*/
}

GameFactory::~GameFactory()
{
}
