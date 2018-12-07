#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[],char* env[]){
  
  float k=0.0,z;
  for(int i=0;i<5;i++){
    printf("Saisissez un flottant : \n");
    if(scanf("%f",&z)<1){
      printf("ERREUR SAISIE \n");
      exit(1);
    }
       k+=z;
  }
  printf("Moyenne : %5.2f\n",k/5);
  
  return 0;
}
