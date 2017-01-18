#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "ObjetoJuego.h"
#include "EstadoJuego.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>
#include <stack>


const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
const int numText = 10;
enum Texturas_t { TFondo, TGloboN, TGloboM, Tmariposa, Tpremio, TPlay, TMenu, TExit, TScore, TResume };

class juegoPG
{
public:
	juegoPG();
	void run();
	void getMousePos(int &mpx, int &mpy)const;
	// los new van a necesitar hacer casting de clase dynamic_cast

	
	
	SDL_Renderer* getRender()const;
	TexturasSDL* getTextura(Texturas_t et) const { return texturas[et]; } //metodo inline
	void setSalir();
	void popState(); //diapositiva 37
	void pushState(EstadoJuego* estado); //diapositiva 37
	void stateChange(EstadoJuego* estado);
	EstadoJuego* topState(); //diapositiva 39
	~juegoPG();
	std::vector<TexturasSDL*> texturas;
private:
	
	int dim = 10; //10; //dimension del array de los globos
	void initTexturas();
	void freeTexturas();
	bool initSDL();
	void closeSDL();
	
	void render();
	void onClick();
	void update();
	void handle_event();

	std::vector<std::string> rutasText;	
	stack <EstadoJuego*> estados;
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	vector <ObjetoJuego*> objetos; //array de los objetos
	//int numG; //numero de globos
	
	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	int mx, my;
	
};

