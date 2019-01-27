#include "../base.h"

template <class T>
class Queue : public Base<T> {
  public:
    Queue():Base<T>(0){};
    void enqueue(T);
    T dequeue();
};
