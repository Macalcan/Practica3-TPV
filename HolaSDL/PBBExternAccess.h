#ifndef _H_PBBExternAccess_H_
#define _H_PBBExternAccess_H_

class PBBExternAccess
{
public:

	PBBExternAccess(){}
	//metodos para obtener dx y dy
	virtual int getDX() = 0;
	virtual int getDY() = 0;
	//metodos para cambiar el valor dx y dy
	virtual void setDX(int dx) = 0;
	virtual void setDY(int dy) = 0;
	//metodo para obtener el numero de clicks hasta el momento
	//int o void???
	virtual int getClicks() = 0;
	//metodos para consultar o cambiar los puntos del objeto
	virtual int getPoints() = 0;
	virtual void setPoints(int puntos) = 0;
	//metodo para que el objeto desaparezca
	virtual void setVisible(bool visible) = 0;

	virtual ~PBBExternAccess(){}
};
#endif

