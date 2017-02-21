#include "GameFactory.h"
#include "GlobosPG.h"
#include "MariposaPG.h"
#include "PremioPG.h"

GameFactory::GameFactory()
{
}

/*ObjetoJuego* GameFactory::createNormal(char type){
	if (type == 'g')
		return new GlobosPG();
	else
		return new BouncingBall();
}

ObjetoJuego* GameFactory::createEspecial(char type){
	if (type == 'g')
		return new  MariposaPG();
	else
		return new Vago();
}

ObjetoJuego* GameFactory::createPrize(char type){
	if (type == 'g')
		return new PremioPG();
	else
		return new Vago();
}*/

GameFactory::~GameFactory()
{
}
