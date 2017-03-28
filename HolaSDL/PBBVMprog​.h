#ifndef _H_PBBVMprog​_H_
#define _H_PBBVMprog​_H_
#include <string>
#include <fstream>
using namespace std;

class PBBVMprog​
{
	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;

	static void compile(string file, string outfile){
		ifstream in;
		ofstream out;
		char bytecode[MAX_SIZE];
		string keyword;
		int pc = 0;

		while (!in.eof())
		{
			in >> keyword;
			if (in.good())
			{
				if (keyword == "get_dx")
					bytecode[pc++] = GET_DX;
				else if (keyword == "get_dy")
					bytecode[pc++] = GET_DY;
				else  
					throw "Error!";
			}
		}
		out.write(bytecode, pc);
	}

public:
	enum INST {GET_DX, GET_DY};
	PBBVMprog​(string file);
	const char* getInstr();
	int getInstructSize();
	~PBBVMprog​();

protected:
	
	
};
#endif