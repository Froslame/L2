/**************************** fichierTP5.h **************************************/
/*         Implantation du type Liste d'entiers  Simplement Chainée          */

#ifndef FICHIERTP5_H
#define FICHIERTP5_H
/* #include <iostream> */
/* #include <sstream> */
/* #include <fstream> */
#include <string>
/* #include <stdlib.h>  */
using namespace std;

typedef struct noeud {
  bool info;
  struct noeud *sag;
  struct noeud *sad;} NoeudSC;
typedef NoeudSC *Dico;

Dico creerDico(bool b, Dico G, Dico D);
// Renvoie une Dico dont la racine vaut b, le sag G et le sad D     

void dessinerAB(Dico A, const char * nomFic, string titre);
// Affiche le dictionnaire A sous forme d'arbre


int nbMots(Dico A);
// renvoie le nombre de mots du dictionnaire A

int lgMin(Dico A);
// A un un arbre dictionnaire contenant au moins un mot
// renvoie la longueur du plus petit mot du dictionnaire A

bool appMot(Dico D, ListeSC L);
// teste si le mot L appartient au dictionnaire D

void ajouterMot(Dico &A,ListeSC L);
// ajoute le mot L au dictionnaire A

void supprimerMot(Dico &A,ListeSC L);
// supprime le mot L du dictionnaire A

bool contientPrefixe(Dico A);
// Renvoie true si le dictionnaire contient au moins un mot et l'un de ses préfixes, renvoie false sinon

ListeSC motMin(Dico A);
  // A un Dictionnaire non vide
  // Renvoie le plus petit mot du dictionnaire dans l'ordre lexicographique (du dictionnaire)

void  nettoyer(Dico &D);
  // supprime les noeuds inutiles de l'arbre

void ajouter0Fin(Dico &D);
  // ajoute la lettre 0 à la fin de chaque mot du dictionnaire D
  // A MODIFIER

#endif /*FICHIERTP5_H */
