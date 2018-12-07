#include <iostream>

#include "option.h"
#include "tabOptions.h"
#include "cellule.h"
#include "population-vivante.h"
#include "JDV.h"

using namespace std;


int main(int argc, char** argv) {
  
  JeuDeLaVie JDV;
  JDV.parseOptions(argc,argv);
  JDV.run(4);
  
  return 0;
}

