#include <iostream>
#include <fstream>
#include <string>

#include "prog.h"
#include "cellule.h"

using namespace std;

//Autre
void TableauCellule::extend(){
  if(taille==tailleMax){
    tailleMax*=2;
    Cellule* T = new Cellule[tailleMax];
    for(size_t i=0;i<taille;i++){
      T[i]=Tab[i];
    }
    delete[] Tab;
    Tab=T;
  }
}
//Constructeur
TableauCellule::TableauCellule(size_t x):Tab(new Cellule[x+1]), taille(x), tailleMax(x+1){}
TableauCellule::TableauCellule(const TableauCellule& T):Tab(new Cellule[T.tailleMax]), taille(T.taille), tailleMax(T.tailleMax){
  for(size_t i=0;i<taille;i++)Tab[i]=T.Tab[i];
}
//Operateur
TableauCellule& TableauCellule::operator=(const TableauCellule& T){
  if(this != &T){
    delete[] Tab;
    Tab=new Cellule[T.tailleMax];
    taille=T.taille;
    tailleMax=T.tailleMax;
    for(size_t i=0;i<taille;i++)Tab[i]=T.Tab[i];
  }
  return *this;
}
//Destructeur
TableauCellule::~TableauCellule(){delete[] Tab;}
//Lecture
size_t TableauCellule::getTaille()const{return taille;}
size_t TableauCellule::getTailleMax()const{return tailleMax;}
Cellule& TableauCellule::at(size_t i){return Tab[i];}
const Cellule& TableauCellule::at(size_t i)const{return Tab[i];}

//Flux
void TableauCellule::read(std::istream& is){
  for(size_t i=0;i<taille;i++){
    size_t x,y,c;
    is>>x>>y>>c;
    Tab[i].setX(x);
    Tab[i].setY(y);
    Tab[i].setVivante(c);
  }
}
void TableauCellule::write(std::ostream& os)const{
  for(size_t i=0;i<taille;i++){
    os<<Tab[i].getX()<<" "<<Tab[i].getY()<<" "<<Tab[i].getVivante()<<endl;
  } 
}

//Recherche
int TableauCellule::find(Cellule k)const{
  for(size_t i=0;i<taille;i++){
    if(Tab[i].getX()==k.getX() && Tab[i].getY()==k.getY()
       && Tab[i].getVivante()==k.getVivante() && Tab[i].getCouleur()==k.getCouleur())
      return i;
  }
  return -1;
}

//Ecriture
void TableauCellule::push_back(Cellule k){
  extend();
  Tab[taille]=k;
  taille++;
}
void TableauCellule::erase(Cellule k){
  int verif=find(k);
  if(verif == -1)return;
  taille--;
  tailleMax--;
  for(size_t i = verif;i<taille;i++){
    Tab[i]=Tab[i+1];
  }
}

//######################

