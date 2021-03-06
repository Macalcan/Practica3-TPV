﻿#include "TexturasSDL.h"
#include "PlayPG.h"
#include "PremioPG.h"
#include "MariposaPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "ObjetoPG.h"
#include "Error.h"
#include "GameOverPG.h"
#include "ProgrammableBouncingBall.h"
#include "BouncingBall.h"
#include "PBBFactory.h"
#include "PBBVMprog​.h"

PlayPG::PlayPG(juegoPG* ju, GameElementFactoryV* fac) : EstadoPG(ju)
{
	factory = fac;
	if (typeid(*factory) == typeid(PBBFactory))
	{
		PBBVMprog​::compile("prog1.vm", "progcom.vm");
	}
	initObjetos();
}

void PlayPG::initObjetos() {
	
	dim = 5; 

	for (int i = 0; i < dim; i++){//creamos un globo en cada vuelta en una posicion aleatoria en el rectangulo de la ventana

		if (i % 2 == 0)
			objetos.emplace_back(factory->createNormalElement(i));//new GlobosPG(juego, TGloboN, x, y)); //cada globo tendrá la textura 0 o la textura 1
		else
			objetos.emplace_back(factory->createNormalElement(i));//new GloboA(juego, TGloboM, x, y));
	}
	numPremios = numMariposas = 2;
	for (int i = dim; i < numMariposas + dim; i++){
		x = rand() % 450;
		y = rand() % 450;
		objetos.emplace_back(factory->createSpecialElement());
	}
	numG = dim; //numero total de globos al principio del juego

	for (int i = dim + numMariposas; i < numPremios + numMariposas + dim; i++){
		objetos.emplace_back(factory->createPrizeElement());
	}

	//QUITAR
	//objetos.emplace_back(new BouncingBall(juego, TPelota, 200, 200));
	//throw error
	
}
void PlayPG::newBaja(ObjetoJuego* po) {
	//queremos saber si lo que destruimos es un globo
	if (dynamic_cast<GlobosPG*>(po) || dynamic_cast<BouncingBall*>(po)) {
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
	else if (typeid(*po) == typeid(ProgrammableBouncingBall))
	puntos += dynamic_cast<ProgrammableBouncingBall*>(po)->getPoints();	
	else if (typeid(*po) == typeid(BouncingBall))
		puntos += dynamic_cast<BouncingBall*>(po)->getPuntos();
	
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

void PlayPG::draw(){
	

	SDL_Rect rect; //rect para el fondo
	rect = { 0, 0, ancho, alto };
	juego->texturas[TFondo]->draw(juego->getRender(), rect); //dibuja el fondo
	
	for (int i = 0; i < objetos.size(); i++) { //dibuja los globos
		objetos[i]->draw();
	}

}
PlayPG::~PlayPG()
{
	for (int i = 0; i < objetos.size(); i++){
		delete objetos[i];
		objetos[i] = nullptr;
	}
}


