#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "tabOptions.h"

using namespace std;

//Constructeur
tabOptions::tabOptions(): opts(), nb_opts(0) {}
//Operateur
Options tabOptions::operator[](size_t i){
  return opts[i];
}
//Lecture
int tabOptions::getOptionIndex(const string &opt) const {
  bool found = false;
  size_t i = 0;
  while (!found && (i < nb_opts)) {
    found = ((opts[i].getNom() == opt) || (opts[i].getRaccourci() == opt));
    i++;
  }
  return found ? i - 1 : -1;
}
int tabOptions::getOptionId(const std::string &opt) const {
  int i = getOptionIndex(opt);
  return (i>=0 ? opts[i].getId():-1);
}
//Ecriture
void tabOptions::addOption(const Options &o) {
  if (nb_opts == NMAX_OPTS) {
    cerr << "Erreur: Impossible d'ajouter une nouvelle option." << endl
	 << "        Nombre maximum d'option atteint"<< " (" << NMAX_OPTS << ")."
	 << endl;
    terminate();   
  }
  bool found=(getOptionIndex(o.getNom())!=-1)||(getOptionIndex(o.getRaccourci())!=-1);
  if(found){
    cerr << "Avertissement: L'identifiant " << o.getId() << " est déjà utilisé."
	 << endl;
  }else{
    opts[nb_opts] = o;
    nb_opts++;    
  }
}
//Affichage
void tabOptions::print() const {
  cout << "Options :" << endl;
  for (size_t i = 0; i < nb_opts; i++) {
    opts[i].print();
  }
}
