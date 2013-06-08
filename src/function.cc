#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Create(const Arguments &args);
Handle<Value> Anonymous(const Arguments &args);

void 
Initialize(Handle<Object> exports, Handle<Object> module) {
    module->Set(String::NewSymbol("exports"),
            FunctionTemplate::New(Create)->GetFunction());
}

Handle<Value>
Echo(const Arguments &args) {
    HandleScope scope;

    Local<String> str = String::New("Hello World");

    return scope.Close(str);
}

Handle<Value>
Create(const Arguments &args) {
    HandleScope scope;

    Local<FunctionTemplate> tpl = FunctionTemplate::New(Echo);
    Local<Function> fn = tpl->GetFunction();

    fn->SetName(String::NewSymbol("echo"));

    return scope.Close(fn);
}

NODE_MODULE(function, Initialize)
