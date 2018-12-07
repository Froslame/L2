#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

typedef struct noeud {
  int info;
  struct noeud *sag;
  struct noeud *sad;} NoeudSC;
typedef NoeudSC *ArbreBin;

ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D){
  /* Res : renvoie une ArbreBin dont la racine vaut e, le sag G et le sad D   */
  ArbreBin A = new NoeudSC;
  A->info=e;  A->sag=G;  A->sad=D;
  return A;}
  
void codageABdot(ofstream& fichier, ArbreBin A){
  if (A != NULL){ 
    fichier << (long) A << " [label=\""  << A->info << "\" ] ;\n";
    if (A->sag != NULL) {
      fichier << (long)A << " -> " << (long)(A->sag) <<  " [color=\"red\",label=\"g\" ] ;\n";
      codageABdot(fichier,A->sag);} 
    if (A->sad != NULL) {
      fichier << (long)A << " -> " << (long)(A->sad) << " [color=\"blue\",label=\"d\" ] ;\n";
      codageABdot(fichier,A->sad);}
  }
  return;}
    

void dessinerAB(ArbreBin A, const char * nomFic, string titre){
  ofstream f(nomFic);
  if (!f.is_open()){
   cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
  }
  else {
    f<< "digraph G { label = \""<< titre << "\" \n";
    codageABdot(f,A);
    f << "\n }\n" ;
    f.close();}
  return;}


/* A COMPLETER */
int sommeNoeuds(ArbreBin A){
  /* renvoie la somme des etiquettes des noeuds de l arbre binaire A */
  /* A COMPLETER */
  int res=0;
  if(A != NULL){
    res += A -> info;
    res += sommeNoeuds(A->sag) + sommeNoeuds(A->sad);
      }
  return res;}

int profMinFeuille(ArbreBin A){
  /* renvoie la profondeur minimum des feuilles de l'arbre A ; A est non vide */
  assert(A!=NULL);
  /* A COMPLETER */
  int d=0,g=0,prof=0;
  if(A != NULL){
    if((A->sag != NULL)||(A->sad != NULL)){
      g = profMinFeuille(A->sag);
      d = profMinFeuille(A->sad);
      prof = 1 + min(g,d);
    }
  }
  return prof;}
    
ListeSC parcoursInfixe(ArbreBin A){
  /* renvoie la liste composee des etiquettes des noeuds de l'arbre A ordonnée
     selon l'ordre infixe */
  /* A COMPLETER */
  ListeSC L = NULL;

  if(A != NULL){
    if(A->sag == NULL){
      if(A->sad == NULL){
	//gauche et droit vide
	insererFinLSC(L,A->info);
      }else{
	//gauche vide
	insererFinLSC(L,A->info);
	L = concatLSC(L,parcoursInfixe(A->sad));
      }
    }else{
      if(A->sad == NULL){
	//droit vide
	L = concatLSC(L,parcoursInfixe(A->sag));
	insererFinLSC(L,A->info);
      }else{
	//rien vide
	L = concatLSC(L,parcoursInfixe(A->sag));
	insererFinLSC(L,A->info);
	L = concatLSC(L,parcoursInfixe(A->sad));
      }
    }
  }
  return L;}

void effeuiller(ArbreBin& A){
  /* modifie l'arbre A en supprimant ses feuilles */
  /* A COMPLETER */
  if (A != NULL){
    if((A->sag == NULL)&&(A->sad == NULL)){
      A = NULL;
      return;
    }
    effeuiller(A->sag);
    effeuiller(A->sad);
  }
  return;}

void tailler(ArbreBin& A, int p){
  /* modifie l'arbre A, en supprimant ses noeuds de profondeur au moins p ; p est un entier positif ou nul */
  /* A COMPLETER */
  if(A != NULL){
    if(p!=0){
      tailler(A->sag,p-1);
      tailler(A->sad,p-1);
    }
    else
      A = NULL;
  }
  return;}

ArbreBin genereAB(int n){
  /* A COMPLETER */
  ArbreBin A = creerArbreBin(n,NULL,NULL);
  if(n != 0){
    if(n > 1){
      A->sag = genereAB(n-(n/2));
      A->sad = genereAB(n/2);
    }
  }
  return A;}

void tronconner(ArbreBin& A){
  /* modifie l'arbre A, en supprimant les noeuds dont un seul sous-arbre est vide */
  /* A COMPLETER */
  
  return;}

bool estParfait(ArbreBin A){
  // Vérifie si A est un arbre binaire parfait
  return true;
}

/*****************************************************************************/
/*                                                                           */
/*                              main                                         */
/*                                                                           */
/*****************************************************************************/
int main(int argc, char *argv[]){
  int q,i;
  ArbreBin A,B,C;
  ostringstream stre;
  ListeSC L;
  string  chaine;
  A=creerArbreBin(8,
		  creerArbreBin(7,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,NULL,NULL)),
		  creerArbreBin(3,NULL,NULL));

  B=creerArbreBin(8,
		  creerArbreBin(2,
				creerArbreBin(4,NULL,NULL),
				creerArbreBin(9,
					      NULL,
					      creerArbreBin(1,
							    NULL,
							    creerArbreBin(7,
									  creerArbreBin(11,NULL,NULL),
									  creerArbreBin(5, 
											NULL,
											NULL))))),
		  creerArbreBin(3,
				creerArbreBin(12,
					      creerArbreBin(6,NULL,NULL),
					      NULL),
				creerArbreBin(9,NULL,NULL)));
  C=NULL;
  C= creerArbreBin(1,C,C);
  cout << "Numero de la question traitee (1/2/3/4/5/6/7) ? ";
  cin >> q;
  switch (q){
  case 1 :
    dessinerAB(A,"arbre.dot","Arbre Bin");
    cout << "Somme des noeuds de l'arbre :"<< sommeNoeuds(A) << endl;
    cout << "Profondeur minimum des feuilles de l'arbre : " << profMinFeuille(A) << endl;
    system("dotty arbre.dot");
    break;
  case 2 :
    dessinerAB(A,"arbre.dot","Arbre Bin");    
    L=parcoursInfixe(A);
    cout << "Liste des noeuds de l'arbre en ordre infixe : ";
    afficherLSC(L);
    system("dotty arbre.dot");
    break;
  case 3 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    effeuiller(B);
    dessinerAB(B,"arbre2.dot","Arbre Bin effeuille");
    system("dotty arbre2.dot");
    break;
  case 4 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    cout << " Donner une profondeur (entier positif) :";
    cin >> i;
    tailler(B,i);
    stre << i;
    chaine = stre.str();
    chaine = "Arbre Bin taille a la profondeur " + chaine;
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    break;
  case 5 :
    cout << " Donner un entier positif :";
    cin >> i;
    stre << i;
    chaine = "Arbre Bin  " + stre.str();
    dessinerAB(genereAB(i),"arbre.dot", "Arbre Bin  " + stre.str());
    system("dotty arbre.dot&");
    break;
  case 6 :
    dessinerAB(B,"arbre.dot","Arbre Bin");
    system("dotty arbre.dot&");
    tronconner(B);
    dessinerAB(B,"arbre2.dot","Arbre tronconne");
    system("dotty arbre2.dot&");
    break;
  case 7 :
    A=genereAB(7);
    chaine= estParfait(A) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(A,"arbre.dot",chaine);
    system("dotty arbre.dot");

    B=genereAB(8);
    chaine= estParfait(B) ? "Arbre parfait" : "Arbre non parfait";
    dessinerAB(B,"arbre2.dot",chaine);
    system("dotty arbre2.dot&");
    break;
  }
  return 0;
}
