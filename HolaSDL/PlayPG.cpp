#ifndef _H_PlayPG_H
#define _H_PlayPG_H
#include "PlayPG.h"
#include "PremioPG.h"
#include "MariposaPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "ObjetoPG.h"
#include "Error.h"

PlayPG::PlayPG(juegoPG* ju) : EstadoPG(ju)
{
}

bool juegoPG::initObjetos() {
	//declaras variables aleatorias x e y que indican la posicion de cada globo
	int x;
	int y;

	//juegoPG se encarga de las te
	/*for (int i = 0; i < 5; i++) {
		texturas.emplace_back(new TexturasSDL());
		texturas[i]->load(pRenderer, rutasText[i]);
	}*/


	for (int i = 0; i < dim; i++){//creamos un globo en cada vuelta en una posicion aleatoria en el rectangulo de la ventana
		x = rand() % 450;
		y = rand() % 450;
		if (i % 2 == 0)
			objetos.emplace_back(new GlobosPG(this, TGloboN, x, y)); //cada globo tendrá la textura 0 o la textura 1
		else
			objetos.emplace_back(new GloboA(this, TGloboM, x, y));
	}
	numPremios = numMariposas = 2;
	for (int i = dim; i < numMariposas + dim; i++){
		x = rand() % 450;
		y = rand() % 450;
		objetos.emplace_back(new MariposaPG(this, Tmariposa, x, y));
	}
	numG = dim; //numero total de globos al principio del juego

	for (int i = dim + numMariposas; i < numPremios + numMariposas + dim; i++){
		objetos.emplace_back(new PremioPG(this, Tpremio, x, y));
	}

	return (texturas[TGloboN] != nullptr || texturas[Tmariposa] != nullptr || texturas[Tpremio] != nullptr);
}
void PlayPG::newBaja(ObjetoJuego* po) {
	//queremos saber si lo que destruimos es un globo
	if (dynamic_cast<GlobosPG*>(po)) {
		numG--;
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

PlayPG::~PlayPG()
{
}

#endif
