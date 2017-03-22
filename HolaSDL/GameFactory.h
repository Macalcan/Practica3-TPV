#ifndef _H_GameFactory_H_
#define _H_GameFactory_H_
#include "GameElementFactoryV.h"
#include "juegoPG.h"
class GameFactory : public GameElementFactoryV
{
public:
	GameFactory(juegoPG* juego);
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

