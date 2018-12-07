#include "Livre.h"
#include <iostream>
#include <string>
using namespace std;

//Constructeurs
Livre::Livre(std::string titre,std::string auteur,size_t date,Livre::Genre genre):
	_titre(titre), _auteur(auteur), _date(date), _genre(genre), _adresse(NULL){}
//Accesseurs en lecture
std::string Livre::getTitre()const { return _titre; }
std::string Livre::getAuteur()const { return _auteur; }
size_t Livre::getDate()const { return _date; }
Livre::Genre Livre::getGenre()const { return _genre; }
Livre& Livre::getAdresse()const { return _adresse; }
//Accesseurs en écriture
void Livre::setAdresse(int adresse) { _adresse=adresse; }
//Autre
void Livre::affiche()const{
	cout<<_titre<<","<<_auteur<<","<<_date<<","<<_genre<<",("<<_adresse<<"eme : position)"<<endl;
}