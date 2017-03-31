#ifndef _H_ProgrammableBouncingBall_H_
#define _H_ProgrammableBouncingBall_H_
#include "PBBExternAccess.h"
#include "BouncingBall.h"
#include "PBBVMprog​.h"
#include <iostream>
using namespace std;


class ProgrammableBouncingBall : public PBBExternAccess, public BouncingBall
{
	PBBVMprog​ prog;
	//ProgrammableBouncingBall vm; 

public:
	ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py);
	~ProgrammableBouncingBall();
protected:
	int clicks;

	virtual int getDX(){ return dx; }
	virtual void setDX(int dx){ this->dx = dx; }
	virtual int getDY(){ return dy; }
	virtual void setDY(int dy){ this->dy = dy; }
	virtual int getClicks(){ return clicks; }
	virtual int getPoints(){ return puntos; }
	virtual void setPoints(int puntos){ this->puntos = puntos; }
	virtual void setVisible(bool visible){ this->visible = visible; }
	
	

	virtual void update(){
		if (rand()) { // some condition
			vm.run(prog, *this);
		}
		cout << "I am at position (" << x << "," << y << ")" << endl;
	}
	virtual bool onClick();
	void run(PBBVMprog​& prog, PBBExternAccess& ball);
};
#endif
