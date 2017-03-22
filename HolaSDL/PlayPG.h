#ifndef _H_PlayPG_H_
#define _H_PlayPG_H_
#include "GameElementFactoryV.h"
#include "EstadoPG.h"

class PlayPG : public EstadoPG
{
public:
	PlayPG(juegoPG* ju, GameElementFactoryV* fac);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego * po);
	void newPremio();
protected:
	int puntos;
	void initObjetos();
	virtual void draw();
	
	GameElementFactoryV* factory;//Game factory
	int numMariposas;
	int numPremios;
	int dim = 10;
	bool gameOver;
	int numG; //numero de globos
	//std::vector<TexturasSDL*> texturas;

	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	int mx, my;
};
#endif
