#include "../base.h"

class KeyValue
{
private:
  /* data */
public:
  KeyValue(std::string, std::string);
  ~KeyValue();
  std::string key;
  std::string value;
};

KeyValue::KeyValue(std::string key, std::string value)
{
  this->key = key;
  this->value = value;
}

KeyValue::~KeyValue()
{
}


template <typename T>
class Queue : public Base<T> {
  public:
    Queue():Base<T>(0){};
    void enqueue(T*);
    T* dequeue();
};
