#pragma once
#include "ObjetoJuego.h"
class GameElementFactoryV
{
public:

	GameElementFactoryV()
	{
	}

	/*virtual ObjetoJuego* createNormal(char type) = 0;
	virtual ObjetoJuego* createEspecial(GameElementFactoryV* factory) = 0;
	virtual ObjetoJuego* createPrize(GameElementFactoryV* factory) = 0;*/

	virtual ~GameElementFactoryV()
	{
	}
};

