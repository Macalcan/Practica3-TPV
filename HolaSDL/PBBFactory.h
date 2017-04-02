#ifndef _H_PBBFactory_H_
#define _H_PBBFactory_H_
#include "GameElementFactoryV.h"
#include "juegoPG.h"

class PBBFactory : public GameElementFactoryV
{
public:
	PBBFactory(juegoPG* ju);
	
	virtual ObjetoJuego* createNormalElement(int i);
	virtual ObjetoJuego* createPrizeElement();
	virtual ObjetoJuego* createSpecialElement();

	~PBBFactory();

protected:
	juegoPG* juego;
};
#endif

