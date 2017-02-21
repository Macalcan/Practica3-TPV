#ifndef _H_GloboA_H
#define _H_GloboA_H
#pragma once

#include "SDL.h"
#include "GlobosPG.h"

class GloboA : public GlobosPG
{
public:
	GloboA(juegoPG* jueg, Texturas_t texturas, int &px, int &py);
	
	void update();
	~GloboA();

private:


};
#endif


