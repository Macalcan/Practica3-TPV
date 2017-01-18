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
}

void EstadoPG::update(){
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update(); //si se ha exlpotado el globo se determina en nuestro array de booleanos y desciende el numero de globos
	}
}

void EstadoPG::draw() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->draw();
	}
}

EstadoPG::~EstadoPG()
{
}
