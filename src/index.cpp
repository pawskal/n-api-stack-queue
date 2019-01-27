#include <napi.h>

Napi::String hello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Napi::String::New(env, "Hello world!");
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, hello));
    return exports;
};

NODE_API_MODULE(nApiStackQueue, init);