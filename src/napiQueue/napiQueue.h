#include <napi.h>
#include "../../lib/base/queue/queue.cpp"

class NapiQueue: public Napi::ObjectWrap<NapiQueue> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    NapiQueue(const Napi::CallbackInfo& info);
    Napi::Value enqueue(const Napi::CallbackInfo& info);
    Napi::Value dequeue(const Napi::CallbackInfo& info);
  private:
    static Napi::FunctionReference constructor; 

    Napi::Value *arr;
    Queue<Napi::Value>* _queue;
    Queue<int>* _queueInt;
};
