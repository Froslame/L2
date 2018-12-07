//Constructeur ALT+X c++-mod

template<typename T>
MyVector<T>::MyVector():_data(new T[1]),_n(0),_alloc(1){}

template<typename T>
MyVector<T>::MyVector(size_t nmax):_data(new T[nmax]),_n(0),_alloc(nmax){}

template<typename T>
MyVector<T>::MyVector(const MyVector& V):_data(new T[V._n]),_n(V._n),_alloc(V._n){
  for(size_t i=0;i<V._n;i++){
    _data[i]=V._data[i];
  }
}

template<typename T>
void MyVector<T>::extend(){
  if (_n<_alloc) return;
  _alloc=2*_n;
  T* tmp=new T[_alloc];
  for(size_t i=0;i<_n;i++){ tmp[i]=_data[i]; }
  delete[] _data;
  _data=tmp;
}

//Destructeur

template<typename T>
MyVector<T>::~MyVector(){ delete[] _data; }

//Lecture

template<typename T>
T& MyVector<T>::at(size_t _n){ return _data[_n]; }

template<typename T>
const T& MyVector<T>::at(size_t)const{ return _data[_n]; }

template<typename T>
size_t MyVector<T>::size()const {return _n;}

//Ecriture

template<typename T>
void MyVector<T>::push_back(const T& C){
  extend();
  _data[_n]=C;
  _n++;
}

template<typename T>
void MyVector<T>::erase(size_t idx){
  if (idx>=0 && idx<(int)_n){
    for(size_t i=idx;i<_n-1;i++)
      _data[i]=_data[i+1];
    _n--;
  }  
}

template<typename T>
int MyVector<T>::find(const T& C) const{
  for (size_t i=0;i<_n;i++)    
    if (C==_data[i]) return i;		
  return -1;
} 

//FONCTION GENERIQUE HORS CLASSE

template<typename T>
void write(std::ostream& os,const MyVector<T> &X){
  os<<"affichage : ";
  for(size_t i=0;i<X.size();i++){
    os<<X.at(i)<<(i!=X.size()-1?",":"");
  }
  os<<std::endl;
}	     				     

template<>
void write<Cellule>(std::ostream& os, const MyVector<Cellule>& T){
  os<<"affichage cellule: ";
  for(size_t i=0;i<T.size();i++){
    write_cell(os,T.at(i));
    os<<(i!=T.size()-1?",":"");
  }
  os<<std::endl;
} 	
