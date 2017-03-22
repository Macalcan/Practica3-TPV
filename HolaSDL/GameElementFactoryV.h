#ifndef _H_GameElementFactoryV_H_
#define _H_GameElementFactoryV_H_
#include "ObjetoJuego.h"

class GameElementFactoryV
{
public:

	GameElementFactoryV()
	{
	}

	virtual ObjetoJuego* createNormalElement(int i) = 0;
	virtual ObjetoJuego* createSpecialElement() = 0;
	virtual ObjetoJuego* createPrizeElement() = 0;

	virtual ~GameElementFactoryV()
	{
	}
};
#endif
