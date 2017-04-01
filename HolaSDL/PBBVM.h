﻿#ifndef _H_PBBVM_H_
#define _H_PBBVM_H_
#include "PBBVMprog​.h"
#include "PBBExternAccess.h"
class PBBVM
{
public:
	PBBVM(){}

	static const int MAX_SIZE = 100;
	int instr[MAX_SIZE];
	int size;

	void push(int n){
		instr[size++] = n;
	}

	int pop(){
		return instr[size--];
	}

	void run(PBBVMprog​& prog, PBBExternAccess& ball){
		const char* instr = prog.getInstr();
		int size = prog.getInstructSize();
		for (int pc = 0; pc < size; pc++)
		{
			switch (instr[pc])
			{
			case PBBVMprog​::PUSH:
				push(*((int*)(instr + pc + 1)));
				pc = pc + sizeof(int);
				break;
			case PBBVMprog​::ADD:
				push(pop() + pop());
				break;
			case PBBVMprog​::GET_DX:
				push(ball.getDX());
				break;
			case PBBVMprog​::GET_DY:
				push(ball.getDY());
				break;
			case PBBVMprog​::SET_DX:
				ball.setDX(pop());
				break;
			case PBBVMprog​::SET_DY:
				ball.setDY(pop());
				break;
			case PBBVMprog​::GET_CLICKS:
				push(ball.getClicks());
				break;
			case PBBVMprog​::GET_POINTS:
				push(ball.getPoints());
				break;
			case PBBVMprog​::SET_POINTS:
				ball.setPoints(pop());
				break;
			case PBBVMprog​::DEACTIVATE:
				ball.deactivate();
				break;
			case PBBVMprog​::GAIN_POINTS:
				ball.addPoints(pop());
				break;
			case PBBVMprog​::SUB:
				push(pop() - pop());
				break;
			case PBBVMprog​::MUL:
				push(pop() * pop());
				break;
			case PBBVMprog​::GOTO:
				pc = *((int*)(instr + pc + 1));
				break;
			case PBBVMprog​::JMPZ:
				if (pop() == 0)
					pc = *((int*)(instr + pc + 1));
				else
					pc = pc + sizeof(int);
				break;
			case PBBVMprog​::JMPGT:
				if (pop() > pop())
				pc = *((int*)(instr + pc + 1));
				else
					pc = pc + sizeof(int);
				break;
			default:
				break;
			}
		}
	}
	~PBBVM(){}
};
#endif
