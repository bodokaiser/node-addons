#include "v8.h"
#include "node.h"
#include <stdio.h>
#include <string.h>

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

    Local<String> StringArg = args[0]->ToString();

    int length = StringArg->Length() + 6;

    char * string = (char *) malloc(length);
    char * string_arg = (* String::AsciiValue(StringArg));

    strcpy(string, "Hello ");
 
    /* string copy with offset */   
    for (int i = 0; i < StringArg->Length(); i++) {
        string[i + 6] = string_arg[i];
    }

    return Scope.Close(String::New(string, length));
}

NODE_MODULE(string, Initialize);
