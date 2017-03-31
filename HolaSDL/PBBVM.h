#ifndef _H_PBBVM_H_
#define _H_PBBVM_H_
#include "PBBVMprog​.h"
#include "PBBExternAccess.h"
class PBBVM
{
public:
	PBBVM();

	void run(PBBVMprog​& prog, PBBExternAccess& ball) {
		const char *instr = prog.getInstr();
		int size = prog.getInstructSize();
		for (int pc = 0; pc<size; pc++) {
			switch (instr[pc]) {
			case PBBVMprog​::GET_DX:
				ball.getDX();
				break;
			case PBBVMprog​::GET_DY:
				ball.getDY();
				break;
			/*case PBBVMprog​::SET_DY:
				ball.setDY();
				break;*/
			}
		}
	}
	~PBBVM();
};
#endif

