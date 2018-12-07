#include <iostream>
#include <fstream>
#include <string>

#include "options.h"

using namespace std;

//Constructeur
Options::Options(): id(-1), nom(), raccourci(), description(){}
Options::Options(int x, const string &name, const string &racc, const string &desc):
  id(x), nom(name), raccourci(racc), description(desc){}
//Lecture
int Options::getId()const{return id;}
std::string Options::getNom()const{return nom;}
std::string Options::getRaccourci()const{return raccourci;}
std::string Options::getDescription()const{return description;}
//Ecriture
void Options::setId(int x){id=x;}
void Options::setNom(const std::string &x){nom=x;}
void Options::setRaccourci(const std::string &x){raccourci=x;}
void Options::setDescription(const std::string &x){description=x;}
//Affichage
void Options::print()const{
  cout<<nom<<" ( "<<raccourci<<" ) "<<"\t"<<description<<endl;
}
