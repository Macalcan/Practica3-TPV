#ifndef _H_PBBVMprog​_H_
#define _H_PBBVMprog​_H_
#include <string>
#include <assert.h>
#include <fstream>
using namespace std;

class PBBVMprog​
{
	static const int MAX_SIZE = 200;
	char instr[MAX_SIZE];
	int size = 0;

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


	enum INST {PUSH, ADD, GET_DX, GET_DY, SET_DX, SET_DY, GET_CLICKS, GET_POINTS, SET_POINTS, DEACTIVATE, GAIN_POINTS, MUL, SUB, GOTO, JMPZ, JMPGT};
	
	
	const char* getInstr(){
		return instr;
	}

	int getInstructSize(){
		return size;
	}
	

	~PBBVMprog​(){}

	static void compile(string file, string outfile){
		ifstream in;
		ofstream out;

		in.open(file);
		out.open(outfile, ios::binary);

		char bytecode[MAX_SIZE];
		int addr[MAX_SIZE];
		int bytecodeNum = -1;
		bool pending[MAX_SIZE];

		string keyword;
		int pc = 0;

		while (!in.eof())
		{
			in >> keyword;
			if (/*in.good()*/ !in.bad())
			{
				bytecodeNum++;
				addr[bytecodeNum] = pc;
				pending[bytecodeNum] = false;

				if (keyword == "GET_DX")
					bytecode[pc++] = GET_DX;
				else if (keyword == "GET_DY")
					bytecode[pc++] = GET_DY;
				else if (keyword == "SET_DX")
					bytecode[pc++] = SET_DX;
				else if (keyword == "SET_DY")
					bytecode[pc++] = SET_DY;
				else if (keyword == "GET_CLICKS")
					bytecode[pc++] = GET_CLICKS;
				else if (keyword == "GET_POINTS")
					bytecode[pc++] = GET_POINTS;
				else if (keyword == "SET_POINTS")
					bytecode[pc++] = SET_POINTS;
				else if (keyword == "DEACTIVATE")
					bytecode[pc++] = DEACTIVATE;
				else if (keyword == "GAIN_POINTS")
					bytecode[pc++] = GAIN_POINTS;
				else if (keyword == "ADD")
					bytecode[pc++] = ADD;
				else if (keyword == "MUL")
					bytecode[pc++] = MUL;
				else if (keyword == "SUB")
					bytecode[pc++] = SUB;
				else if (keyword == "PUSH"){
					int n;
					in >> n;
					bytecode[pc++] = PUSH;
					*((int*)(bytecode + pc)) = n;
					pc += sizeof(int);
				}
				else if (keyword == "GOTO"){
					int n;
					in >> n;
					bytecode[pc++] = GOTO;
					if (n < bytecodeNum){
						*((int*)(bytecode + pc)) = addr[n];
					}
					else {
						pending[bytecodeNum] = true;
						*((int*)(bytecode + pc)) = n;
					}
					pc = pc + sizeof(int);
				}
				else if (keyword == "JMPZ"){
					int n;
					in >> n;
					bytecode[pc++] = JMPZ;
					if (bytecode[pc] == 0){
						if (n < bytecodeNum){
							*((int*)(bytecode + pc)) = addr[n];
						}
						else {
							pending[bytecodeNum] = true;
							*((int*)(bytecode + pc)) = n;
						}
						pc = pc + sizeof(int);
					}
				}
				else if (keyword == "JMPGT"){
					int n;
					in >> n;
					bytecode[pc++] = JMPGT;
					if (n < bytecodeNum) {
						*((int *)(bytecode + pc)) = addr[n];
					}
					else {
						pending[bytecodeNum] = true;
						*((int *)(bytecode + pc)) = n;
					}
					pc += sizeof(int);
				}
				else
					throw "Error!";
			}
		}

		for (int i = 0; i < bytecodeNum; i++) {
			if (pending[i]) {
				int n = *((int*)(bytecode + addr[i] + 1));
				if (n <= bytecodeNum) {
					*((int*)(bytecode + addr[i] + 1)) = addr[n];
				}
				else
					*((int*)(bytecode + addr[i] + 1)) = pc++;

			}
			out.write(bytecode, pc);
			in.close();
			out.close();
		}
	}
	
};
#endif