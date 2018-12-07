#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "cellule.h"

template<typename T>
class MyVector{
 private:
  T* _data;
  size_t _n;
  size_t _alloc;

  void extend();
 public:
  //Constructeur
  MyVector();
  MyVector(size_t _nmax);
  MyVector(const MyVector&);
  //Destructeur
  ~MyVector();
  //Lecture
  T& at(size_t _n);
  const T& at(size_t)const;
  size_t size()const;
  //Ecriture
  void push_back(const T&);
  void erase(size_t _n);
  int find(const T&)const;
};

#include "MyVector.tcc"

#endif
