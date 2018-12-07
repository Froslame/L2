#include "cellule.h"
#include <iostream>
using namespace std;

//---Class cell----
cell::cell():x(0),y(0),vivante(false){};
cell::cell(unsigned int a,unsigned int b,bool vi):x(a),y(b),vivante(vi){};

bool cell::estVoisin(const cell &C)const{
  return(vivante && //(C.x==x-1||C.x==x+1) && (C.y==y+1||C.y==y-1) && (C.y!=y||C.x!=x));
   	 ((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y) <= 2));
	 }

unsigned int cell::getX()const{return x;}
unsigned int cell::getY()const{return y;}

void cell::setX(unsigned int _x){this->x=_x;}
void cell::setY(unsigned int _y){this->y=_y;}

bool cell::estVivante() const{return vivante;}

void cell::setVivante(bool vi){vivante = vi;}

//-------------------
/*
void test_cell(const cell &C){
  string tmp;
  if(C.vivante())tmp="vivante";else tmp="morte";
  cout<<"{"<<tmp<<", "<<C.x<<"x"<<C.y<<"}"endl;
}

void voisin(const cell &C1, const cell &C2){
  if(C1.estvoisine(C2))cout<<C2<<"est voisine de "<<C1<<endl;else cout<<C2<<"n'est pas voisine de "<<C1<<endl;
  if(C2.estvoisine(C1))cout<<C1<<"est voisine de "<<C2<<endl;else cout<<C1<<"n'est pas voisine de "<<C2<<endl;
}

void affichage(const cell &C1, const cell &C2){
  cout<<"L'objet "<<C1<<"est à l'adresse mémoire "<<&C1<<endl;
  cout<<"L'objet "<<C2<<"est à l'adresse mémoire "<<&C2<<endl;
  cout<<"La cellule (à l'adresse mémoire "<<&C1<<") = ";test_cell(&C1);
  cout<<"La cellule (à l'adresse mémoire "<<&C2<<") = ";test_cell(&C2);
  
}
*/
