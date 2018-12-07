#ifndef cell_H
#define cell_H

class cell{
 private:
  unsigned int x,y;
  bool vivante;
  

 public:
  cell();
  cell(unsigned int,unsigned int,bool);

  bool estVoisin(const cell&)const;

  unsigned int getX()const;
  unsigned int getY()const;
  bool estVivante()const;

  void setVivante(bool);
  void setX(unsigned int);
  void setY(unsigned int);
};

#endif
