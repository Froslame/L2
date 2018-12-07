#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "triRapide.h"

using namespace std;

void triRapide_aux(TableauCellule& T,size_t deb,size_t fin){
  
  size_t tmp_fin=fin;
  size_t tmp_deb=deb;
  size_t pivot = deb;
  Cellule tmp;

  while(deb != fin){
    if(deb == pivot){
      if((T.at(pivot)).estAvant(T.at(fin))){
        fin--;
      }
      else{
	tmp=T.at(pivot);
	T.at(pivot)=T.at(fin);
	T.at(fin)=tmp;
	pivot=fin;
	deb++;
      }
    }
    else{
      if((T.at(deb)).estAvant(T.at(pivot))){
        deb++;
      }
      else{
	tmp=T.at(pivot);
	T.at(pivot)=T.at(deb);
	T.at(deb)=tmp;
	pivot=deb;
	fin--;
      }
    }
  }
  
  if(tmp_deb<deb){
    triRapide_aux(T,tmp_deb,pivot-1);
  }
  if(fin<tmp_fin){
    triRapide_aux(T,pivot+1,tmp_fin);
  }
}

void triRapide(TableauCellule& T){
  triRapide_aux(T,0,T.size()-1);
}
