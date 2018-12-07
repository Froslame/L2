#ifndef trigen_H
#define trigen_H

#include "cellule.h"
#include "myvector.h"

template<typename T>
bool estEgal(const T& x,const T& y){ return x==y; }

template<typename T>
bool estAvant(const T& x,const T& y){ return x<y; }

template<typename T>
bool estApres(const T& x,const T& y){ return x>y; }

template<>
bool estEgal(const Cellule& a,const Cellule& b){ return a.estEquivalente(b);}

template<>
bool estAvant (const Cellule& a,const Cellule& b){ return a.estAvant(b);}

template<>
bool estApres(const Cellule& a,const Cellule& b){ return a.estApres(b);}

template<typename TAB,typename C>
size_t rechercheDichotomique(const TAB &T, const C& c){
  size_t deb=0,fin=T.size();
  size_t res=(size_t)-1;
  while((res==(size_t)-1)&&(deb<fin)){
    size_t mid = (deb+fin)/2;
    if(estEgal(c,T.at(mid))){
      res=mid;
    }else{
      if(estAvant(c,T.at(mid)))
        fin=mid;
      else
        deb=mid+1;
    }
  }
  return res;
}

template<typename T>
void echanger(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<typename VECT>
void triBulle(VECT &T) {
  bool modif = true;
  size_t n = T.size();
  while (modif && n--) {
    modif = false;
    for (size_t i = 0; i < n; i++) {
      if (estAvant(T.at(i+1),T.at(i))) {
        echanger(T.at(i), T.at(i+1));
        modif = true;
      }
    }
  }
}

template<typename VECT>
void triRapide_aux(VECT &T, size_t deb, size_t fin) {
  if (deb >= fin) return;
  size_t d = deb, f = fin-1, pivot;
  pivot = (deb + fin) / 2;
  while (d < f) {
    while ((d < pivot) && !estApres(T.at(d),T.at(pivot))) {
      d++;
    }
    while ((pivot < f) && !estAvant(T.at(f),T.at(pivot))) {
      f--;
    }
    echanger(T.at(d), T.at(f));
    if (pivot == d) {
      pivot = f++;
    } else {
      if (pivot == f) {
        pivot = d--;
      }
    }
    d++;
    f--;
  }
  triRapide_aux(T, deb, pivot);
  triRapide_aux(T, pivot + 1, fin);
}

template<typename VECT>
void triRapide(VECT &T) {
  triRapide_aux(T, 0, T.size()-1);
}

#endif
