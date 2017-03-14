#ifndef _H_Vago_H_
#define _H_Vago_H_
#include "ObjetoPG.h"
class Vago : public ObjetoPG
{
public:
	Vago(juegoPG* ju, Texturas_t textura, int x, int y);
	virtual void draw(){}
	virtual void update(){}
	virtual bool onClick(){ return false; }
	~Vago();
};

#endif

