// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "SDL.h"  // Para utilizar SDL
#include <iostream>  // la consola: cin / cout
#include "juegoPG.h"
#include "Error.h"
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 

int main(int argc, char* args[]) {  // SDL require esta cabecera 
	
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	
	
	try{
		juegoPG game; //variable de tipo juegoPG para empezar el juego
		game.run(); //llamada al metodo run para que comience el juego
	}
	catch (Error & e){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", e.mensaje().c_str(), nullptr);

	}

	return 0;
}