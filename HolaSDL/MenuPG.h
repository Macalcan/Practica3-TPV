#ifndef _H_MenuPG_H
#define _H_MenuPG_H
#include "EstadoPG.h"
#include "juegoPG.h"
#include "BotonPG.h"
#include "PlayPg.h"
#include "Configuracion.h"

class MenuPG : public EstadoPG
{
public:
	MenuPG(juegoPG* juego);
	BotonPG* boton;
protected:
	void initObjetos();
	static void salir(juegoPG* jug) { jug -> setSalir(); }
	static void jugar(juegoPG* jug) { jug->stateChange(new PlayPG(jug, jug->getFactoria())); }
	static void config(juegoPG* jug){ jug->stateChange(new Configuracion(jug)); /*jug->setFactoria(FBouncingBalls);*/ }
	~MenuPG();
};
#endif
