#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EDF -1

int nbocc[256], taille=0;

char* itoa(int i,char *s){
  if(i<0)
    return NULL;
  if(i<10){
    s[0]=i+'0';
    s[1]='\0';
  }else{
    int l=strlen(itoa((i/10),s));
    char unite=i%10 + '0';
    s[l]=unite;
    s[l+1]='\0';
  }
  return s;
}

//return 0 si lecture du fichier possible
int verif(char *monfic){
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

//calcule le nombre d'occurence de chaque caractere
void calcul_nbocc(){
  printf("taille -> %i \n",taille);

  char K='a';
  
  for (int i=0;i<26/*256*/;i++){
    printf("Il y a %i %c \n",nbocc[K],K);
    K++;
  }
}

//renvoie le nombre de caractère différents
int calcul_nbdiff(){
  char K='a';
  int k=0;
  for(int i=0;i<26/*256*/;i++){
    if(nbocc[K]!=0) k++;
    K++;
  }
  return k;
}

//Creation Tableau Feuilles
void tab_feuille(int new_nbocc[][5],int new_taille){
  char K='a';
  int j=0;
  for(int i=0;i<26;i++){
    if(nbocc[K]!=0){
      //-2 si non défini de maniere definitive
      //-1 si non défini pour l'instant
      new_nbocc[j][0]=-2;      //fils gauche
      new_nbocc[j][1]=-2;      //fils droit
      new_nbocc[j][2]=-1;      //père
      new_nbocc[j][3]=K;       //nom
      new_nbocc[j][4]=nbocc[K];//nombre occ
      j++;
    }
    K++;
  }
  //Initialisation par défault
  while(j!=new_taille){
    new_nbocc[j][0]=-1;
    new_nbocc[j][1]=-1;
    new_nbocc[j][2]=-1;
    new_nbocc[j][3]=-1;
    new_nbocc[j][4]=-1;
    j++;
  }
  new_nbocc[j-1][2]=-2;
}

//Complete Tableau Feuilles
void comp_feuille(int new_nbocc[][5],int new_taille){
  //char* lettre=malloc(50);
  int a = taille, b=a;
  int A,B;
  int k = (new_taille + 1)/2;
  while (new_nbocc[new_taille-1][4]==-1){
    for(int i=0;i<new_taille;i++){
      if(new_nbocc[i][2]==-1 && new_nbocc[i][3]!=-1
	 && (new_nbocc[i][4]<=a || new_nbocc[i][4]<=b)){
	if(b<a){
	  a = new_nbocc[i][4];
	  A=i;
	}
	else{
	  b =  new_nbocc[i][4];
	  B=i;
	}
      }
    }
    new_nbocc[k][0]=A;
    new_nbocc[k][1]=B;
    new_nbocc[A][2]=k;
    new_nbocc[B][2]=k;
    new_nbocc[k][3]=new_nbocc[A][3]+new_nbocc[B][3];
    //conv(concat(conv(new_nbocc[A][3],lettre),conv(new_nbocc[B][3],lettre)),lettre);
    new_nbocc[k][4]=new_nbocc[A][4]+new_nbocc[B][4];
    //new_nbocc[A][4]=-1;
    //new_nbocc[B][4]=-1;

    a=taille;b=a;
    k++;     
  }
}

//Affiche Tableau Feuille
void affiche(int new_nbocc[][5],int new_taille){
  printf("----------------------- \n");
  printf("    FG        FD      PERE      NOM      OCC\n");
  for(int i=0;i<new_taille;i++){
    printf("%i : ",i);
    for(int j=0;j<3;j++){
      printf("%i        ",new_nbocc[i][j]);
    }
    printf("%c        ",new_nbocc[i][3]);
    //printf("%i        ",new_nbocc[i][3]);
    printf("%i        ",new_nbocc[i][4]);
    printf("\n");
  }
}

//Initialisation Code Binaire
void init_binaire(char* code_bin[][2],int new_nbocc[][5]){
  char* s=malloc(50);
  for(int i=0;i<calcul_nbdiff();i++){
    s=itoa(new_nbocc[i][3],s);
    code_bin[i][0]=s;
    code_bin[i][1]=malloc(50);
    //printf("%c \n",code_bin[i][0]);
  }
}

//Code Binaire Caractere
void binaire(int new_nbocc[][5],int new_taille,char* code_bin[][2],char* code){
  int k;
  char* s=malloc(50);
  for(int i=0;i<calcul_nbdiff();i++){
    k=new_nbocc[i][2];
    while(k!=-2){
      k=new_nbocc[k][2];
      if(new_nbocc[k][0]==i){
	code_bin[i][1]=strcat(code_bin[i][1],"0");
      }
      else{
	code_bin[i][1]=strcat(code_bin[i][1],"1");
      }
    }
    printf("%s \n",code_bin[i][1]);
  }
}

int main(int argc, char* argv[]){
  if(argc<2){
    printf("SAISISSEZ UN FICHIER \n");
    exit(1);
  }
  int k = verif(argv[1]);
  if(k==1){
    printf("LECTURE IMPOSSIBLE \n");
    exit(2);
  }
  
  calcul_nbocc();
  int new_taille = calcul_nbdiff()*2 - 1;
  int new_nbocc[new_taille][5];
  char* code_bin[taille][2];
  
  tab_feuille(new_nbocc,new_taille);
  affiche(new_nbocc,new_taille);
  
  comp_feuille(new_nbocc,new_taille);
  affiche(new_nbocc,new_taille);

  //creer code bit des caracteres
  init_binaire(code_bin,new_nbocc);
  binaire(new_nbocc,new_taille,code_bin,"");
  
  
  //creer stockage code arbre
  //transformer fichier en suite binaire
  //fonction lecture de code arbre
  //lire la suite binaire grace au code arbre 
  
  return 0;
}


/* Correction 

   int *rconv = malloc ((2*nbcar-1)*size_of(int));
   int *fg = malloc ((2*nbcar-1)*size_of(int));
   int *fd = malloc ((2*nbcar-1)*size_of(int));
   int *pere = malloc ((2*nbcar-1)*size_of(int));
   int *occ = malloc ((2*nbcar-1)*size_of(int));
---
   int j=0;
   for(int i=0;i<256;i++){
    if(nbocc[i]>0){
    conv[i]=j;
    rconv[j]=i;
    fg[j]=fd[j]=pere[j]=-1;
    occ[j]=nbocc[i]
    j++
    }
   }
---
   for(int nn=bar;nn<2*nbocc-1;nn++){
   int min1=taille,min2=taille;
    for(int i =0;i<nn;i++){
     if(occ[i]<min1)&&pere i == -1
      imin2=min1;min2=min1;
      imin1=i;min1=occ[i];
     else
      if(occ[i]<min2)&& pere i == -1
       imin2=i;min2=occ[i];
     }
   }
*/
/*Correction suite
  parcours(2*nbcar -2,"")
  void parcours(int n, char* code){
   if (fg[n]==-1){
    printf %c:%s,rconv[n],code
   }
   else{
    char *s=malloc(strlen(code)+2);
    strcpy(s,code);
    strcat(s,"0");
    parcours(fg[n],s);
    srtcat(strcpy(s,code),"1");
    parcours(fd[n],s);
   } 
   free(s);
  }
*/
