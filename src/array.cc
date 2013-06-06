#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Push(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::New("value"),
            Array::New());

    exports->Set(String::New("push"),
            FunctionTemplate::New(Push)->GetFunction());
}

Handle<Value>
Push(const Arguments &args) {
    HandleScope Scope;

    if (!args[0]->IsArray() || args[1]->IsUndefined())
        return Scope.Close(Undefined());

    Local<Array> ArrayArg = Local<Array>::Cast(args[0]->ToObject());

    int i = ArrayArg->Length();

    ArrayArg->Set(Number::New(i), args[1]);
    
    return Scope.Close(ArrayArg);
}

NODE_MODULE(array, Initialize);
