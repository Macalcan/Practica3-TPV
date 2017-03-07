#ifndef _H_GameElementFactoryV_H_
#define _H_GameElementFactoryV_H_
#include "ObjetoJuego.h"
#include "juegoPG.h"
class GameElementFactoryV
{
public:

	GameElementFactoryV()
	{
	}

	virtual ObjetoJuego* createNormalElement(char type, juegoPG* juego) = 0;
	virtual ObjetoJuego* createSpecialElement(char type, juegoPG* juego) = 0;
	virtual ObjetoJuego* createPrizeElement(char type, juegoPG* juego) = 0;

	virtual ~GameElementFactoryV()
	{
	}
};
#endif
