
#include "ObjetoPG.h"


ObjetoPG::ObjetoPG(juegoPG* jueg, Texturas_t texturas, int px, int py) 
{	
	juego = jueg;
	texturasa = texturas;
	rectObjeto.x = px;
	rectObjeto.y = py;

}

bool ObjetoPG::dentro(int x, int y) const{
	
	return(y >= rectObjeto.y && y <= rectObjeto.y + rectObjeto.h &&  x >= rectObjeto.x && x <= rectObjeto.x + rectObjeto.w);
	
}
bool ObjetoPG::onClick(){
	int mpx; 
	int mpy;
	juego->getMousePos(mpx, mpy);
	return dentro(mpx, mpy);
}
void ObjetoPG::draw(){
	
	if (visible){
		juego->getTextura(texturasa)->draw(juego->getRender(), rectObjeto);
	}
}




ObjetoPG::~ObjetoPG()
{
}


