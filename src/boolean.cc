#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> ReturnBoolean(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::New("value"),
            Boolean::New(false));

    exports->Set(String::New("exec"),
            FunctionTemplate::New(ReturnBoolean)->GetFunction());
}

Handle<Value>
ReturnBoolean(const Arguments &args) {
    HandleScope Scope;

    if (!args[0]->IsBoolean())
        return Scope.Close(Undefined());

    bool Bool = args[0]->BooleanValue();

    return Scope.Close(Boolean::New(!Bool));
}

NODE_MODULE(boolean, Initialize);
