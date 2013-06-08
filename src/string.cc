#include "v8.h"
#include "node.h"
#include <stdio.h>
#include <string.h>

using namespace v8;

Handle<Value> Greet(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            String::New("Hello World"));

    exports->Set(String::NewSymbol("greet"),
            FunctionTemplate::New(Greet)->GetFunction());
}

Handle<Value>
Greet(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(
                    String::New("Argument should be a String.")));

        return scope.Close(Undefined());
    }

    Local<String> str = args[0]->ToString();

    int nstr_len = str->Length() + 6;
    char * nstr = (char *) malloc(nstr_len);
    char * nstr_arg = (* String::AsciiValue(str));

    strcpy(nstr, "Hello ");
 
    for (int i = 0; i < str->Length(); i++) {
        nstr[i + 6] = nstr_arg[i];
    }

    return scope.Close(String::New(nstr, nstr_len));
}

NODE_MODULE(string, Initialize)
