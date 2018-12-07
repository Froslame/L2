#ifndef TD2_H
#define TD2_H

class Itv{
 private:
  float a,b;

 public:
  Itv(float,float);
  Itv();
  
  //Lecture
  float getSup()const;
  float getInf()const;

  void affiche()const;
  void longueur()const;

  bool appart(float)const;

  //Ecriture
  void setSup(float);
  void setInf(float);
}

#endif
