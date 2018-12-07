#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

class Options{
 private:
  int id;
  std::string nom,raccourci,description;
 public:
  //Constructeur
  Options();
  Options(int id, const std::string &nom, const std::string &raccourci, const std::string &description);
  //Lecture
  int getId()const;
  std::string getNom()const;
  std::string getRaccourci()const;
  std::string getDescription()const;
  //Ecriture
  void setId(int id);
  void setNom(const std::string &nom);
  void setRaccourci(const std::string &racc);
  void setDescription(const std::string &desc);
  //Affichage
  void print()const;
};

#endif
