#ifndef PROG_H
#define PROG_H

class TableauInt{
 private:
  int* Tab;
  size_t taille;
  size_t tailleMax;
 public:
  //Constructeur
  TableauInt(size_t taille);
  TableauInt(const TableauInt&);
  //Operateur
  TableauInt& operator=(const TableauInt&);
  //Destructeur
  ~TableauInt();
  //Lecture
  size_t getTaille()const;
  size_t getTailleMax()const;
  int& at(size_t);
  const int& at(size_t)const;
  //Ecriture
  void push_back(int);
  void extend();
  
};

void write(std::ostream&, const TableauInt&);

#endif
