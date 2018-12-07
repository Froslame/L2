#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "prog.h"

using namespace std;

int main(int argc, char** argv){
  if(argc !=2){
    cerr<<"Usage: "<<argv[0]<<" [tab dim]"<<endl;
    return 1;
  }

  size_t n = atoi(argv[1]);
  TableauInt T(n);
  for(size_t i=0;i<n;i++){
    T.at(i)=i+1;
  }
  TableauInt T2(n);
  for(size_t i=0;i<n;i++){
    T2.push_back(i+1);
  }
  
  T.push_back(12);
  write(cout,T);
  write(cout,T2);
  
  return 0;
}
