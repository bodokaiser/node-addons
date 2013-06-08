#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Get(const Arguments &args);
Handle<Value> Set(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            Object::New());

    exports->Set(String::NewSymbol("get"),
            FunctionTemplate::New(Get)->GetFunction());
    exports->Set(String::NewSymbol("set"),
            FunctionTemplate::New(Set)->GetFunction());
}

Handle<Value>
Get(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsObject()) {
        ThrowException(Exception::Error(
                    String::New("First argument should be an Object.")));

        return scope.Close(Undefined());
    }

    if (!args[1]->IsString()) {
        ThrowException(Exception::Error(
                    String::New("Second argument should be a String.")));

        return scope.Close(Undefined());
    }

    Local<Object> obj = args[0]->ToObject();
    Local<String> str = args[1]->ToString();

    if (!obj->Has(str))
        return scope.Close(Undefined());

    return scope.Close(obj->Get(str));
}

Handle<Value>
Set(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsObject()) {
        ThrowException(Exception::Error(
                    String::New("First argument should be an Object.")));

        return scope.Close(Undefined());
    }

    if (!args[1]->IsString()) {
        ThrowException(Exception::Error(
                    String::New("Second argument should be a String.")));

        return scope.Close(Undefined());
    }

    if (args[2]->IsUndefined()) {
        ThrowException(Exception::Error(
                    String::New("Third argument should not be Undefined.")));

        return scope.Close(Undefined());
    }

    Local<Object> obj = args[0]->ToObject();
    Local<String> str = args[1]->ToString();
    
    obj->Set(str, args[2]);
    
    return scope.Close(obj);
}

NODE_MODULE(object, Initialize);
