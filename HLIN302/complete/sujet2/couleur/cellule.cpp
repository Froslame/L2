#include "cellule.h"
#include <iostream>
#include <string>

using namespace std;

//---Class cell----
cell::cell():x(0),y(0),vivante(false),couleur(NOIR){};
cell::cell(unsigned int a,unsigned int b,bool vi):x(a),y(b),vivante(vi),couleur(vivante?BLEU:NOIR){};

bool cell::estVoisin(const cell &C)const{
  return(vivante && //(C.x==x-1||C.x==x+1) && (C.y==y+1||C.y==y-1) && (C.y!=y||C.x!=x));
   	 ((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y) <= 2));
	 }

unsigned int cell::getX()const{return x;}
unsigned int cell::getY()const{return y;}

void cell::setX(unsigned int _x){this->x=_x;}
void cell::setY(unsigned int _y){this->y=_y;}

bool cell::estVivante() const{return vivante;}

//void cell::setVivante(bool vi){vivante = vi;}

cell::Couleur cell::getCouleur()const{return couleur;}

//-------------------

void cell::setVivante(bool vi){
  if (vi) {
    couleur=vivante? VERT : BLEU;
  }else{
    couleur=NOIR;
  }
  vivante = vi;
}

bool CelluleEstDeLaCouleur(const cell &cellule, cell::Couleur col){
  return (cellule.cell::Couleur==col);
}
