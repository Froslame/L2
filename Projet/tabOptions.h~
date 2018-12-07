#ifndef TABOPTIONS_H
#define TABOPTIONS_H

#include <string>
#include "options.h"

#define NMAX_OPTS 5

class tabOptions {
 private:
  Options opts[NMAX_OPTS];
  size_t nb_opts;
  int getOptionIndex(const std::string &opt) const;
 public:
  //Constructeur
  tabOptions();
  //Operateur
  Options operator[](const size_t i);
  //Lecture
  int getOptionId(const std::string &opt) const;
  //Ecriture
  void addOption(const Options &o);
  //Affichage
  void print() const;
};

#endif
