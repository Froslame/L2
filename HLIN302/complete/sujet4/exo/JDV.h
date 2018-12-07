#ifndef __JDV_H
#define __JDV_H

#include <string>

#include "population-vivante.h"
#include "tabOptions.h"


#define HELP_ID          1
#define VERSION_ID       2
#define DIMENSION_ID    10
#define PROBABILITY_ID  11
#define CONFIG_ID       20

class JeuDeLaVie {
 private:
  PopulationVivante POP;
  
  void nettoie(std::string& s);
  bool findCleVal(std::string& a, std::string& b, std::string& s);
  void TraiteOption(const std::string &cle, const std::string &valeur, size_t num_ligne);

 public:
  JeuDeLaVie();

  void loadConfig(std::string config);
  void run(size_t);
void parseOptions(int argc, char** argv);
  
};

#endif
