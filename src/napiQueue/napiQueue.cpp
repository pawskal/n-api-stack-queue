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
};

Napi::Value NapiQueue::enqueue(const Napi::CallbackInfo& info) {
   Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object arg = info[0].As<Napi::Object>();
  Napi::ObjectReference ref = Napi::ObjectReference::New(arg);

  Napi::Array keys = arg.GetPropertyNames();
  
  // cout<<Napi::Value(keys['0']).As<Napi::String>().ToString()<<" ref obj `"<<endl;
 
  this->_queueInt->enqueue(1); 

  Napi::Value s = keys.Get((uint32_t)0);
  string str = s.As<Napi::String>().Utf8Value();
  cout<<arg.Get(str).As<Napi::String>().Utf8Value()<<" ref obj `"<<endl;


  return Napi::Value::From(env, s);
}

void foo (Napi::Object b) {
  cout<<b<<" asdasda"<<endl;
  // Napi::ObjectReference ref = Napi::ObjectReference::New(b, 1);

}

Napi::Value NapiQueue::dequeue(const Napi::CallbackInfo& info) {
  // Napi::Env env = info.Env();
  // Napi::HandleScope scope(env);

  int obj1 = this->_queueInt->dequeue();
  cout<<obj1<<" OBJ 1 "<<endl;
  // Napi::ObjectReference ob = Napi::ObjectReference::New(obj1.ToObject());
  // cout<<ob.Value()<<" ref obj `"<<endl;
  // Napi::Object* obj2 = &obj1;
  // foo(*obj2);
  // Napi::ObjectReference ref = Napi::ObjectReference::New(obj1, 1);
  // ref.SuppressDestruct();
  // std::cout<<(std::string)ref.Get("a").ToString()<<endl;

  // Napi::Value* val = Napi::ObjectWrap<Napi::Object>::Unwrap(obj1);


  // cout<<ref.Value()<<endl;

  // return *obj2;
  // return Napi::Value(env, obj1).ToObject();

  // sleep(2000)

  return Napi::Number::From(info.Env(), obj1);
}
