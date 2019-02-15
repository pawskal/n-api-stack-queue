#include <iostream>
#include "queue.h"

using namespace std;

// template <class T>
// Queue<T>::Queue(int size):Base(size);

template <typename T>
void Queue<T>::enqueue(T* obj) {
  cout<<this->size<<" old size"<<endl;
  cout<<obj<<" ENQ REF"<<endl;
  this->resize(this->size + 1);
  this->array[this->size -1] = obj;
}

template <typename T>
T* Queue<T>::dequeue() {
  T* obj = *this->array;
  cout<<this->size<<" old size"<<endl;
  cout<<obj<<" DEQ REF"<<endl;
  this->resize(this->size - 1);
  return obj;
}