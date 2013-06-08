#include "v8.h"
#include "node.h"
#include "node_buffer.h"

using namespace v8;

Handle<Value> Create(const Arguments &args);
Handle<Value> ToString(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::New("value"),
            node::Buffer::New(5)->handle_);

    exports->Set(String::New("create"),
            FunctionTemplate::New(Create)->GetFunction());
    exports->Set(String::New("toString"),
            FunctionTemplate::New(ToString)->GetFunction());
}

Handle<Value>
Create(const Arguments &args) {
    HandleScope Scope;

    if (!args[0]->IsString())
        return Scope.Close(Undefined());

    int length = args[0]->ToString()->Length();
    char * string  = (* String::AsciiValue(args[0]));

    return Scope.Close(node::Buffer::New(string, length)->handle_);
}

Handle<Value>
ToString(const Arguments &args) {
    HandleScope Scope;

    if (!node::Buffer::HasInstance(args[0]))
        return Scope.Close(Undefined());

    char * data = node::Buffer::Data(args[0]);
    size_t length = node::Buffer::Length(args[0]);
    const char * string = (const char *) data;
    
    return Scope.Close(String::New(string, length));
}

NODE_MODULE(buffer, Initialize)
