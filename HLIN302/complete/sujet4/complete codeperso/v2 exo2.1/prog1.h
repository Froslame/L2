#ifndef PROG2_H
#define PROG2_H

#include <string>

#define N 10

using namespace std;

class tabOption{
 private:
  option tab[N];
  size_t taille;
  int getOptionIndex(string) const;
 public:
  //Constructeur
  tabOption();
  
  //Lecture
  int getOptionId(string) const;
  bool optionHasArgument(string) const;
  
  //Ecriture
  void addOption(option);  

  //Autre
  void print() const;
};

#endif
