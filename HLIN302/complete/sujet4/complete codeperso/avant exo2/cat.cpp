#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){

  
  ifstream X;
  string l;
  cout<<"Début Prog"<<endl;
  if(argc==1){
    cout<<"Saisissez un fichier"<<endl;
    return 1;
  }
  for(int i=1; i<argc ; i++){
    cout<<"Fichier : "<<i<<endl<<endl;
    X.open(argv[i],ios::in);
    while(!X.eof()){
      getline(X,l,'\n');
      cout<<l<<endl;
    }
    X.close();
  }
  
  return 0;
}
