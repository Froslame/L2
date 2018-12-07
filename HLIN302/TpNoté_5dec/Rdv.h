#ifndef __RDV_H
#define __RDV_H

#include <string>

class Rdv
{
public:
	enum TYPE
	{
		CONTROLE,
		MALADIE,
		VACCIN,
		CERTIFICAT,
		AUTRE
	};
private:
	const std::string _nom;
	const TYPE _type;
	Rdv* _prochain;
public:
	//Constructeurs
	Rdv(std::string nom,TYPE type);
	//Accesseurs en Lecture
	std::string getNom()const;
	TYPE getType()const;
	Rdv* getSuivant()const;
	//Accesseurs en Ecriture
	void setSuivant(Rdv* suiv);
	//Autre
};

#endif