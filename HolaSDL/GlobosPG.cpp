// Practica realizada por Blanca Macazaga Zuazo y Adri�n Alc�ntara Delgado

#include "GlobosPG.h"
#include "PlayPG.h"
using namespace std;



GlobosPG::GlobosPG(juegoPG* jueg, Texturas_t texturas, int px, int py) : ObjetoPG(jueg, texturas, px, py)
{
	visible = true;
	puntos = 5;
	explotado = false;
	inflado = 100;
	rectObjeto.h = rectObjeto.w = 100;
}


bool GlobosPG::onClick(){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	
	if (ObjetoPG::onClick() && !explotado){
		visible = false;
		explotado = true;
		if (dynamic_cast<PlayPG*>(juego->topState())) {
			dynamic_cast<PlayPG*>(juego->topState())->newPuntos(this);
			dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);
		}
		return true;
	}
	else return false;
	
}
//--------------------------------------------------------------------------------//
//actualiza el globo
void GlobosPG::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (!explotado){
		if (inflado <= 0 && dynamic_cast<PlayPG*>(juego->topState())){
			explotado = true;
			visible = false;
			dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);
		}
		else {
			if (rand() % 100 < PVIS) //probabilidad de que sea visible o no
				visible = true;
			else
				visible = false;

			if (rand() % 100 < PDES){ //probabilidad de que se desinfle
				inflado -= 10; //disminuye el "aire" que tiene el globo
				rectObjeto.h -= 10; //disminuye el tama�o del globo
				rectObjeto.w -= 10;
				//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
				puntos += 2;
			}

		}
	}
}

//getter de puntos del globo
int GlobosPG::getPuntos(){
	return puntos;
}

//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}

