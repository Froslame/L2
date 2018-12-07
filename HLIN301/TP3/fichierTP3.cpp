#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;



bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC triée, false sinon 

  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}

bool estListeIntervalle(ListeSC L){
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  // A COMPLETER _ completed
  ListeSC P=L;
  while(P->succ!=NULL){
    if((P->info)+1 != (P->succ->info))
      return false;
    P=P->succ;
  }

  return true;
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : ???  0(l^2)
  assert(l>0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0;i<l;i++)    
    insererFinLSC(L,p+i);
  return L;
}

ListeSC consListeIntervalle2(int l, int p){
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : ???  0(l)
  assert(l>0); 
  // A COMPLETER _ completed
  int i; ListeSC L;
  L=NULL;
  for(i=l-1;i>=0;i--){
    insererDebutLSC(L,i+p);
  }
  return L;
}

ListeSC consListeIntervalle3(int l, int p){
  //     Donnée : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier élément a pour valeur p 
  //     Complexité : ???  0(l)
  //     Version récursive
  // A COMPLETER _ completed
  ListeSC L=NULL;
  if(l>0){
    insererDebutLSC(L,p);
    l--;
    p++;
    ListeSC P=L;
    P->succ=consListeIntervalle3(l,p);
    return L;
  }
  return L;
}

// Temps de construction d'une liste intervalle de taille 50000 :
// avec consListeIntervalle1 : ??? 10.5509
// avec consListeIntervalle2 : ??? 0.002009
// avec consListeIntervalle3 : ??? 0.003471

void transfListeIntervalle(ListeSC L){
  //     Donnée : L est une liste triée non vide  
  //     Res : modifie L en y inserant des éléments de sorte qu'elle soit une Liste Intervalle
  //     Complexité : ???? 0(n)
  assert((L!=NULL));
  assert(estTrieeLSC(L));
  // A COMPLETER _ completed
  ListeSC P;
  P=L;
  while (P->succ != NULL){
    if((P->info)+1 != P->succ->info){
      insererApresLSC(L,P,(P->info)+1);
    }
    P=P->succ;
  }
  return;
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  //     Donnée : l1 et l2 2 listes intervalles
  //     Res : Renvoie l'intersection de l1 et l2; les éléments de la liste résultat sont recopiés
  //     Complexité : ???? 0(n)
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));
  // A COMPLETER _ completed
  ListeSC L,P,RES;
  L=l1;P=l2;
  while((L->succ != NULL)&&(P->succ != NULL)){
    if(L->info == P->info){
      insererFinLSC(RES,L->info);
      L=L->succ;
      P=P->succ;
    }
    if(L->info < P->info){
      L=L->succ;
    }
    if(L->info > P->info){
      P=P->succ;
    }
  }
  if(L->info == P->info){
      insererFinLSC(RES,L->info);
  }
  return RES;
}
  
void plusLgSsLiInterv(ListeSC &L){
  //     Donnée : L liste
  //     Res : L est modifiee, elle est la plus longue sous-liste intervalle de la liste en entrée
  //     Complexité : ???? 0(n)
  // A COMPLETER _ completed
  assert((L!=NULL));
  ListeSC P,T,K;
  P=L;T=L;
  int i,max=0;
  while(P->succ != NULL && P!=NULL){
    i=0;
    T=P;
    while( P!=NULL && P->succ!=NULL && ((P->info)+1 == (P->succ->info))){
      i++;
      P=P->succ;
    }
    K=P;
    if(P->succ != NULL)
      P=P->succ;
    if(i>max){
      max=i;
      L=T;
      K->succ=NULL;
    }
  }
  
}





