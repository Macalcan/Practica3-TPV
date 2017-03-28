#include "ProgrammableBouncingBall.h"


ProgrammableBouncingBall::ProgrammableBouncingBall(juegoPG* jueg, Texturas_t texturas, int px, int py) 
	: BouncingBall(jueg, texturas, px, py)
{
}

void ProgrammableBouncingBall::run(PBBVMprog​& prog, PBBExternAccess& ball){
	const char* instr = prog.getInstr();
	int size = prog.getInstructSize();
	for (int pc = 0; pc < size; pc++)
	{
		switch (instr[pc])
		{
		case PBBVMprog​::GET_DX:
			ball.getDX();
			break;
		case PBBVMprog​::GET_DY:
			ball.getDY();
			break;
		}
	}
}

ProgrammableBouncingBall::~ProgrammableBouncingBall()
{

}
