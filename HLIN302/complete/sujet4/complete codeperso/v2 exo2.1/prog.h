#ifndef PROG_H
#define PROG_H

#include <string>

using namespace std;

class option{
 public:
  enum Type{
    AUCUN,
    ENTIER,
    REEL,
    CHAINE
  };

 private:
  size_t id;
  string nom,raccourci,description;
  Type type;
  
 public:
  //Constructeur
  option();
  option(int id,string nom,string raccourci,string description,Type type);
  //Lecture
  int getId() const;
  string getNom() const;
  string getRaccourci() const;
  string getDescription() const;
  Type getType() const;
  //Ecriture
  void setId(int);
  void setNom(string);
  void setRaccourci(string);
  void setDescription(string);
  void setType(Type);
  //Autre
  void print() const;
};

string Type2String(option::Type t);

#endif
