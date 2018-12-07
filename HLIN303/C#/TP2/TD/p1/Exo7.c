#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[] ,char* env[]){

  float k=0.0;
  float z;
  for (int i=1;i<argc;i++){
    z=atoi(argv[i]);
    k+=z;
  }
  printf("Moyenne : %6.2f\n",k/(argc-1));
  
  return 0;
}
