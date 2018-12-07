#ifndef cell_H
#define cell_H

#include <string>

class cell{
 public:
  enum Couleur{
    NOIR, //0
    BLEU, //1
    VERT, //2
    ROUGE,//3
    NB_COULEURS,//4 
  };
  
 private:
  unsigned int x,y;
  bool vivante;
  Couleur couleur;
  

 public:
  //Constructeur
  cell();
  cell(unsigned int,unsigned int,bool);
  //Lecture
  unsigned int getX()const;
  unsigned int getY()const;
  bool estVivante()const;
  Couleur getCouleur()const;
  //Ecriture
  void setVivante(bool);
  void setX(unsigned int);
  void setY(unsigned int);
  //Autre
  bool CelluleEstDeLaCouleur(const cell&, cell::Couleur);
  bool estVoisin(const cell&)const;
};

std::string Couleur2String(cell::Couleur);

#endif
