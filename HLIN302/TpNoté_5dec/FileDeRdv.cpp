#include "FileDeRdv.h"
#include <iostream>

//Constructeurs
FileDeRdv::FileDeRdv() : _debut(NULL), _fin(NULL) {}
//Destructeurs
FileDeRdv::~FileDeRdv(){ suppress(_debut); }
//Operateur
FileDeRdv* FileDeRdv::operator=(const FileDeRdv* X){
	//while(X.getSuivant != NULL)
		//_debut = X.getDeb();
	return this;
}
//Accesseurs en lecture
Rdv* FileDeRdv::getDeb()const { return _debut; }
Rdv* FileDeRdv::getFin()const { return _fin; }
//Acceseurs en Ecriture
void FileDeRdv::ajoutFin(Rdv* fin) {
	fin->setSuivant(NULL);
	_fin->setSuivant(fin);
	_fin=fin;
}
void FileDeRdv::retraitDeb(Rdv* deb){
	Rdv *tmp = _debut->getSuivant();
	_debut->setSuivant(NULL);
	_debut = tmp;
}


//HORS CLASSE
void suppress(Rdv* X){
	while(X->getSuivant()!=NULL){
		suppress(X->getSuivant());
		X->setSuivant(NULL);
	}
}
/*
Rdv* duplicate(const Rdv* X){
	Rdv *tmp=X;
	while(X->getSuivant()!=NULL){
		tmp->setSuivant(duplicate(X->getSuivant));
	}
	return tmp;
}
*/