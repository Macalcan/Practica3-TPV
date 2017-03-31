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
		case PBBVMprog​::PUSH:
			prog.push(*((int*)(instr + pc + 1)));
			pc = pc + sizeof(int);
			break;
		case PBBVMprog​::ADD:
			prog.push(prog.pop() + prog.pop());
			break;
		case PBBVMprog​::GET_DX:
			prog.push(ball.getDX());
			break;
		case PBBVMprog​::GET_DY:
			prog.push(ball.getDY());
			break;
		case PBBVMprog​::SET_DX:
			ball.setDX(prog.pop());
			break;
		case PBBVMprog​::SET_DY:
			ball.setDY(prog.pop());
			break;
		}
	}
}

ProgrammableBouncingBall::~ProgrammableBouncingBall()
{

}
