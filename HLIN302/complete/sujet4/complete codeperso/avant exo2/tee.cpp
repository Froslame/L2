#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ancienmain(int argc, char** argv){
  
  ofstream X;
  X.open(argv[1],ios::out|ios::app);
  string txt;
  while(txt!="END"){
    cin>>txt;
    //cout.write(X,txt);
    X<<txt<<'\n';
    cout<<txt<<endl;
  }
  X.close();
  
  return 0;
}

  //V2

int main(int argc, char** argv){
  
  ofstream X;
  string txt;
  while(txt!="END"){
    cin>>txt;
    cout<<txt<<endl;
    for(int i=1;i<argc;i++){
      X.open(argv[i],ios::out|ios::app);
      X<<txt<<'\n';
      X.close();
    }
  }
  
  return 0;
}
