#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Revert(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            Boolean::New(false));

    exports->Set(String::NewSymbol("revert"),
            FunctionTemplate::New(Revert)->GetFunction());
}

Handle<Value>
Revert(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsBoolean()) {
        ThrowException(Exception::Error(
                    String::New("Argument should be a Boolean.")));

        return scope.Close(Undefined());
    }

    bool boo = args[0]->BooleanValue();

    return scope.Close(Boolean::New(!boo));
}

NODE_MODULE(boolean, Initialize)
