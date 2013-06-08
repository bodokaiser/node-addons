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
    HandleScope Scope;

    if (!args[0]->IsObject() || !args[1]->IsString())
        return Scope.Close(Undefined());

    Local<Object> ObjectArg = args[0]->ToObject();
    Local<String> StringArg = args[1]->ToString();

    if (!ObjectArg->Has(StringArg))
        return Scope.Close(Undefined());

    return Scope.Close(ObjectArg->Get(StringArg));
}

Handle<Value>
Set(const Arguments &args) {
    HandleScope Scope;

    if (!args[0]->IsObject() || !args[1]->IsString())
        return Scope.Close(Undefined());

    Local<Object> ObjectArg = args[0]->ToObject();
    Local<String> StringArg = args[1]->ToString();
    
    ObjectArg->Set(StringArg, args[2]);
    
    return Scope.Close(ObjectArg);
}

NODE_MODULE(object, Initialize);
