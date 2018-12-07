#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "FileDeRdv.h"
using namespace std;

#define N 100

int main(int argc, char const *argv[])
{
	int x;
	cout<<"Lancement : (1)Exo1, (2)Exo2 : ";
	cin>>x;
	switch(x){
		case 1 : 
		{
			cout<<"Exercice 1 :"<<endl;
			int T[6];
			srand(time(NULL));
			for(int i=0;i<6;i++){
				bool check = true;
				int X=(1 + rand() % N);
				for(int j=0;j<6;j++){
					if(T[j]==X)
						check = false;
				}
				if(check){
					T[i]=X;
				}else{
					i--;
				}
			}

			Rdv A("Patient_<T[0]>",Rdv::AUTRE);
			Rdv B("Patient_<T[1]>",Rdv::AUTRE);
			Rdv C("Patient_<T[2]>",Rdv::AUTRE);
			Rdv D("Patient_<T[3]>",Rdv::AUTRE);
			Rdv E("Patient_<T[4]>",Rdv::AUTRE);
			Rdv F("Patient_<T[5]>",Rdv::AUTRE);

			A.setSuivant(&B);
			B.setSuivant(&C);
			C.setSuivant(&D);
			D.setSuivant(&E);
			E.setSuivant(&F);

			break;
		}
		case 2 : 
		{
			cout<<"Exercice 2 :"<<endl;

			break;
		}
		default :
		{
			cout<<"Aucun mode de lancement valide sélectionner ! "<<endl;
		}
	}

	return 0;
}