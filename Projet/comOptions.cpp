#include <iostream>
#include <fstream>
#include <string>

#include "comOptions.h"

using namespace std;

tabOptions listOptions(int argc,char** argv){
  tabOptions opts;
  opts.addOption(Options(1, "--help", "-h",
			 "Affiche l'aide du programme"));
  opts.addOption(Options(2, "--version", "-v",
			 "Affiche la version"));
  opts.addOption(Options(3, "--auteur", "-a",
			 "Affiche l'auteur"));
  return opts;
}

void LoadOptions(tabOptions opts,int argc,char** argv){
  for (int i = 1; i < argc ; i++) {
    switch(opts.getOptionId(argv[i])){
    case 1:
      cout<<"aide"<<endl;
      break;
    case 2:
      cout<<"version"<<endl;
      break;
    case 3:
      cout<<"auteur"<<endl;
      break;
      default:
	break;
    }
  }
}
