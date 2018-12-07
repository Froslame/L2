#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "triBulle.h"
#include "rechDicho.h"
#include "triRapide.h"

using namespace std;

int main(int argc, char** argv){
  
  cout<<"-------------------------------"<<endl;
  size_t taille;
  cout<<"Donner la taille : ";
  cin>>taille;
  cout<<"----------AVANT-TRI------------"<<endl;
  
  srand(time(NULL));
  TableauCellule T(taille);
  for(size_t i=0;i<taille;i++){
    T.at(i).setX(rand() % taille);
    T.at(i).setY(rand() % taille);
  }
  TableauCellule P = T;
  
  T.write(cout);
  cout<<"----------APRES-TRI-BULLE------"<<endl;
  time_t start1 = time(NULL);
  triBulle(T);
  time_t fin1 = time(NULL);
  T.write(cout);

  size_t x=rand() % taille,y=rand() % taille;
  Cellule rech(false,x,y);
  
  cout<<"---------RECH-DICHO------------"<<endl;
  cout<<"On cherche la cellule : ";
  rech.print();
  
  int k = rechDicho(T,rech);
  if(k!=-1)
    cout<<"La cellule est dans le tableau"<<endl;
  else
    cout<<"La cellule n'est pas dans le tableau"<<endl;
  cout<<"----------AVANT-TRI------------"<<endl;
  P.write(cout);
  cout<<"----------APRES-TRI-RAPIDE-----"<<endl;
  time_t start2 = time(NULL);
  triRapide(P);
  time_t fin2 = time(NULL);
  P.write(cout);
  cout<<"------------DUREE--------------"<<endl;
  cout<<"Vitesse TriBulle : "<<difftime(fin1,start1)<<" sec"<<endl;
  cout<<"Vitesse TriRapide : "<<difftime(fin2,start2)<<" sec"<<endl;
  cout<<"-------------------------------"<<endl;
  
  return 0;
}
