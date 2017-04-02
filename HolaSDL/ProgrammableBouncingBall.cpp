#include "ProgrammableBouncingBall.h"


ProgrammableBouncingBall::ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py, string vmprog) : BouncingBall(jueg, texturas, px, py), prog(vmprog)
{
	clicks = 0;
	//puntos = 10;
}





