#include <iostream>
#include <fstream>
#include <string>

#include "prog.h"
#include "prog1.h"

using namespace std;

#define HELP_ID          1
#define VERSION_ID       2
#define DIMENSION_ID    10
#define PROBABILITY_ID  11
#define CONFIG_ID       20

int main(int argc, char** argv){
  
  tabOption opts;
  
  opts.addOption(option(HELP_ID, "--help", "-h",
			"Affiche l'aide du programme", option::AUCUN));
  opts.addOption(option(VERSION_ID, "--version", "-v",
			"Affiche la version du programme", option::AUCUN));
  opts.addOption(option(DIMENSION_ID, "--dimension", "-N",
			"Initialise une matrice carrée de la dimension spécifiée",option::ENTIER));
  opts.addOption(option(PROBABILITY_ID, "--probability", "-p",
			"Probabilité d'une cellule d'être en vie au démarrage",option::REEL));
  opts.addOption(option(CONFIG_ID, "--config", "-f",
			"Charge la configuration initiale du jeu à partir du fichier passé en paramètre",option::CHAINE));

  if (argc < 2) {
    cout<<"Aucune option fournis"<<endl;
    return 1;
  }
  
  cout << "Options passées en ligne de commande au programme "
       << argv[0] << " :" << endl;

  for (int i = 1; i < argc ; i++) {
    if (opts.getOptionId(argv[i]) != -1) {
      cout << "L'option " << argv[i] << " a été trouvée.";
      if (opts.optionHasArgument(argv[i])) {
	cout << " Elle attend un argument de type "
	     <<"//"; //Type2String(opts.optionHasArgument(argv[i]));
	cout << " => " << (++i < argc ? argv[i] : "Erreur");
      }
      cout << endl; 
    } else {
      cout << "Usage : " << argv[0] << " [Options]" << endl;
      opts.print();
      return 1;
    }
  }
  
  return 0;
}
