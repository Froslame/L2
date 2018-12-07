#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
char* concat(char* deb,char* fin){
  char* mot;
  int i=0,j=0;
  while(deb[i]!='\0'){
    i++;
  }
  while(deb[j]!='\0'){
    j++;
  }
  mot=malloc(i+j-2);
  for(int k=0;k<i;k++){
    mot[k]=deb[k];
  }
  int z=0;
  for(int k=i;k<j;k++){
    mot[k]=fin[z];
    z++;
  }
  return mot;
}

char* ctc(int k){
  char* txt=malloc(2);
  txt[0]=i+'0';
  txt[1]='\0';
  return txt;
}

char* conv(int i){
  if(i<10)
    return ctc('0'+i);
  else
    return concat(conv(i/10),ctc('0'+(i%10)));
}
*/
char* conv(int i,char *s){
  if(i<0)
    return NULL;
  if(i<10){
    s[0]=i+'0';
    s[1]='\0';
  }else{
    int l=strlen(conv((i/10),s));
    char unite=i%10 + '0';
    s[l]=unite;
    s[l+1]='\0';
  }
  return s;
}

int main(int argc, char* argv[], char* env[]){

  int deci=4894;
  char* s=malloc(50);
  printf("%s \n",conv(deci,s));

  return 0;
}
