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
const int numText = 4;
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
	int getPuntos();
private:
	
	int dim = 10; //10; //dimension del array de los globos
	void initTexturas();
	bool initSDL();
	void closeSDL();
	bool initObjetos();
	void freeObjetos();
	void render() const;
	void onClick();
	void update();
	void handle_event();

	std::vector<std::string> rutasText;	
	stack <EstadoJuego*> estados;
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

