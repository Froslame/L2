#include "prog.h"
#include "prog1.h"

#include <unistd.h> //usleep

int main(int argc, char** argv){
  int x=0;
  Population JDV;
  JDV.init(560); 
  JDV.print();
  do{
    JDV=JDV.next();
    JDV.print();
    //for(int k=0;k!=159999999;k++);*
    usleep(50000);
  }while(x==0);
  return 0;
}
