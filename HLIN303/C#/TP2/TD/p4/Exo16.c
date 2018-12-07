#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EDF -1

int nbocc[256], taille=0;

//return 0 si ok
int calcul_nbocc(char *monfic){
  FILE* f=fopen(monfic,"r");
  if (f==NULL){return 1;}
  int c;
  while(EDF!=(c=fgetc(f))){
    taille++;
    nbocc[c]++;
  }
  fclose(f);
  return 0;
}

int main(int argc, char* argv[]){

  if(argc<2){
    printf("SAISISSEZ UN FICHIER \n");
    exit(1);
  }
  
  int k = calcul_nbocc(argv[1]);
  if(k==1){
    printf("LECTURE IMPOSSIBLE \n");
    exit(2);
  }
  
  printf("taille -> %i \n",taille);

  char K='a';
  
  for (int i=0;i<26/*256*/;i++){
    printf("Il y a %i %c \n",nbocc[K],K);
    K++;
  }
  
  return 0;
}
