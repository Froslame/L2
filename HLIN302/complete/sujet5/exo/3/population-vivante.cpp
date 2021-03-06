#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include "prog.h"
#include "population-vivante.h"
using namespace std; 

#define CHECK_BOUND(i,j)						\
  if (i>=N || j>=N){							\
    std::cout<<"Accessing a Cell at ("<<i<<","<<j<<") out of range ... aborting"<<std::endl; \
    std::terminate();							\
  }									\

//parcours les éléments vivants
const Cellule* PopulationVivante::at(size_t i, size_t j) const {
  for (size_t k = 0 ; k < alive ; k++) {
    if ((T[k].getX() == i) && (T[k].getY() == j)) {
      return T+k; //T[k]
    }
  }
  return NULL;
}
Cellule* PopulationVivante::at(size_t i, size_t j)  {
  for (size_t k = 0 ; k < alive ; k++) {
    if ((T[k].getX() == i) && (T[k].getY() == j)) {
      return T+k;
    }
  }
  return NULL;
}

size_t PopulationVivante::nb_voisins_vivants(size_t ci, size_t cj) const {
  size_t cpt=0;
  size_t imin,imax,jmin,jmax;
  imin = ci==0?ci:ci-1;
  imax = ci==(N-1)?ci:ci+1;
  jmin = cj==0?cj:cj-1;
  jmax = cj==(N-1)?cj:cj+1;
  
  for (size_t i = imin ; i <= imax ; i++) {
    for (size_t j = jmin ; j <= jmax ; j++) {
      if (at(i,j) != NULL) {
	cpt++;
      }
    }
  }
  return cpt - (at(ci,cj) != NULL ? 1 : 0);
}

void PopulationVivante::updateColors() {
  //calcule les cellules vivantes qui vont mourir  
  for (size_t i = 0; i < alive;
    size_t voisin=nb_voisins_vivants(T[i].getX(), T[i].getY());
    if ((voisin != 2) && (voisin != 3)) T[i].doitMourir();  
  }
}


PopulationVivante::PopulationVivante(size_t n) :T(), alive(0), N(n) {
  reset();
}

PopulationVivante::~PopulationVivante(){delete T[];}


void PopulationVivante::init(size_t n) {
  srand(time(NULL));
  if (nb_vivants() == 0) {
    size_t i,j;
    for (size_t k = 0 ; k < n ; k++) {
      do {
	i=rand()% N;
	j=rand()% N;
      } while (at(i,j) != NULL);
      T[k]=Cellule(true,i,j);
      alive++;
    }
    updateColors();
  }
}
size_t PopulationVivante::nb_cellules(Cellule::Couleur c) const {
  size_t cpt=0;
  for (size_t i = 0 ; i < alive ; i++) {
      if (CelluleEstDeLaCouleur(T[i],c)) {
	cpt++;
      }    
  }
  return cpt;
}

size_t PopulationVivante::nb_vivants()    const { return alive;}
size_t PopulationVivante::nb_deces()     const { return nb_cellules(Cellule::ROUGE)+nb_cellules(Cellule::JAUNE);}
size_t PopulationVivante::nb_morts()      const { return N*N-alive;} 
size_t PopulationVivante::nb_naissances() const { return nb_cellules(Cellule::BLEU);}


Cellule PopulationVivante::getCelluleCopie(size_t i, size_t j) const {
  CHECK_BOUND(i,j);
  const Cellule* ptr=at(i,j);
  if (ptr==NULL) {
    return Cellule(false,i,j);
  } else {
    return *ptr;
  }
}

void PopulationVivante::printCell(size_t i, size_t j) const {
  CHECK_BOUND(i,j);
  getCelluleCopie(i,j).print();
}   

void PopulationVivante::kill(size_t i, size_t j) {
  CHECK_BOUND(i,j);
   Cellule* ptr=at(i,j);
  if (ptr!=NULL) {
    size_t k=ptr-T; // retrouve la position dans le tableau
    for ( ; k < alive - 1 ; k++) {
      T[k]=T[k+1];
    }
    alive--;
  }
}

void PopulationVivante::birth(size_t i, size_t j) {
  if (alive+1<N){
    CHECK_BOUND(i,j);
    Cellule* ptr=at(i,j);
    if (ptr==NULL) {
      T[alive]=Cellule(true,i,j);    
      alive++;
    }
    else{
      ptr->setVivante(true);
    }
  }
  else {
    std::cerr<<"PopulationVivante: Erreur -> trop de cellule vivante pour NMAX="<<N<<std::endl;
    std::cerr<<"aborting...\n";
    std::terminate();
  }
}

void PopulationVivante::print() const {
  for (size_t i = 0; i < N + 2 ; i++) {
    cout << "X";
  }
  cout<<endl;
  for (size_t i = 0 ; i < N ; i++) {
    cout<<"X";
    for (size_t j = 0 ; j < N ; j++) {
      cout<<Couleur2String(getCelluleCopie(i,j).getCouleur());
    }
    cout<<"X"<<endl;
  }
  for (size_t i = 0 ; i < N + 2 ; i++) {
    cout<<"X";
  }
  cout<<endl;
}

PopulationVivante PopulationVivante::next() const {
  PopulationVivante POP(*this);  
  for (size_t i = 0 ; i < N ; i++) {
    for (size_t j = 0 ; j < N ; j++) {
      size_t voisin=nb_voisins_vivants(i,j);
      if ((voisin == 3) || ((voisin == 2) && (at(i,j) != NULL))) {
	POP.birth(i,j);
      } else {
	POP.kill(i,j);
      }
    }
  }
  POP.updateColors();
  return POP;
}

//----------TD4

//Constructeur
PopulationVivante::PopulationVivante(size_t n,float proba){}
//Lecture
float PopulationVivante::getProbability(){
  return probability;
}
int PopulationVivante::getDimension(){
  return N;
}
//Ecriture
void PopulationVivante::setProbability(float x){
  probability = x;
  reset();
}
void PopulationVivante::setDimension(int x){
  N=x;
  reset();
}
//Autre
void PopulationVivante::reset(){
  alive=0;
  srand(time(NULL));
  for(size_t i=0;i<N;i++){
    for(size_t j=0;i<N;j++){
      if(((rand()%10000))<=10000*probability)
	birth(i,j);
      else
	kill(i,j);
    }
  }
}
//----Dynamique
int PopulationVivante::find(Cellule k)const{
  for(size_t i=0;i<N;i++){
    if(T[i].getX()==k.getX() && T[i].getY()==k.getY())
      return i;
  }
  return -1;
}
//Flux
void PopulationVivante::print(std::ofstream& of)const{
  string txt;
  of.open("config.txt",ios::out||ios::app);
  for(size_t i;i<taille;i++){
    of<<;
  }
  of.close();
}
/*
}
for(int i=1; i<argc ; i++){
cout<<"Fichier : "<<i<<endl<<endl;
X.open(argv[i],ios::in);
while(!X.eof()){
getline(X,l,'\n');
cout<<l<<endl;
}
X.close();
*/
