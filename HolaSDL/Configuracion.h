#ifndef _H_Configuracion_H_
#define _H_Configuracion_H_
#include "EstadoPG.h"
#include "juegoPG.h"
#include "BotonPG.h"
#include "PlayPg.h"
#include "MenuPG.h"

class Configuracion : public EstadoPG
{
public:
	Configuracion(juegoPG* juego);
	~Configuracion();
protected:
	void initObjetos();
	
	static void globos(juegoPG* jug){ jug->setFactoria(FGlobos); jug->stateChange(new MenuPG(jug)); }
	static void bBalls(juegoPG* jug){ jug->setFactoria(FBouncingBalls); jug->stateChange(new MenuPG(jug)); }
};
#endif
