#include "napiQueue.h"
#include <chrono>
#include <thread>

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

  this->_objects = new Queue<KeyValue>();
};

Napi::Value NapiQueue::enqueue(const Napi::CallbackInfo& info) {
  Napi::Object arg = info[0].As<Napi::Object>();

  Napi::Array keys = arg.GetPropertyNames();
  
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

Napi::Value NapiQueue::dequeue(const Napi::CallbackInfo& info) {
  KeyValue* obj = this->_objects->dequeue();

  cout<<obj->key<<" <- Key "<<obj->value<<" <- Value"<<endl;

  cout<<obj<<endl;

  Napi::Object val = Napi::Object::New(info.Env());
  val.Set(obj->key, obj->value);

  return Napi::Value(info.Env(), val).ToObject();
}
