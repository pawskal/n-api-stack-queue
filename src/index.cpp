// #include <napi.h>
#include "napiQueue/napiQueue.cpp"

Napi::String hello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Napi::String::New(env, "Hello world!");
}

Napi::Number multiply(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Number arg1 = info[0].As<Napi::Number>();
  Napi::Number arg2 = info[1].As<Napi::Number>();

  int a = arg1.Int32Value();
  int b = arg2.Int32Value();

  int result = a * b;
  return Napi::Number::New(env, result);
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, hello));
    exports.Set(Napi::String::New(env, "multiply"), Napi::Function::New(env, multiply));
    return NapiQueue::Init(env, exports);
    // return exports;
};

NODE_API_MODULE(nApiStackQueue, init);