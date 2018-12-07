#include <iostream>
#include <fstream>
#include <string>

#include "prog.h"

using namespace std;

//-------- CLASSE OPTION ----------

//Constructeur
option::option():id(-1),nom(),raccourci(),description(),type(AUCUN){}
option::option(int _id,string _nom,string _raccourci,string _desc,option::Type _type):
  id(_id),nom(_nom),raccourci(_raccourci),description(_desc),type(_type){}

//Lecture
int option::getId() const{return id;}
string option::getNom() const{return nom;}
string option::getRaccourci() const{return raccourci;}
string option::getDescription() const{return description;}
option::Type option::getType() const{return type;}
//Ecriture
void option::setId(int x){id=x;}
void option::setNom(string x){nom=x;}
void option::setRaccourci(string x){raccourci=x;}
void option::setDescription(string x){description=x;}
void option::setType(option::Type x){type=x;}
//Autre
void option::print() const{
  cout<<nom<<" ("<<raccourci<<") "<<type<<"\t"<<description<<endl;
}
