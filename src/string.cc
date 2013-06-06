#include "v8.h"
#include "node.h"

using namespace v8;

Handle<Value> Greet(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::New("value"),
            String::New("Hello World"));

    exports->Set(String::New("greet"),
            FunctionTemplate::New(Greet)->GetFunction());
}

Handle<Value>
Greet(const Arguments &args) {
    HandleScope Scope;

    if (!args[0]->IsString())
        return Scope.Close(Undefined());

    char * string = (char *) args[0]->ToString()
        ->GetExternalAsciiStringResource();

    Handle<String> RString = String::New("Hello ");

    RString->WriteAscii(string);

    return Scope.Close(RString);
}

NODE_MODULE(string, Initialize);
