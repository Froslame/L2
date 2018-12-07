#ifndef __LIVRE_H
#define __LIVRE_H

#include <string>

class Livre
{
public:
	enum Genre
	{
		ROMAN,
		FANTASY,
		SF,
		BD,
		AUTRE
	};
private:
	const std::string _titre;
	const std::string _auteur;
	const size_t _date;
	const Genre _genre;
	Livre& _adresse;
public:
	//Constructeurs
	Livre(std::string titre,std::string auteur,size_t date,Genre genre);//bas de pile
	//Accesseurs en lecture
	std::string getTitre()const;
	std::string getAuteur()const;
	size_t getDate()const;
	Genre getGenre()const;
	Livre& getAdresse()const;
	//Accesseurs en écriture
	void setAdresse(Livre& adresse);
	//Autre
	void affiche()const;
};

#endif