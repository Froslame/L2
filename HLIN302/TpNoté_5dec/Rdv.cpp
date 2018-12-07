#include "Rdv.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Constructeurs
Rdv::Rdv(std::string nom,Rdv::TYPE type):
	_nom(nom), _type(type), _prochain(NULL) {}
//Accesseurs en Lecture
std::string Rdv::getNom()const { return _nom; }
Rdv::TYPE Rdv::getType()const { return _type; }
Rdv* Rdv::getSuivant()const { return _prochain; }
//Accesseurs en Ecriture
void Rdv::setSuivant(Rdv* suiv) { _prochain = suiv; }
//Autre