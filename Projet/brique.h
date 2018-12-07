#ifndef BRIQUE_H
#define BRIQUE_H

#include <string>

class Brique{
 private:
  int _hp;
  size_t _x,_y;
 public:
  //Constructeur
  Brique();
  Brique(int hp,size_t x,size_t y);
  //Destructeur
  //quand détruit remplace par un truc vide
  ~Brique();
  //Lecture
  int getX()const;
  int getY()const;
  int getHp()const;
  //Ecriture
  
  //Affichage
};

#endif
