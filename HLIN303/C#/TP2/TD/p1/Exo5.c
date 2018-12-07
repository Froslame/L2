#include <stdio.h>

int main(int argc, char* argv[], char *env[]){

  printf("Il y a %i paramètres passés à la ligne de commande.\n",argc-1);

for(int k=1;k<argc;k++){
  printf("Parametre %i : %s\n",k,argv[k]);
 }

 int j=0;
 while (env[j] != NULL){
   printf("Variable Environnement %i : %s\n",j,env[j]);
   j++;
 }
 
return 0;
}
