#ifndef _H_Gamefactory2_H_
#define _H_Game2actory2_H_
#include "GameElementFactoryV.h"
class Gamefactory2 : public GameElementFactoryV
{
public:
	Gamefactory2(char types, juegoPG* juego);
	ObjetoJuego* createNormalElement(int i);
	ObjetoJuego* createSpecialElement();
	ObjetoJuego* createPrizeElement();
	~Gamefactory2();

protected:
	int x;
	int y;
	char type;
	juegoPG* ju;
};
#endif

