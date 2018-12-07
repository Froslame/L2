#include <iostream>
#include <fstream>
#include <string>

#include "triBulle.h"

using namespace std;

void triBulle(TableauCellule& T){
  size_t X = 1;
  Cellule tmp;
  bool check;
  while (X != T.size()){
      check = true;
      for(size_t i=0;i<T.size()-X;i++){
	if((T.at(i)).estAvant(T.at(i+1))){
	  tmp=T.at(i+1);
	  check=false;
	  T.at(i+1)=T.at(i);
	  T.at(i)=tmp;
	}
      }
      if (check) return;
      X++;
    }
}
