
#include "PlayPG.h"
#include "PremioPG.h"
#include "MariposaPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "ObjetoPG.h"
#include "Error.h"
#include "GameOverPG.h"

PlayPG::PlayPG(juegoPG* ju) : EstadoPG(ju)
{
	
	initObjetos();
}

void PlayPG::initObjetos() {
	//declaras variables aleatorias x e y que indican la posicion de cada globo

	for (int i = 0; i < dim; i++){//creamos un globo en cada vuelta en una posicion aleatoria en el rectangulo de la ventana
		x = rand() % 450;
		y = rand() % 450;
		if (i % 2 == 0)
			objetos.emplace_back(new GlobosPG(juego, TGloboN, x, y)); //cada globo tendrá la textura 0 o la textura 1
		else
			objetos.emplace_back(new GloboA(juego, TGloboM, x, y));
	}
	numPremios = numMariposas = 2;
	for (int i = dim; i < numMariposas + dim; i++){
		x = rand() % 450;
		y = rand() % 450;
		objetos.emplace_back(new MariposaPG(juego, Tmariposa, x, y));
	}
	numG = dim; //numero total de globos al principio del juego

	for (int i = dim + numMariposas; i < numPremios + numMariposas + dim; i++){
		objetos.emplace_back(new PremioPG(juego, Tpremio, x, y));
	}

	//throw error
	
}
void PlayPG::newBaja(ObjetoJuego* po) {
	//queremos saber si lo que destruimos es un globo
	if (dynamic_cast<GlobosPG*>(po)) {
		numG--;
		if (numG == 0){
			juego->stateChange(new GameOverPG(juego, puntos));
		}
	}
	else if (typeid(*po) == typeid(PremioPG)) {
		dynamic_cast<PremioPG*>(po)->visible = false;
	}
}

//--------------------------------------------------------------------------------//
void PlayPG::newPuntos(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po))
		puntos += dynamic_cast<GlobosPG*>(po)->getPuntos();
	else if (typeid(*po) == typeid(PremioPG))
		puntos += dynamic_cast<PremioPG*>(po)->getPuntos();
}
//--------------------------------------------------------------------------------//
void PlayPG::newPremio() {
	bool premioNuevo = false;
	for (int i = objetos.size() - 1; i > objetos.size() - numPremios - 1 && !(premioNuevo); i--){
		if (!(dynamic_cast<PremioPG*>(objetos[i])->visible))
		{
			dynamic_cast<PremioPG*>(objetos[i])->visible = true;
			premioNuevo = true;
		}
	}

}
void PlayPG::update() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update(); //si se ha exlpotado el globo se determina en nuestro array de booleanos y desciende el numero de globos
	}
}
void PlayPG::draw(){
	//SDL_RenderClear(game->getRender()); //"limpia" el render donde vamos a dibujar el siguiente frame

	/*SDL_Rect rect; //rect para el fondo
	rect = { 0, 0, ancho, alto };
	texturas[TFondo]->draw(juego->getRender(), rect); //dibuja el fondo
	*/
	for (int i = 0; i < objetos.size(); i++) { //dibuja los globos
		objetos[i]->draw();
	}

	//Show the window
	//SDL_RenderPresent(game->getRender());
}
PlayPG::~PlayPG()
{
}


