#ifndef _H_GameFactory_H_
#define _H_GameFactory_H_
#include "GameElementFactoryV.h"
class GameFactory : public GameElementFactoryV
{
public:
	GameFactory(char types, juegoPG* juego);
	ObjetoJuego* createNormalElement(int i);
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();

protected:
	int x;
	int y;
	char type;
	juegoPG* ju;
	~GameFactory();
};
#endif

