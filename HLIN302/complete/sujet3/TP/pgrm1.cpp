#include "pgrm.h"
#include "pgrm1.h"
#include <iostream>
#include <string>
using namespace std;

//--class Population
Population::Population() {
  for(size_t x=0;x<N;x++){
    for(size_t y=0;y<N;y++){
      Pop[x][y].setX(x);
      Pop[x][y].setY(y);
      Pop[x][y].setVivante(false);
    }
  }
}

Cellule Population::getXY(unsigned int x, unsigned int y)const{
  return Pop[x][y].print();
}

void Population::rdmGen(unsigned int k){
  unsigned int x,y;
  while(k!=0){
    x=rand()%N;
    y=rand()%N;
    if(Pop[x][y].getVivante()){}
    else{
      Pop[x][y].setVivante(true);
      k--;
    }
  }
}

size_t Population::nb_cellules(Cellule::Couleur c) const {
  size_t cpt=0;
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      if (CelluleEstDeLaCouleur(T[i][j],c)) {
	// if (T[i][j].getCouleur()==c){	
	cpt++;
      }
    }
  }
  return cpt;
}

size_t Population::nb_vivants()const {
  return N*N-nb_morts();}

size_t Population::nb_deces()const {
  return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);}

size_t Population::nb_morts()const {
  return nb_cellules(Cellule::NOIR);}

size_t Population::nb_naissances()const {
  return nb_cellules(Cellule::BLEU);}

