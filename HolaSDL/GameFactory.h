#ifndef _H_GameFactory_H_
#define _H_GameFactory_H_
#include "GameElementFactoryV.h"
class GameFactory : public GameElementFactoryV
{
public:
	GameFactory();
	ObjetoJuego* createNormalElement(char type, juegoPG* juego);
	ObjetoJuego* createSpecialElement(char type, juegoPG* juego);
	ObjetoJuego* createPrizeElement(char type, juegoPG* juego);

protected:
	int x;
	int y;
	~GameFactory();
};
#endif

