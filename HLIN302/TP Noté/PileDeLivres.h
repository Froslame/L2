#ifndef __PILESDELIVRE_H
#define __PILESDELIVRE_H

#include <string>
#include "Livre.h"

class PileDeLivres
{
private:
	Livre& _sommetPile;
public:
	//Constructeurs
	PileDeLivres();
	PileDeLivres(Livre& oeuvre);
	PileDeLivres(const PileDeLivres& Pile);
	//Destructeur
	~PileDeLivres();
	//Operateur
	PileDeLivres& operator =(const PileDeLivres&);
	//Accesseurs en lecture
	Livre& at(size_t indice);
	const Livre& at(size_t indice)const;

	size_t size()const;
	//Accesseurs en écriture
	void add(Livre oeuvre); //ajout un livre en sommet de Pile
	void delete(); //enleve sommet de Pile
	//Autre

};

void suppress(Livre* oeuvre); //suprime le livre ainsi que tout les livres en dessous
Livre* duplicate(Livre* oeuvre); //copie le livre ainsi que tout les livres en dessous

#endif