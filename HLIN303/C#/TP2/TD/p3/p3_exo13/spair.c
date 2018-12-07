#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "impair.h"
#include "pair.h"

int main(int argc, char* argv[]){

  int x = atoi(argv[1]);
  
  if (pair(x)==1){
    printf("%i est pair !\n",x);
      }else{
    printf("%i est impair !\n",x);
  }
  
  return 0;
}
