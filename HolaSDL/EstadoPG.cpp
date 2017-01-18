#include "EstadoPG.h"


EstadoPG::EstadoPG()
{
}

EstadoPG::EstadoPG(juegoPG* ju)
{
	game = ju;
}

bool EstadoPG::onClick(){
	bool click = false;
	for (int i = objetos.size() - 1; i >= 0 && (!click); i--){
		if (objetos[i]->onClick()){
			click = true;
		}
	}
	return click;
}



void EstadoPG::draw() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->draw();
	}
}

EstadoPG::~EstadoPG()
{
}
