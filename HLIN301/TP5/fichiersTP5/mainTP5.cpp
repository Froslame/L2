#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP5.h"
using namespace std;


/*****************************************************************************/
/*                                                                           */
/*                              main                                         */
/*                                                                           */
/*****************************************************************************/
int main(int argc, char *argv[]){
  int q;
  
  Dico B,C,D;
  ostringstream stre;
  ListeSC L;
  string  chaine;

  B=creerDico(false,
	      creerDico(false,
				creerDico(true,NULL,NULL),
				creerDico(true,
					      NULL,
					      creerDico(false,
							    NULL,
							    creerDico(true,
									  creerDico(false,NULL,NULL),
									  creerDico(true, 
											NULL,
											NULL))))),
		  creerDico(true,
				creerDico(false,
					      creerDico(true,NULL,NULL),
					      NULL),
				creerDico(true,NULL,NULL)));
  C=NULL;
  D= creerDico(false,C,C);
  cout << "Numero de la question traitee (1/2/3/4/5/6/7) ? ";
  cin >> q;
  switch (q){
  case 1 :
    dessinerAB(B,"arbre.dot","Dictionnaire");
    cout << "nombre de mots :"<< nbMots(B) << endl;
    system("dotty arbre.dot");
    break;
  case 2 :
    dessinerAB(B,"arbre.dot","Dictionnaire");
    system("dotty arbre.dot&");
    L=lireLSC();
    cout << "Ce mot " << (appMot(B,L)?"appartient ":"n'appartient pas ")<< "au dictionnaire"<< endl;
    break;
  case 3 :
    dessinerAB(D,"arbre.dot","Dictionnaire");
    system("dotty arbre.dot&");
    L=lireLSC();
    ajouterMot(D,L);
    dessinerAB(D,"arbre2.dot","Dictionnaire apres ajout du mot");
    system("dotty arbre2.dot&");
    break;
  case 4 :
    dessinerAB(B,"arbre.dot","Dictionnaire");
    system("dotty arbre.dot&");
    L=lireLSC();
    supprimerMot(B,L);
    dessinerAB(B,"arbre2.dot","Dictionnaire apres suppression du mot");
    system("dotty arbre2.dot&");
    break;
  case 5 :
    dessinerAB(B,"arbre.dot","Dictionnaire");    
    cout << "longueur du plus petit mot : " << lgMin(B) << endl;
    system("dotty arbre.dot");
    break;
  case 6 :
    dessinerAB(B,"arbre.dot","Dictionnaire");
    cout << "le dico "<< (contientPrefixe(B)?"contient " : "ne contient pas ") << "un mot et l'un de ses prefixes"<< endl;
    system("dotty arbre.dot&");
    break;
  case 7 :
    dessinerAB(B,"arbre.dot","Dictionnaire");
    cout <<" le plus petit mot du dictionnaire est ";
    afficherLSC(motMin(B));
    system("dotty arbre.dot&");
    break;

    
  }
  return 0;
}
