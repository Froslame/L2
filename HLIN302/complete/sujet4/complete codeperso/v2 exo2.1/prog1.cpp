#include <iostream>
#include <fstream>
#include <string>

#include <exception> //terminate

#include "prog.h"
#include "prog1.h"

using namespace std;

//-------- CLASSE TAB_OPTION ----------

//Constructeur
tabOption::tabOption(): tab(), taille(0) {}

//Lecture
int tabOption::getOptionIndex(string opt) const {
  bool found = false;
  size_t i = 0;
  while (!found && (i < taille)) {
    found = ((tab[i].getNom() == opt) || (tab[i].getRaccourci() == opt));
    i++;
  }
  return found ? i - 1 : -1;
}

int tabOption::getOptionId(string k) const {
  int i = getOptionIndex(k);
  return (i>=0 ? tab[i].getId():-1);
}

bool tabOption::optionHasArgument(string k) const {
  size_t i = getOptionIndex(k);
  return (tab[i].getType() != option::AUCUN);
}

//Ecriture
void tabOption::addOption(option o) {
  if (taille == N) {
   cerr << "Erreur: Impossible d'ajouter une nouvelle option." << endl
	<< "        Nombre maximum d'option atteint"<< " (" << N << ")."
	<< endl;
   terminate();   
  }
    
  bool found = (getOptionIndex(o.getNom()) !=  -1) || (getOptionIndex(o.getRaccourci()) !=  -1);
  
  if (found) {
    cerr << "Avertissement: L'identifiant " << o.getId() << " est déjà utilisé."
	 << endl;
  } else {
    tab[taille] = o;
    taille++;    
  }
}

//Autre
void tabOption::print() const{
  cout<<"Options :"<<endl;
  for (size_t i = 0;i<taille;i++){
    tab[i].print();
  }
}
