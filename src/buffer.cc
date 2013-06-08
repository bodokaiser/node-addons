#include "v8.h"
#include "node.h"
#include "node_buffer.h"

using namespace v8;

Handle<Value> Create(const Arguments &args);
Handle<Value> ToString(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            node::Buffer::New(5)->handle_);

    exports->Set(String::NewSymbol("create"),
            FunctionTemplate::New(Create)->GetFunction());
    exports->Set(String::NewSymbol("toString"),
            FunctionTemplate::New(ToString)->GetFunction());
}

Handle<Value>
Create(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsString()) {
        ThrowException(Exception::Error(
                    String::New("Argument should be a String.")));

        return scope.Close(Undefined());
    }

    int len = args[0]->ToString()->Length();
    char * str  = (* String::AsciiValue(args[0]));

    return scope.Close(node::Buffer::New(str, len)->handle_);
}

Handle<Value>
ToString(const Arguments &args) {
    HandleScope scope;

    if (!node::Buffer::HasInstance(args[0])) {
        ThrowException(Exception::Error(
                    String::New("Argument should be a Buffer.")));

        return scope.Close(Undefined());
    }

    char * data = node::Buffer::Data(args[0]);
    size_t len = node::Buffer::Length(args[0]);
    const char * str = (const char *) data;
    
    return scope.Close(String::New(str, len));
}

NODE_MODULE(buffer, Initialize)
