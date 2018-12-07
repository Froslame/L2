#include <iostream>
#include <fstream>
#include <string>

#include "rechDicho.h"

using namespace std;

int rechDicho(const TableauCellule& T,const Cellule& C){
  int mil,deb=0,fin=T.size()-1;
  while(deb<=fin){
    mil=(deb+fin)/2;
    if(T.at(mil).estEquivalente(C))
      return mil;
    if(T.at(mil).estAvant(C)){
      fin=mil-1;
    }else{
      deb=mil+1;
    }
  }
  return -1;
}
