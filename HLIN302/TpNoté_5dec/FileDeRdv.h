#ifndef __FILERDV_H
#define __FILERDV_H

#include <string>

#include "Rdv.h"

class FileDeRdv
{
private:
	Rdv* _debut;
	Rdv* _fin;
public:
	//Constructeurs
	FileDeRdv();
	//Destructeurs
	~FileDeRdv();
	//Operateur
	FileDeRdv* operator=(const FileDeRdv*);
	//Accesseurs en lecture
	Rdv* getDeb()const;
	Rdv* getFin()const;
	//Acceseurs en Ecriture
	void ajoutFin(Rdv* fin);
	void retraitDeb(Rdv* deb);
};

void suppress(Rdv* X); //supprime X et ceux qui le suivent
Rdv* duplicate(const Rdv* X); //duplique X et ceux qui le suivent

#endif