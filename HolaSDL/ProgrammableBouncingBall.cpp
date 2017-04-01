#include "ProgrammableBouncingBall.h"


ProgrammableBouncingBall::ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py, string vmprog) : BouncingBall(jueg, texturas, px, py), prog(vmprog)
{
	clicks = 0;
}

void ProgrammableBouncingBall::update(){
	{
		if (rand()) { // some condition
			vm.run(prog, *this);
		}
		//cout << "I am at position (" << x << "," << y << ")" << endl;
	}
}

bool ProgrammableBouncingBall::onClick(){
	if (BouncingBall::onClick()){
		clicks++;
		vm.run(prog, *this);
		return true;
	}
	else
		return false;
}


