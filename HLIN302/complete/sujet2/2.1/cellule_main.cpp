#include "cellule.h"
#include <iostream>
using namespace std;

void test_cell(const cell &c) {
  cout << "La cellule (à l'adresse mémoire " << &c << ") = {"
       << (c.estVivante() ? "vivante" : "morte")
       << ", " << c.getX() << "x" << c.getY() << "}"
       << endl;
}

#define PrintCell(c) \
  cout << "L'objet " #c " est à l'adresse mémoire " \
       << &c << endl

#define PrintVoisines(c1, c2)				\
  cout << "La cellule " #c1 " "				\
       << (c1.estVoisin(c2) ? "est" : "n'est pas")	\
       << " voisine de " #c2 "." << endl

int main() {
  cell c1(true, 1, 2), c2;
  c2.setVivante(!c2.estVivante());
  c2.setX(c1.getX());
  c2.setY(c1.getX() + c1.getY());
  PrintCell(c1); PrintCell(c2);
  test_cell(c1); test_cell(c2);
  PrintVoisines(c1, c2); PrintVoisines(c2, c1);
  return 0;
}
