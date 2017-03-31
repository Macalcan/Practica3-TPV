#ifndef _H_PBBVMprog​_H_
#define _H_PBBVMprog​_H_
#include <string>
#include <assert.h>
#include <fstream>
using namespace std;

class PBBVMprog​
{
	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;

	/*static void compile(string file, string outfile){
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
		in.close();
		out.close();
	}*/


public:

	PBBVMprog​(string filename){
		ifstream in;
		in.open(filename, ios::binary);

		in.seekg(0, ios::end);
		size = (int)in.tellg();
		assert(size <= MAX_SIZE);
		in.seekg(0, ios::beg);
		in.read(instr, size);

		in.close();
	}

	void push(int n){
		instr[size++] = n;
	}

	int pop(){
		return instr[size--];
	}

	enum INST {PUSH, ADD, GET_DX, GET_DY, SET_DX, SET_DY};
	
	
	const char* getInstr();
	int getInstructSize();
	

	~PBBVMprog​();

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
		in.close();
		out.close();
	}

protected:
	
	
};
#endif