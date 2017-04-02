#ifndef _H_ProgrammableBouncingBall_H_
#define _H_ProgrammableBouncingBall_H_
#include "PBBExternAccess.h"
#include "BouncingBall.h"
#include "PBBVMprog​.h"
#include <iostream>
#include "PBBVM.h"
#include "PlayPG.h"
using namespace std;


class ProgrammableBouncingBall : public PBBExternAccess, public BouncingBall
{
	

public:
	ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py, string vmprog);
	~ProgrammableBouncingBall(){}
	PBBVM vm;
	PBBVMprog​ prog;
	virtual int getPoints(){ return puntos; }
protected:
	int clicks;

	virtual int getDX(){ return dx; }
	virtual void setDX(int dx){ this->dx = dx; }
	virtual int getDY(){ return dy; }
	virtual void setDY(int dy){ this->dy = dy; }
	virtual int getClicks(){ return clicks; }
	
	virtual void setPoints(int puntos){ this->puntos = puntos; }
	virtual void deactivate(){ visible = false; dynamic_cast<PlayPG*>(juego->topState())->newBaja(this); }
	virtual void addPoints(int points){ puntos += points; }
	
	virtual void update();
	virtual bool onClick();
	
	
	
	
};
#endif
