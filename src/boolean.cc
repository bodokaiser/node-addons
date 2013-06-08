#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> ReturnBoolean(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            Boolean::New(false));

    exports->Set(String::NewSymbol("exec"),
            FunctionTemplate::New(ReturnBoolean)->GetFunction());
}

Handle<Value>
ReturnBoolean(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsBoolean())
        return scope.Close(Undefined());

    bool boolean = args[0]->BooleanValue();

    return scope.Close(Boolean::New(!boolean));
}

NODE_MODULE(boolean, Initialize)
