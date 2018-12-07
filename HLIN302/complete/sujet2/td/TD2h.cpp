#include "TD2.h"
#include <iostream>
using namespace std;

//---------Class ItV-----------
Itv::Itv(float k, float p) : a(k), b(p) {
  if (a>b){float tmp=a; a=b; b=tmp;
    cout<<"Valeur echange"<<endl;
  }
}
Itv::Itv() : a(0.0), b(0.0) {}
//Lecture
float Itv::getSup()const{return b;}
float Itv::getInf()const{return a;}

void Itv::affiche()const{std::cout<<"["<<a<<";"<<b<<"]"<<std::endl;}
void Itv::longueur()const{return b-a;}

bool Itv::appart(float x)const{return (x<=b && x>=a);}

//Ecriture
void Itv::setSup(float sup){
  if(sup>=a) b=sup;
  else cout<<"Erreur"<<endl;
}
void Itv::setInf(float inf){a=inf;}

//--------Class Cpt----------
Cpt::Cpt():I1(0,0),I2(0,0);
Cpt::Cpt(Itv A,Itv B):I1(,),I2(,);
//Lecture
bool Cpt::egal()const;
bool Cpt::inclu()const;
bool Cpt::disjoint()const;
bool Cpt::accole()const;
bool Cpt::imbrique()const;
