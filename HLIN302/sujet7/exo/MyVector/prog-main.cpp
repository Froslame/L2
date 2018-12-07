#include <iostream>
#include <fstream>
#include <string>

#include "myvector.h"

#include <vector>
#include "cellule.h"
template<typename T>
void write(std::ostream& os,const vector<T> &X){
  os<<"affichage : ";
  for(size_t i=0;i<X.size();i++){
    os<<X.at(i)<<(i!=X.size()-1?",":"");
  }
  os<<std::endl;
}

template<>
void write<Cellule>(std::ostream& os, const vector<Cellule>& T){
  os<<"affichage cellule: ";
  for(size_t i=0;i<T.size();i++){
    write_cell(os,T.at(i));
    os<<(i!=T.size()-1?",":"");
  }
  os<<std::endl;
} 	


using namespace std;

int main(int argc, char** argv){
  
  //MyVector<int> T1;
  //MyVector<double> T2;
  //MyVector<Cellule> T3;
  vector<int>T1;
  vector<double>T2;
  
  vector<Cellule>T3;
  
  for(size_t i=1;i<10;i++){
    T1.push_back(i);
    T3.push_back(Cellule(true,i,i));
    T2.push_back(1./i);
  }
  write(cout,T1);
  write(cout,T2);
  write(cout,T3);
  
  return 0;
}
