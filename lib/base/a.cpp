#include <iostream>
#include <cstring>
#include "a.h"

using namespace std;

const int SIZE = 0;

template <class T>
Base<T>::Base(int size) {
  this->size = SIZE;
  this->array = new T*[SIZE];
}

template <class T>
void Base<T>::print() {
  string str = this->size == 0 ? "empty" : "not emply";
  cout<<str<<endl;
  for(int i = 0; i<this->size; i++) {
    // cout << this->array[i] <<endl;
    this->array[i]->display(true);
  }
}

template <class T>
void Base<T>::fill() {
  for(int i = 0; i<this->size; i++) {
    this->array[i] = i;
  }
}

template <class T>
void Base<T>::resize(int newSize) {
  int offset = newSize - this->size;
  cout<<newSize<<" newSize "<<newSize*sizeof(T*)<<endl;
  cout<<offset<<" offset"<<endl;
  if (offset > 0) {
    memcpy(this->array, this->array, newSize*sizeof(T*)); 
  } else {
    memcpy(this->array, this->array + 1, newSize*sizeof(T*)); 
  }
  this->size = this->size + offset;
}
