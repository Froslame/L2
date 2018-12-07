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


Dico creerDico(bool b, Dico G, Dico D){
  /* Res : renvoie une Dico dont la racine vaut e, le sag G et le sad D   */
  Dico A = new NoeudSC;
  A->info=b;  A->sag=G;  A->sad=D;
  return A;}

void codageABdot(ofstream& fichier, Dico A){
  if (A != NULL){ 
    fichier << (long) A << " [label=\""  << (A->info?"true":"false") << "\" ] ;\n";
    if (A->sag != NULL) {
      fichier << (long)A << " -> " << (long)(A->sag) <<  " [color=\"red\",label=\"0\" ] ;\n";
      codageABdot(fichier,A->sag);} 
    if (A->sad != NULL) {
      fichier << (long)A << " -> " << (long)(A->sad) << " [color=\"blue\",label=\"1\" ] ;\n";
      codageABdot(fichier,A->sad);}
  }
  return;}


void dessinerAB(Dico A, const char * nomFic, string titre){
  ofstream f(nomFic);
  if (!f.is_open()){
   cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
  }
  else {
    f<< "digraph G {   label = \""<< titre << "\" \n";
    f<< "graph [ fontname=""fixed"", fontsize = 20];";
    f<< "node [ fontname=""fixed"", fontsize = 20];";
    f<< "edge [ fontname=""fixed"", fontsize = 20];";
    codageABdot(f,A);
    f << "\n }\n" ;
    f.close();}
  return;}


/* A COMPLETER */
int nbMots(Dico A){
  // renvoie le nombre de mots du dictionnaire A 
  /* A MODIFIER  */
	int nbr=0;
	if (A->info == true)
		nbr++;
	if(A->sag != NULL)
		nbr+=nbMots(A->sag);
	if(A->sad != NULL)
		nbr+=nbMots(A->sad);
  return nbr;
}


bool appMot(Dico D, ListeSC L){
  // teste si le mot L appartient au dictionnaire D
  /* A MODIFIER  */
	if(D == NULL)
		return false;
	if (L != NULL){
		if(L->info == 0){
			if(D->sag != NULL)
				return appMot(D->sag,L->succ);
			return false;
		}else{
			if(D->sad != NULL)
				return appMot(D->sad,L->succ);
			return false;
		}
	}else{
		return D->info;
	}
}

void ajouterMot(Dico &A,ListeSC L){
  // ajoute le mot L au dictionnaire A
  /* A MODIFIER  */
	if(A == NULL){
		Dico B = creerDico(false,NULL,NULL);
		Dico C = creerDico(false,NULL,NULL);
		A=creerDico(false,B,C);
	}
	if(L != NULL){
		if(L->info == 0){
			if(A->sag == NULL){
				Dico B = creerDico(false,NULL,NULL);
				A->sag = B;
			}
			ajouterMot(A->sag,L->succ);
		}
		if(L->info == 1){
			if(A->sad == NULL){
				Dico C = creerDico(false,NULL,NULL);
				A->sad = C;
			}
			ajouterMot(A->sad,L->succ);
		}
	}else{
		A->info = true;
	}
}

void supprimerMot(Dico &A,ListeSC L){
  // supprime le mot L du dictionnaire A
  /* A MODIFIER  */
	if(A != NULL){
		if(L != NULL){
			if(L->info == 0){
				if(A->sag == NULL){
					Dico B = creerDico(false,NULL,NULL);
					A->sag = B;
				}
				supprimerMot(A->sag,L->succ);
			}else{
				if(A->sad == NULL){
					Dico C = creerDico(false,NULL,NULL);
					A->sad = C;
				}
				supprimerMot(A->sad,L->succ);
			}
		}else{
			A->info = false;
		}
	}
}

int lgMin(Dico A){
  // A un un arbre dictionnaire contenant au moins un mot
  // renvoie la longueur du plus petit mot du dictionnaire A
  assert(nbMots(A)>0);
  /* A MODIFIER  */
  	if(A!=NULL){
  		if(A->info)	
  			return 1;
  		int x = 1+lgMin(A->sag);
  		int y = 1+lgMin(A->sad);
  		if(x>y)
  			return y;
  		return x;
  	}
  return 0;
}

bool contientPrefixe(Dico A){
  // Renvoie true si le dictionnaire contient au moins un mot et l'un de ses préfixes, renvoie false sinon
  /* A MODIFIER  */
	bool a,b;
	if(A!=NULL){
		if(A->info){
			if(contientPrefixe(A->sag))
				return true;
			if(contientPrefixe(A->sad))
				return true;
		}else{
			a = contientPrefixe(A->sag);
			b = contientPrefixe(A->sad);
		}
	}
  return (a||b);
}

ListeSC motMin(Dico A){
  // A un Dictionnaire non vide
  // Renvoie le plus petit mot du dictionnaire dans l'ordre lexicographique (du dictionnaire)
  assert(nbMots(A)>0);
/*  CODE PAS FINI DONC MIS EN COMMENTAIRE POUR EVITER ERREUR DE COMPILATION
  ListeSC L;
  if(A!=NULL){
  	if((A->sag == NULL)&&(A->sad == NULL)){
  		if(A->info)
  			return L;
  	}if(A->sag != NULL){
  		insererFinLSC(L,0);
  		concatLSC(L,motMin(A->sag));
   	}else{
   		if(A->sad != NULL){
   			insererFinLSC(L,1);
   			concatLSC(L,motMin(A->sad));
   		}
   	}
  }*/
  return NULL;
}

