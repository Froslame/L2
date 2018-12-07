#ifndef PROG_H
#define PROG_H

#include "cellule.h"

class TableauCellule{
 private:
  Cellule* Tab;
  size_t taille;
  size_t tailleMax;

  void extend();
 public:
  //Constructeur
  TableauCellule(size_t);
  TableauCellule(const TableauCellule&);
  //Operateur
  TableauCellule& operator=(const TableauCellule&);
  //Destructeur
  ~TableauCellule();
  //Lecture
  size_t getTaille()const;
  size_t getTailleMax()const;
  Cellule& at(size_t);
  const Cellule& at(size_t)const;
  //Flux
  void read(std::istream&);
  void write(std::ostream&)const;
  //Recherche
  int find(Cellule)const;
  //Ecriture
  void push_back(Cellule);
  void erase(Cellule);
};


#endif
