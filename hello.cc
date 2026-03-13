#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context =
      exports->GetCreationContext().ToLocalChecked();
  exports->Set(context,
               Nan::New("hello").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(hello, Init)
//
//#include <nan.h>
//
//void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
//  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
//}
//
//void Init(v8::Local<v8::Object> exports) {
//  v8::Local<v8::Context> context =
//      exports->GetCreationContext().ToLocalChecked();
//
//  // --- BEGIN: Minimal block to trigger the Electron/V8 error ---
//  // Create a tiny object with an internal field and use the *legacy*
//  // untagged internal-field pointer API that no longer exists in V8 14+.
//  v8::Local<v8::FunctionTemplate> t = Nan::New<v8::FunctionTemplate>();
//  t->InstanceTemplate()->SetInternalFieldCount(1);
//  v8::Local<v8::Object> inst =
//      Nan::NewInstance(Nan::GetFunction(t).ToLocalChecked(), 0, nullptr)
//          .ToLocalChecked();
//
//  // This legacy overload is removed in modern V8 used by Electron 41+.
//  // It will compile on some Node-only environments but *fail* on Electron 41:
//  // error: no overloaded function takes 2 arguments
//  inst->SetAlignedPointerInInternalField(0, nullptr);
//  // --- END: Minimal block ---
//
//  exports->Set(context,
//               Nan::New("hello").ToLocalChecked(),
//               Nan::New<v8::FunctionTemplate>(Method)
//                   ->GetFunction(context)
//                   .ToLocalChecked());
//}
//
//NODE_MODULE(hello, Init)
