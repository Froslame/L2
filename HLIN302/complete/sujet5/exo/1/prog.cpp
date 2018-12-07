#include <iostream>
#include <fstream>
#include <string>

#include "prog.h"

using namespace std;

//Constructeur
TableauInt::TableauInt(size_t taille) : Tab(new int[taille]), taille(taille) , tailleMax(taille){}
TableauInt::TableauInt(const TableauInt& T) : Tab(new int[T.taille]), taille(T.taille), tailleMax(taille){
  for(size_t i=0;i<taille;i++){
    Tab[i]=T.Tab[i];
  }
}
//Operateur
TableauInt& TableauInt::operator=(const TableauInt& T){
  if(this != &T){
    delete[] Tab;
    Tab=new int[T.taille];
    taille=T.taille;
    tailleMax=T.tailleMax;
    for(size_t i=0;i<taille;i++){
      Tab[i]=T.Tab[i];
    }
  }
  return *this;
}
//Destructeur
TableauInt::~TableauInt(){delete[] Tab;}
//Lecture
size_t TableauInt::getTaille()const{return taille;}
size_t TableauInt::getTailleMax()const{return tailleMax;}

int& TableauInt::at(size_t i){return Tab[i];}
const int& TableauInt::at(size_t i)const{return Tab[i];}


//Ecriture
void TableauInt::push_back(int k){
  if(taille<tailleMax)extend();
  Tab[taille]=k;
  taille++;
}
void TableauInt::extend(){
  int* T = new int[2*taille];
  for(size_t i=0;i<taille;i++){
    T[i]=Tab[i];
  }
  delete[] Tab;
  Tab=T;
}
//####################

void write(ostream& os, const TableauInt& T){
  for(size_t i=0;i<T.getTaille();i++)
    os<<T.at(i)<<" ";
  os<<endl;
}
