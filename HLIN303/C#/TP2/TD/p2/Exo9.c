#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** strsplit(char* txt,char sep){
  int i=0;int l; int n=0;
  int NbSep=0;
  while(txt[i]!='\0'){
    if(txt[i]==sep)NbSep++;
    i++;
  }
  char** res=malloc(NbSep+2);
  int APRES_SEP;
  i=0;
  do{
    l=0;
    while(txt[i]!='\0'&&txt[i]!=sep){
      l++;i++;
    }
    res[n]=malloc(l+1);
    strncpy(res[n],txt+i-l,l);
    res[n][l]='\0';
    n++;
    APRES_SEP=0;
    if(txt[i]==sep){
      APRES_SEP=1;
      i++;
    }
  }while(txt[i]!='\0');
  if(APRES_SEP==1){
    res[n]=malloc(1);
    res[n][0]='\0';
    n++;
  }
  res[n]=NULL;
  return res;
}

int main(int argc, char* argv[], char* env[]){
  char** Tab=strsplit("/bin:/usr/bin:/usr/local/bin",':');
  int i=0;int j=0;
  		       
  while(Tab[i]!=NULL){
    printf("%i --> %s \n",i,Tab[i]);
    i++;
  }
  printf("%i %s \n",i,Tab[i]);
  
  return 0;
}
