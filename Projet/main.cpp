#include <iostream>
#include <fstream>
#include <string>


#include <exception>

#include "comOptions.h"

using namespace std;

/*
#############################
#   espace lance la balle   #
#gauche droit en déplacement#
#   q quitte la partie      #
#############################
*/

void startProgram(int argc,char** argv){
  if(argc>4){
    cerr<<"SURCHARGE OPTION"<<endl;
    terminate();
  }
  tabOptions opts=listOptions(argc,argv);
  LoadOptions(opts,argc,argv);
}




int main(int argc, char** argv){
  startProgram(argc,argv);//Initialise le jeu
  //myProgram();//Le jeu
  //stopProgram();//Stop le jeu
  return 0;
}
