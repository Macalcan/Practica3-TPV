#pragma once
#include <string>
using namespace std;
#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <SDL.h>
using namespace std;
class Error
{
protected:
 string mensaje;
public:
 Error(string const & m)  {
  mensaje = m;
  
 }
 string const Mensaje(){
  return mensaje;
 }
 

};

class errorTextura : public Error {
public:
 errorTextura(string const& m) : Error(m) {};
};
class errorSDL : public Error {
public:
 errorSDL(string const& m) : Error(m) {};
};
#endif

