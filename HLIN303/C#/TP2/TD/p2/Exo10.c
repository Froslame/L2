#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int conv(char* dec){
  int z,i=0;
  char* res;
  while(dec[i]!='.'){
    i++;
  }
  res=malloc(i-1);
  //printf("%i \n",i);
  //printf("%i \n",j);
  strncpy(res,dec,i);
  //printf("%s \n",res);
  z=atoi(res);
  return z;
}

int conv(char *dec){
  int z=0,i=0;
  while(dec[i]!='\0'){
    i++;
  }
  int x=1;
  for(i;i!=0;i--){
    z+=dec[i-1]*x;
    x*=10;
  }
  return z;
}
*/

int conv(char *s){
  int cumul=0,i=0;
  while(s[i]>='0' && s[i]<='9'){
    cumul=cumul*10+s[i]-'0';
    i++;
  }
  return cumul;
}

int main(int argc, char* argv[], char* env[]){

  char* deci="4554";
  printf("%i \n",conv(deci));

  return 0;
}
 
