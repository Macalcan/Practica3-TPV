#pragma once
#include "EstadoPG.h"
class PlayPG : public EstadoPG
{
public:
	PlayPG();
	~PlayPG();

protected:
	bool onClick();

	int puntos;
	int numMariposas;
	int numPremios;
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	vector <ObjetoJuego*> objetos; //array de los objetos
	int numG; //numero de globos
	std::vector<TexturasSDL*> texturas;
	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	int mx, my;
};

