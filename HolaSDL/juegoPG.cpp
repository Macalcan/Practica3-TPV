// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "PremioPG.h"
#include "MariposaPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "ObjetoPG.h"
#include "Error.h"
#include "MenuPG.h"
#include "PausaPG.h"
using namespace std;

juegoPG::juegoPG()
{
	srand(SDL_GetTicks());

	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;

	error = false; //si hay un error se pondrá a true
	exit = false; //si se sale del juego se pondrá a true
	gameOver = false; //si se acaba el juego se pondrá a true
	pausa = false; //se se pulsa p es true y se para la actualizacion de los globos
	
	//Error errorM("No se carga SDL");
	if(!initSDL())
		throw errorTextura("SDL no se inicia");

	//metemos las rutas de texturas
	rutasText.emplace_back("..\\bmps\\sky.jpg");
	rutasText.emplace_back("..\\bmps\\globoN.png");
	rutasText.emplace_back("..\\bmps\\globoM.png");
	rutasText.emplace_back("..\\bmps\\butterfly.png");
	rutasText.emplace_back("..\\bmps\\Gift.png");
	rutasText.emplace_back("..\\bmps\\TPlay.png");
	rutasText.emplace_back("..\\bmps\\TMenu.png");
	rutasText.emplace_back("..\\bmps\\TExit.png");
	rutasText.emplace_back("..\\bmps\\TScore.png");
	rutasText.emplace_back("..\\bmps\\TResume.png");
	initTexturas();
}
//--------------------------------------------------------------------------------//
bool juegoPG::initSDL() {

	bool carga = true; //si carga es false no se puede cargar la ventana inicializando SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "¡SDL no se ha podido iniciar! \nSDL_Error: " << SDL_GetError() << '\n';
		carga = false;
	}
	else {
		pWindow = SDL_CreateWindow("SDL Balloon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr){
			cout << "¡La ventana no se ha podido crear! \nSDL_Error: " << SDL_GetError() << '\n';
			carga = false;
		}
		else {
			//Toma la superficie de la ventana:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //De momento la ventana sera negra pero despues tendra un fondo
			if (pRenderer == nullptr){
				cout << "¡No se ha podido crear el renderer! \nSDL_Error: " << SDL_GetError() << '\n';
				carga = false;
			}
		}
	}

	return carga;
}
//--------------------------------------------------------------------------------//
void juegoPG::initTexturas() {
	for (int i = 0; i < numText; i++) {
		texturas.emplace_back(new TexturasSDL());
		texturas[i]->load(pRenderer, rutasText[i]);
	}
}
SDL_Renderer* juegoPG::getRender() const {
	return pRenderer;
}
//--------------------------------------------------------------------------------//


//--------------------------------------------------------------------------------//
void juegoPG::closeSDL() {
	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
//--------------------------------------------------------------------------------//
void juegoPG::freeTexturas() {
	
	//delete de las rutas de codigo
	delete (texturas[TGloboN]);
	texturas[TGloboN] = nullptr;
	delete(texturas[TGloboM]);
	texturas[TGloboM] = nullptr;
	delete (texturas[TFondo]);
	texturas[TFondo] = nullptr;
	delete (texturas[Tmariposa]);
	texturas[Tmariposa] = nullptr;
	delete (texturas[Tpremio]);
	texturas[Tpremio] = nullptr;
	delete (texturas[TPlay]);
	texturas[TPlay] = nullptr;
	delete (texturas[TMenu]);
	texturas[TMenu] = nullptr;
	delete (texturas[TExit]);
	texturas[TExit] = nullptr;
	delete (texturas[TScore]);
	texturas[TScore] = nullptr;
	delete (texturas[TResume]);
	texturas[TResume] = nullptr;
	//destruye las texturas de los globos
}
//--------------------------------------------------------------------------------//
EstadoJuego* juegoPG::topState() {
	return estados.top();
}

//dibuja los globos que estan visibles, para ello deberia hacer probablemente un for recorriendo todos los globos y accediendo a su atributo visible,
//en caso de que el globo lo sea se dibuja con draw(pRenderer), pRenderer está declarado arriba pero no asginado
void juegoPG::render() {

	SDL_RenderClear(pRenderer); //"limpia" el render donde vamos a dibujar el siguiente frame

	/*SDL_Rect rect; //rect para el fondo
	rect = { 0, 0, ancho, alto };
	texturas[TFondo]->draw(pRenderer, rect); //dibuja el fondo*/

	topState()->draw(); 

	//Show the window
	SDL_RenderPresent(pRenderer);
}
//--------------------------------------------------------------------------------//
//comprueba si al hacer click ha explotado el globo a traves del metodo onClick de GlobosPG y si lo ha explotado saca los puntos del globo y los suma
//a los puntos conseguidos en total
void juegoPG::onClick(){
	topState()->onClick();
}
//--------------------------------------------------------------------------------//
//recorre todos los globos actualizandolos y comprobando si se han desinflado o explotado, y por lo tanto no son visibles
void juegoPG::update() {
	topState()->update();
}
//--------------------------------------------------------------------------------//
void juegoPG::handle_event() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) exit = true;
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK";
				mx = e.button.x;
				my = e.button.y;
				onClick();
			}
		}
		else if (e.type == SDL_KEYUP){ //si se pulsa una tecla comprueba que es p
			if (e.key.keysym.sym == SDLK_p){
				pausa = !pausa;
			}
			else if (e.key.keysym.sym == SDLK_ESCAPE && dynamic_cast<PlayPG*>(topState()))
			{
				pushState(new PausaPG(this));
			}
		}
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::run()
{
	pushState(new MenuPG(this));
	if (!error){
		Uint32 MSxUpdate = 500;
		cout << "Play \n";
		Uint32 lastUpdate = SDL_GetTicks();
		string puntuacion = "preparado!!?? ";
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Practica1", puntuacion.c_str(), nullptr);
		
		//render();
		//handle_event();
		while (!exit && !gameOver){
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){//while(elapsed >= MSxUpdate)
				if (!pausa)
					update();
				
				lastUpdate = SDL_GetTicks();
			}

			render();
			handle_event();
		}

		render();
		
	}



}


//--------------------------------------------------------------------------------//
void juegoPG::getMousePos(int &mpx, int &mpy) const {
	//hay que añadir atributos para la posicion del raton (debe actualizarse en onClick)
	mpx = mx;
	mpy = my;
}
//--------------------------------------------------------------------------------//
void juegoPG::setSalir(){
	exit = true;
}

//--------------------------------------------------------------------------------//
void juegoPG::pushState(EstadoJuego* estado){
	estados.push(estado);
}
void juegoPG::popState() {
	delete topState();
	estados.pop();
}

void juegoPG::stateChange(EstadoJuego* estado){
	popState();
	pushState(estado);
}


juegoPG::~juegoPG()
{
	closeSDL();
	freeTexturas();
	pWindow = nullptr;
	pRenderer = nullptr;
}
