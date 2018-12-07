#include <iostream>
#include <fstream>
#include <string>

#include "cellule.h"

using namespace std;

template <typename T>
const T &max3(const T &x,const T &y,const T &z){
  if(x>y && x>z) return x;
  if(y>x && y>z) return y;
  return z;
}

template <typename T1,typename T2,typename T3>
const T1 &max3(const T1 &x,const T2 &y,const T3 &z){
  cerr<<"Type différent !! | ";
  return x;
}

template<>
const Cellule &max3<Cellule>(const Cellule &X,const Cellule &Y,const Cellule &Z){
  if (X.estApres(Y) && X.estApres(Z)) return X;
  if (Y.estApres(X) && Y.estApres(Z)) return Y;
  return Z;
}

#define MAX3(x,y,z,type)						\
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl; \
  cout<<"{ "<<x<<" , "<<y<<" , "<<z<<" } : "<<max3<type>(x,y,z)<<endl
#define MAX3_(x,y,z)							\
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;	\
  cout<<"{ "<<x<<" , "<<y<<" , "<<z<<" } : "<<max3(x,y,z)<<endl
#define MAX3_CELLULE(x,y,z)						\
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl; \
  cout<<"{ "; x.print();						\
  cout<<" ,"; y.print();						\
  cout<<" ,"; z.print();						\
  cout<<"}:";							\
  max3(x,y,z).print();	

 
int main(int argc, char** argv){
  
  int a=3,b=2,c=0;
  float x=4.2,y=5.0,z=2.3;
  Cellule X(true,6,7),Y(true,7,8),Z(true,6,9);
  
  MAX3(a,b,c,int);
  MAX3(x,y,z,float);
  MAX3_(a,y,c);
  MAX3_CELLULE(X,Y,Z);
  
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  return 0;
}
