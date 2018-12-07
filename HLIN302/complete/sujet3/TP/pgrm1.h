#ifndef __PGRM1_H
#define __PGRM1_H

#include <string>

#define N 5

class Population{
 private:
  Cellule Pop[N][N];

  size_t nb_cellule(Cellule::Couleur)const;
  
 public:
  //Constructeur
  Population();

  void rdmGen(unsigned int k);
  
  //Acces Lecteur
  Cellule getXY(unsigned int x, unsigned int y)const;
  
  //Acces Interrogation
  unsigned int nb_vivants()const;
  unsigned int nb_deces()const;
  unsigned int nb_morts()const;
  unsigned int nb_naissances()const;

  
};


#endif
