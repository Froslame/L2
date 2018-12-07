#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "impair.h"
#include "pair.h"

int impair(unsigned int i){
  if(i==0){
    return 0;
  }
  else
    return pair(i-1);
}

int pair(unsigned int i){
  if(i==0){
    return 1;
  }
  else
    return impair(i-1);
}

int main(int argc, char* argv[]){
  
  int x = atoi(argv[1]);
  
  if (pair(x)==1){
    printf("%i est pair !\n",x);
      }else{
    printf("%i est impair !\n",x);
  }
  
  return 0;
}
