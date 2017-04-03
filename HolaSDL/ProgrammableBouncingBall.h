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
	ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py, string vmprog) : BouncingBall(jueg, texturas, px, py), prog(vmprog)
	{
		clicks = 0;
		points = 10;
	}
	~ProgrammableBouncingBall(){}
	PBBVM vm;
	PBBVMprog​ prog;
	virtual int getPoints(){ return points; }
protected:
	int clicks;

	virtual int getDX(){ return dx; }
	virtual void setDX(int dx){ this->dx = dx; }
	virtual int getDY(){ return dy; }
	virtual void setDY(int dy){ this->dy = dy; }
	virtual int getClicks(){ return clicks; }
	
	virtual void setPoints(int puntos){ this->puntos = puntos; }
	virtual void disable(){ 
		explotado = true;
		visible = false; 
		dynamic_cast<PlayPG*>(juego->topState())->newPuntos(this);
		dynamic_cast<PlayPG*>(juego->topState())->newBaja(this);		
	}
	virtual void addPoints(int points){ puntos += points; }
	
	
	virtual bool onClick(){

		if (ObjetoPG::onClick()){
			clicks++;
			vm.run(prog, *this);
			return true;
		}
		else
			return false;
	}
	int points;
	
	
	
};
#endif
