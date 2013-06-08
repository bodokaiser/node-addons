#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Push(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            Array::New());

    exports->Set(String::NewSymbol("push"),
            FunctionTemplate::New(Push)->GetFunction());
}

Handle<Value>
Push(const Arguments &args) {
    HandleScope scope;
    
    if (!args[0]->IsArray() || args[1]->IsUndefined()) {
        ThrowException(Exception::TypeError(
                    String::New("Argument should be an Array.")));

        return scope.Close(Undefined());
    }

    Local<Array> arr = Local<Array>::Cast(args[0]->ToObject());

    int i = arr->Length();

    arr->Set(Number::New(i), args[1]);
    
    return scope.Close(arr);
}

NODE_MODULE(array, Initialize)
