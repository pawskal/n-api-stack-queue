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
  Queue<KeyValue>* objects = new Queue<KeyValue>();

  Sum *foo = new Sum(5, 5);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(foo);

  queue->print();

  Sum *bar = new Sum(3, 3);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(bar);
  queue->print();

  Sum *baz = new Sum(4, 4);
  cout<<"enqueueyng"<<endl;
  queue->enqueue(baz);
  queue->print();

  cout<<"dequeueyng"<<endl;

  Sum* first = queue->dequeue();
  cout<<"first"<<endl;
  first->display(true);

  cout<<queue->size<<endl;

  Sum* last = queue->dequeue();
  cout<<"last"<<endl;
  last->display(true);
  queue->print();

  Queue<int>* queueInt = new Queue<int>();
  int n = 34;
  int* val = &n;

  int k = 168;
  int* val2 = &k;
  queueInt->enqueue(val);
  queueInt->enqueue(val2);

  int* a = queueInt->dequeue();
  int* b = queueInt->dequeue();

  cout<<*a<<" a "<<*b<<" b "<<endl;

  Queue<std::string>* queueStr = new Queue<std::string>();
  std::string st1 = "test 1";
  std::string* st1ref = &st1;

  queueStr->enqueue(st1ref);
  // queueStr->enqueue((std::string)"test 2");

  std::string* aStr = queueStr->dequeue();
  // std::string* bStr = queueStr->dequeue();

  cout<<*aStr<<" a "<<endl;

  KeyValue* obj1 = new KeyValue("test1", "test2");
  KeyValue* obj2 = new KeyValue("test3", "test4");

  objects->enqueue(obj1);
  objects->enqueue(obj2);

  KeyValue* obj3 = objects->dequeue();
  KeyValue* obj4 = objects->dequeue();

  cout<<obj3->key<<" <- Key3 "<<obj3->value<<" <- Value3"<<endl;
  cout<<obj4->key<<" <- Key4 "<<obj4->value<<" <- Value4"<<endl;

  
  return 0;
}
