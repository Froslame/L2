#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EDF -1

int nbocc[256], taille=0;


/*############
# CONVERSION #
############*/
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

/*#####################
# LECTURE FICHIER TXT #
#####################*/
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

/*#########################
# CALCUL NOMBRE OCCURENCE #
#########################*/
void calcul_nbocc(){
  printf("---------TAILLE-------- \n");
  printf("taille -> %i \n",taille);
  printf("----NBR-OCCURENCES----- \n");

  char K='a';
  
  for (int i=0;i<26/*256*/;i++){
    printf("Il y a %i %c \n",nbocc[K],K);
    K++;
  }
}

/*####################################
# CALCUL NOMBRE CARACTERE DIFFERENTS #
####################################*/
int calcul_nbdiff(){
  char K='a';
  int k=0;
  for(int i=0;i<26/*256*/;i++){
    if(nbocc[K]!=0) k++;
    K++;
  }
  return k;
}

/*######################################################################
# CREATION ET INITIALISATION DES FEUILLES // INITIALISATION DE L'ARBRE #
######################################################################*/
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


/*########################
# REMPLISSAGE DE L'ARBRE #
########################*/
void comp_feuille(int new_nbocc[][5],int new_taille){
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
    new_nbocc[k][4]=new_nbocc[A][4]+new_nbocc[B][4];

    a=taille;b=a;
    k++;     
  }
}


/*#################
# AFFICHE L'ARBRE #
#################*/
void affiche(int new_nbocc[][5],int new_taille){
  printf("---------ARBRE--------- \n");
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


/*#################################
# INITIALISE TABLEAU CODE BINAIRE #
#################################*/
void init_binaire(char* code_bin[][2],int new_nbocc[][5]){
  for(int i=0;i<calcul_nbdiff();i++){
    char* txt=malloc(2);
    txt[0]=new_nbocc[i][3];
    txt[1]='\0';
    code_bin[i][0]=txt;
    code_bin[i][1]=malloc(50);
  }
}

/*###############################
# COMPLETE TABLEAU CODE BINAIRE #
###############################*/
void binaire(int new_nbocc[][5],int new_taille,char* code_bin[][2]){
  int k;
  int fg;
  int i0,tmp;
  int taille_tmp;
  for(int i=0;i<calcul_nbdiff();i++){
    i0=i;
    k=new_nbocc[i][2];
    while(k!=-2){
      tmp=k;
      fg=new_nbocc[k][0];
      k=new_nbocc[k][2];
      taille_tmp=strlen(code_bin[i][1]);
      for(int j=taille_tmp;j>=0;j--){
	code_bin[i][1][j+1]=code_bin[i][1][j];
      }
      if(fg==i0){
	code_bin[i][1][0]='0';
      }
      else{
	code_bin[i][1][0]='1';
      }
      i0=tmp;
    }
  }
}


/*##############################
# AFFICHE TABLEAU CODE BINAIRE #
##############################*/
void affiche_code(char* code_bin[][2]){
  printf("----CODE-BINAIRE------- \n");
  for(int i=0;i<calcul_nbdiff();i++){
    printf("%i : %s -> %s \n",i,code_bin[i][0],code_bin[i][1]);
  }
}

/*#############################################
# ECRITURE FICHIER TXT POUR LIRE CODE BINAIRE #
#############################################*/
void write_code(char* code_bin[][2]){
  FILE* f=fopen("CODE_ARBRE.txt","w+");
  char* txt;
  if (f != NULL){
    for(int i=0;i<calcul_nbdiff();i++){
      txt=strcat(code_bin[i][0],":");
      txt=strcat(txt,code_bin[i][1]);
      fputs(txt,f);
      fputs("\n",f);
    }
    fclose(f);
  }
  else{
    printf("ECRITURE IMPOSSIBLE \n");
    exit(3);
  }
}

/*#################################
# TAILLE ARBRE VIA LE FICHIER TXT #
#################################*/
int read_taille(char* fichier){
  FILE* f=fopen(fichier,"r");
  char taille[256];
  int taille_tmp=0, taille_def=0;
  if(f != NULL){
    int c;
    while(EDF != (c=fgetc(f))){
      taille_tmp++;
      taille[c]++;
    }
  }
  char K='a';
  for(int i=0;i<taille_tmp;i++){
    if(nbocc[K]!=0) taille_def++;
    K++;
  }
  return taille_def;
}

/*#####################################
# EXTRACTION ARBRE VIA LE FICHIER TXT #
#####################################*/
void read_arbre(char* fichier){
  int taille_arbre=read_taille(fichier);
  char* new_code[taille_arbre-1][1];
  FILE* f=fopen(fichier,"r");
  char** tmp[1]=malloc(40);
  if(f != NULL){
    char* c=malloc(40);
    while(fgets(c,40,f)){
      tmp=strsplit(c,":");
      new_code[tmp[0]][tmp[1]];
    }
    fclose(f);
  }
  else{
    printf("LECTURE IMPOSSIBLE \n");
    exit(4);
  }
}

/*#############
# COMPILATION #
#############*/


/*###############
# DECOMPILATION #
###############*/


/*######
# MAIN #
######*/
int main(int argc, char* argv[]){
  //vérification parametre
  if(argc<2){
    printf("SAISISSEZ UN FICHIER \n");
    exit(1);
  }
  int k = verif(argv[1]);
  if(k==1){
    printf("LECTURE IMPOSSIBLE \n");
    exit(2);
  }

  //allocation mémoire pour l'arbre et son codage
  calcul_nbocc();
  int new_taille = calcul_nbdiff()*2 - 1;
  int new_nbocc[new_taille][5];
  char* code_bin[taille][2];

  //initialise l'arbre
  tab_feuille(new_nbocc,new_taille);
  affiche(new_nbocc,new_taille);

  //complete l'arbre
  comp_feuille(new_nbocc,new_taille);
  affiche(new_nbocc,new_taille);

  //creer code binaire des caracteres
  init_binaire(code_bin,new_nbocc);
  binaire(new_nbocc,new_taille,code_bin);
  affiche_code(code_bin);
  
  //creer txt code arbre
  write_code(code_bin);

  //lecture txt code arbre
  read_arbre("CODE_ARBRE.txt");
  //affiche_code_txt(new_code);
  
  //transformer fichier en suite binaire
  //lire la suite binaire grace au code arbre 
  
  return 0;
}
