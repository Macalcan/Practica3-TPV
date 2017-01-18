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
	int puntos;
protected:
	bool initObjetos();
	virtual void draw();
	
	int numMariposas;
	int numPremios;
	//bool error, gameOver, exit;
	//SDL_Window* pWindow;
	//SDL_Renderer* pRenderer;
	//bool pausa; //para pausar la actualizacion de los globos
	bool gameOver;
	int numG; //numero de globos
	//std::vector<TexturasSDL*> texturas;

	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	int mx, my;
};



