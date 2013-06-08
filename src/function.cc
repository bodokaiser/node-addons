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
    HandleScope Scope;

    Local<String> Str = String::New("Hello World");

    return Scope.Close(Str);
}

Handle<Value>
Create(const Arguments &args) {
    HandleScope Scope;

    Local<FunctionTemplate> Tpl = FunctionTemplate::New(Echo);
    Local<Function> Fn = Tpl->GetFunction();

    Fn->SetName(String::NewSymbol("echo"));

    return Scope.Close(Fn);
}

NODE_MODULE(function, Initialize)
