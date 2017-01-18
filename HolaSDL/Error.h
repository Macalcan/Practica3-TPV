#pragma once
#include <string>
using namespace std;
class Error
{
protected:
	string errorM; //mensaje de error
	
public:
	//Error();
	Error(string const &message) { errorM = message; };
	const string& mensaje() const { return errorM; };
	~Error();
};


