#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

/*###############################################
# AFFICHE TABLEAU CODE BINAIRE APRES EXTRACTION #
###############################################*/
void affiche_code_ext(char* new_code[][2],int taille_arbre){
  printf("---CODE-BINAIRE-EXTRACT-\n");
  int i=0;
  while(new_code[i][0]!=NULL){
    printf("%s : %s \n",new_code[i][0],new_code[i][1]); /////////////////////////////////
    i++;
  }
}

/*#############################################
# ECRITURE FICHIER TXT POUR LIRE CODE BINAIRE #
#############################################*/
void write_code(char* code_bin[][2]){
  FILE* f=fopen("./Compiler/CODE_ARBRE.txt","w+");
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
  char* new_code[taille_arbre-1][2];
  FILE* f=fopen(fichier,"r");
  if(f != NULL){
    char* c=malloc(40);
    int x_tmp = 0;
    while(fgets(c,40,f)){
      char** tmp=malloc(40);
      char** ttmp=malloc(40);
      tmp=strsplit(c,':');
      ttmp=strsplit(tmp[1],'\n');
      new_code[x_tmp][0]=tmp[0];
      new_code[x_tmp][1]=ttmp[0];
      x_tmp++;
    }
    fclose(f);
  }
  else{
    printf("LECTURE IMPOSSIBLE \n");
    exit(4);
    }
  affiche_code_ext(new_code,taille_arbre);
}

/*#############
# COMPILATION #
#############*/

void compression(char* code_bin[][2],char* fichier){
  printf("----COMPILATION---- \n");
  int check = 1;
  FILE* brut=fopen(fichier,"r");
  FILE* code=fopen("./Compiler/CODE.txt","w+");
  char* code_brut=malloc(taille*8);
  for(int i=0;i<taille*8;i++){
    code_brut[i]='\0';
  }
  if (brut != NULL && code != NULL){
    int tmp_lettre;
    while(EDF != (tmp_lettre = fgetc(brut))){
      char lettre=tmp_lettre;
      if(lettre != '\n')
	//printf("%c : ",lettre);
      check=0;
      for(int i=0;i<calcul_nbdiff();i++){
	if(code_bin[i][0][0] == lettre){
	  code_brut=strcat(code_brut,code_bin[i][1]);
	  check=1;
	  //printf("%s \n",code_brut);
	}
      }
      if(check == 0){
	if(lettre = '\n'){
	  //printf("RETURN \n"); //a modifier si l'on veut prendre en compte les return
	}
	else{
	  //printf("CODE CARACTERE INCONNU \n");
	  exit(6);
	}
      }
    }
  }
  else{
    printf("COMPILATION IMPOSSIBLE, PROBLEME D'ACCES \n");
    exit(5);
  }
  printf("Suite a écrire : %s \n",code_brut);
  //CREATION DES OCTETS
  printf("--OCTERISATION--- \n");
  int i=0;int k=0;
  char* verif=malloc(8);
  for (int j=0;j<8;j++){
    verif[j]='\0';
  }
  char* tmp_verif=malloc(15);
  for (int j=0;j<15;j++){
    tmp_verif[j]='\0';
  }
  int b=0;
  while((code_brut[k] != '\0') && (k<taille*8)){
    check = 0;
    int tmp_i = 0;
    while((check == 0) && (i!=8) && (k<taille*8) && (code_brut[k] != '\0')){
      for(int j=0;j<calcul_nbdiff();j++){
	verif[tmp_i] = code_brut[k];
	int check_bis=0;
	for(int a=0;a<8;a++){
	  if(verif[a] != code_bin[j][1][a])
	    check_bis = 1;
	}
	if(check_bis==0){
	  check = 1;
	}
      }
      k++;
      i++;
      tmp_i++;
    }
    int m=0;
    if(verif[m]!='\0'){
      for (int j=b;j<8;j++){
	tmp_verif[j]=verif[m];
	m++;
      }
    }
    b=i;
    for (int j=0;j<8;j++){
      verif[j]='\0';
    }
    if((i == 8) || (code_brut[k] == '\0')){
      printf("%s ENVOYER",tmp_verif);

      int w=7;
      int manquant=0;
      if(tmp_verif[w]=='\0'){
	while(tmp_verif[w]=='\0'){
	  w--;
	  manquant++;
	}
      }
      if(manquant != 0){
	for(int j=7;j>=manquant;j--){
	  tmp_verif[j]=tmp_verif[j-manquant];
	}
	for(int j=0;j<manquant;j++){
	  tmp_verif[j]='0';
	}
      }
      
      int calc=0;
      int puiss=7;
      for(int j=0;j<8;j++){
	if(tmp_verif[j]=='1'){
	  calc += pow(2,puiss);
	}
	puiss--;
      }
      printf(" %i",calc);
      fputc(calc,code);//xxd -b Compiler/CODE.txt
      if(i!=8)
	fputc(manquant,code);//met en dernier caractere la taille du dernier
      
      for (int j=0;j<15;j++){
	tmp_verif[j]='\0';
      }
      b=0;
      i=0;
      printf("\n");
    }
  }
  fclose(code);
  fclose(brut);
}

/*###############
# DECOMPILATION #
###############*/

//Extraire toute la chaine de caractere du fichier
//transfomer la chaine grace a la table du code en liste binaire
//lire la liste binaire au fur et a mesure
//stocker dans un fichier petit par petit
void decompression(char* fichier){
  printf("----DECOMPRESSION--- \n");
  FILE* code=fopen(fichier,"r");
  int tab[200];//taille max du fichier a decompresser
  for(int i=0;i<200;i++)
    tab[i]=-1;
  int c;
  int indice=0;
  if(code != NULL){
    while(EDF != (c=fgetc(code))){
      tab[indice]=c;
      indice++;
    }
  }else{
    printf("LECTURE IMPOSSIBLE \n");
    exit(7);
  }
  char* tab_oct[indice];
  char* octet=malloc(9);
  for(int i=0;i<9;i++)
    octet[i]='\0';
  for(int i=0;i<indice-2;i++){
    int tmp = tab[i];
    while(tmp != 0){
      printf("%i \n",tmp);
      for(int j=7;j>=0;j--){
	if(tmp%2 == 0)
	  octet[j]='0';
	else
	  octet[j]='1';
	tmp = tmp/2;
      }
    }
    tab_oct[i]=octet;
  }
  fclose(code);

  read_arbre("./Compiler/CODE_ARBRE.txt");
}

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

  for(int i=0;i<taille;i++)
    for(int j=0;j<2;j++)
      code_bin[i][j]="\0";

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

  //lecture txt code arbre && affiche code extrait
  read_arbre("./Compiler/CODE_ARBRE.txt");
  
  //transformer fichier en suite binaire
  compression(code_bin,argv[1]);
  //lire la suite binaire grace au code arbre 
  decompression("./Compiler/CODE.txt");

  return 0;
}
