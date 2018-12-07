#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pair.h"

int impair(unsigned int i){
  if(i==0){
    return 0;
  }
  else
    return pair(i-1);
}
