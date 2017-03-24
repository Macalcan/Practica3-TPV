#ifndef _H_Configuracion_H_
#define _H_Configuracion_H_
#include "EstadoPG.h"
#include "juegoPG.h"
#include "BotonPG.h"
#include "PlayPg.h"

class Configuracion : public EstadoPG
{
public:
	Configuracion(juegoPG* juego);
	~Configuracion();
protected:
	void initObjetos();
	
};
#endif
