#pragma once
#include "GameElementFactoryV.h"
class GameFactory : public GameElementFactoryV
{
public:
	GameFactory();
	/*ObjetoJuego* createNormal(char type);
	ObjetoJuego* createEspecial(char type);
	ObjetoJuego* createPrize(char type);*/

	~GameFactory();
};

