#include "PileDeLivres.h"
#include <iostream>

//Constructeurs
PileDeLivres::PileDeLivres() : _sommetPile(NULL) {}
PileDeLivres::PileDeLivres(Livre& oeuvre) : _sommetPile(oeuvre) {}
PileDeLivres::PileDeLivres(const PileDeLivres& Pile) : _sommetPile(NULL) {
	_sommetPile = Pile.at(Pile.size());
}
//Destructeur
PileDeLivres::~PileDeLivres(){ suppress(this.at(this.size())); }
//Operateur
PileDeLivres& PileDeLivres::operator =(const PileDeLivres& Pile){

	return *this;
}
//Accesseurs en lecture
Livre& PileDeLivres::at(size_t indice);
const Livre& PileDeLivres::at(size_t indice)const;

size_t PileDeLivres::size()const;
//Accesseurs en écriture
void PileDeLivres::add(Livre oeuvre); 
void PileDeLivres::delete(); 
//Autre

//HORS CLASSE
void suppress(Livre* oeuvre){
	Livre* des=oeuvre.getAdresse();
	oeuvre.setAdresse(NULL);
	while(des!=NULL){
		Livre* tmp=des.getAdresse();
		des.setAdresse(NULL);
		des=tmp;
	}
}
Livre* duplicate(Livre* oeuvre){

}