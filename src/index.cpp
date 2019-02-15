// #include <napi.h>
#include "napiQueue/napiQueue.cpp"
#include <chrono>
#include <thread>

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

class SumAsyncWorker : public Napi::AsyncWorker {
  public: 
    SumAsyncWorker(const Napi::Function& callback, const double arg0, const double arg1)
      : Napi::AsyncWorker(callback), arg0(arg0), arg1(arg1), sum(0){}

  protected:
    void Execute() override {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      sum = arg0 + arg1;
    }

    void OnOK() override {
      Napi::Env env = Env();

      Callback().MakeCallback(
        Receiver().Value(), {
          env.Null(),
          Napi::Number::New(env, sum)
        }
      );
    }

    void OnError(const Napi::Error& e) override {
      Napi::Env env = Env();

      Callback().MakeCallback(
        Receiver().Value(),
        {
          e.Value(),
          env.Undefined()
        }
      );
    }
  private:
    double arg0;
    double arg1;
    double sum;
  };


void sumAsync(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 3) {
    Napi::TypeError::New(env, "Invalid argument count").ThrowAsJavaScriptException();
    return;
  }

  if (!info[2].IsFunction()) {
    Napi::TypeError::New(env, "Invalid argument types").ThrowAsJavaScriptException();
    return;
  }

  Napi::Function cb = info[2].As<Napi::Function>();

  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();

  SumAsyncWorker * worker = new SumAsyncWorker(cb, arg0, arg1);

  worker->Queue();
}



Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, hello));
    exports.Set(Napi::String::New(env, "multiply"), Napi::Function::New(env, multiply));
    exports.Set(Napi::String::New(env, "sum"), Napi::Function::New(env, sumAsync));
    return NapiQueue::Init(env, exports);
    // return exports;
};

NODE_API_MODULE(nApiStackQueue, init);