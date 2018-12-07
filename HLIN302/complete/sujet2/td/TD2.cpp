#include <iostream>

#include "TD2.cpp"

int main(){
  Itv I1(1,5);
  const Itv I2(2.4,3);

  I1.affiche();
  I2.affiche();

  I1.setSup(10);
  I1.setInf(0);

  I1.appart(7);
  
  return 0;
}
