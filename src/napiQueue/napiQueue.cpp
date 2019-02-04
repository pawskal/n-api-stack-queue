#include "napiQueue.h"

// #include <napi.h>
// #include "queue.cpp"

Napi::FunctionReference NapiQueue::constructor;

Napi::Object NapiQueue::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function function = DefineClass(env, "NapiQueue", {
    InstanceMethod("dequeue", &NapiQueue::dequeue),
    InstanceMethod("enqueue", &NapiQueue::enqueue),
  });

  constructor = Napi::Persistent(function);
  constructor.SuppressDestruct();

  exports.Set("NapiQueue", function);
  return exports;
};

NapiQueue::NapiQueue(const Napi::CallbackInfo& info): Napi::ObjectWrap<NapiQueue>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // this->_queue = new Queue<Napi::ObjectReference>();
  this->arr = new Napi::Value[1];

  this->_queue = new Queue<Napi::Value>();
  this->_queueInt = new Queue<int>();
  this->_objects = new Queue<KeyValue>();

};

Napi::Value NapiQueue::enqueue(const Napi::CallbackInfo& info) {
  // Napi::Env env = Napi::Env();
  // Napi::HandleScope scope(env);

  Napi::Object arg = info[0].As<Napi::Object>();

  Napi::Array keys = arg.GetPropertyNames();
  
  // int n = 356;
  // int* a = &n;
  
  // cout<<a<<": ptra"<<endl;
  // cout<<*a<<": value ptra"<<endl;

  // this->_queueInt->enqueue(a); 

  Napi::Value s = keys.Get((uint32_t)0);
  string str = s.As<Napi::String>().Utf8Value();
  string value = arg.Get(str).As<Napi::String>().Utf8Value();
  cout<<value<<" ref obj `"<<endl;
  KeyValue* pair = new KeyValue(str, value);
  cout<<"Pait: -> "<<pair<<endl;
  cout<<pair->key<<" <- Key "<<pair->value<<" <- Value"<<endl;
  this->_objects->enqueue(pair);


  return Napi::Value::From(info.Env(), s);
}

void foo (Napi::Object b) {
  cout<<b<<" asdasda"<<endl;
  // Napi::ObjectReference ref = Napi::ObjectReference::New(b, 1);

}

Napi::Value NapiQueue::dequeue(const Napi::CallbackInfo& info) {
  // Napi::Env env = info.Env();
  // Napi::HandleScope scope(env);
  cout<<"DEQUEUEING NODE!!!!!!!!"<<endl;

  KeyValue* obj = this->_objects->dequeue();

  cout<<obj->key<<" <- Key "<<obj->value<<" <- Value"<<endl;

  cout<<obj<<endl;

  Napi::Object val = Napi::Object::New(info.Env());
  val.Set(obj->key, obj->value);
  // val.Set(obj2->key, obj2->value);

  // Napi::ObjectReference ref = Napi::ObjectReference::New(val);
  // ref.Set()


  // cout<<ref.Value()<<endl;

  // return *obj2;
  // return Napi::Value(env, obj1).ToObject();

  // sleep(2000)

  return Napi::Value(info.Env(), val).ToObject();
}
