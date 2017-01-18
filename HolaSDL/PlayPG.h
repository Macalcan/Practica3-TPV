#ifndef _H_PlayPG_H_
#define _H_PlayPG_H_
#pragma once
#include "EstadoPG.h"
class PlayPG : public EstadoPG
{
public:
	PlayPG(juegoPG* ju);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego * po);
	void newPremio();


protected:
	int puntos;
	void initObjetos();
	virtual void draw();
	virtual void update();
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
