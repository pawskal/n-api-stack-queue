#include <iostream>
#include "./base/queue/queue.cpp"

using namespace std;

class Sum {
  public:
    int a, b, result;
    Sum(int a, int b) {
      this->a = a;
      this->b = b;
    };
    int calculate() {
      result = a + b;
      return result;
    };
    void display(bool print) {
      cout<< "a: "<<a<<"\t"<< "b: "<<b<<"\t"<<"result: "<<this->calculate()<<endl;
      cout<< "----------------------------"<<endl;
    };
};

int main() {
  Queue<Sum>* queue = new Queue<Sum>();

  Sum *foo = new Sum(5, 5);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(*foo);

  queue->print();

  Sum *bar = new Sum(3, 3);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(*bar);
  queue->print();

  Sum *baz = new Sum(4, 4);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(*baz);
  queue->print();

  cout<<"dequeueyng"<<endl;

  Sum first = queue->dequeue();
  cout<<"first"<<endl;
  first.display(true);

  cout<<queue->size<<endl;

  Sum last = queue->dequeue();
  cout<<"last"<<endl;
  last.display(true);
  queue->print();

  Queue<int>* queueInt = new Queue<int>();
  queueInt->enqueue(34);
  queueInt->enqueue(66);

  int a = queueInt->dequeue();
  int b = queueInt->dequeue();

  cout<<a<<" a "<<b<<" b "<<endl;
  
  return 0;
}
