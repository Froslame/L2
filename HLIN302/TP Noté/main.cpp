#include <iostream>

#include "PileDeLivres.h"

using namespace std;

void empilementMagique(Livre* Tab,const size_t taille){
	size_t min=-1,tmp=2500;
	Livre& adr=NULL;
	for(size_t k=0;k<taille;k++){
		for(size_t i=0;i<taille;i++){
			if(Tab[i].getAdresse()==NULL){
				if(Tab[i].getDate()<tmp){	
					min=i;
					tmp=Tab[i].getDate();
					adr=Tab[i];
				}
			}
		}
		Tab[min].setAdresse(adr);
		tmp=2500;
	}
}
void affichageMagique(const Livre* Tab,const size_t taille){
	int ind=taille;
	while(ind>=0){
		for(size_t i=0;i<taille;i++){
			if(Tab[i].getAdresse()==ind)
				Tab[i].affiche();
		}
		ind--;
	}
}

int main(int argc, char const *argv[])
{
	int x;
	cout<<"Lancement : (1)Exo1, (2)Exo2 : ";
	cin>>x;
	switch(x){
		case 1 : 
		{
			Livre a("Tolkien","The fellowship of the ring",1954,Livre::FANTASY);
			Livre b("Tolkien","The two towers",1954,Livre::FANTASY);
			Livre c("Tolkien","The return of the king",1955,Livre::FANTASY);
			Livre d("Goscini","Astérix en Corse",1973,Livre::BD);
			Livre e("Goscini","Astérix aux jeux olympiques",1968,Livre::BD);
			Livre f("Goscini","Le combat des chefs",1966,Livre::BD);
			size_t taille=6;
			Livre Tab[6]={a,b,c,d,e,f};
			empilementMagique(Tab,taille);
			affichageMagique(Tab,taille);
			break;
		}
		default :
		{
			cout<<"Aucun mode de lancement valide sélectionner ! "<<endl;
		}
	}

	return 0;
}