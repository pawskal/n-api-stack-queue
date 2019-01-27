#include <iostream>
#include "queue.h"

using namespace std;

// template <class T>
// Queue<T>::Queue(int size):Base(size);

template <class T>
void Queue<T>::enqueue(T obj) {
  cout<<this->size<<" old size"<<endl;
  this->resize(this->size + 1);
  this->array[this->size -1] = obj;
}

template <class T>
T Queue<T>::dequeue() {
  T obj = this->array[0];
  cout<<this->size<<" old size"<<endl;
  this->resize(this->size - 1);
  return obj;
}