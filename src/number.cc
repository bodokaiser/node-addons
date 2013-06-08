#include "v8.h"
#include "node.h"
#include <math.h>
#include <stdint.h>

using namespace v8;

Handle<Value> Add(const Arguments &args);
Handle<Value> Substract(const Arguments &args);
Handle<Value> Multiply(const Arguments &args);
Handle<Value> Divide(const Arguments &args);
Handle<Value> Power(const Arguments &args);

void 
Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("value"),
            Number::New(666));

    exports->Set(String::NewSymbol("add"),
            FunctionTemplate::New(Add)->GetFunction());
    exports->Set(String::NewSymbol("substract"),
            FunctionTemplate::New(Substract)->GetFunction());
    exports->Set(String::NewSymbol("multiply"),
            FunctionTemplate::New(Multiply)->GetFunction());
    exports->Set(String::NewSymbol("divide"),
            FunctionTemplate::New(Divide)->GetFunction());
    exports->Set(String::NewSymbol("power"),
            FunctionTemplate::New(Power)->GetFunction());
}

Handle<Value>
Add(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(
                    String::New("Arguments should be Numbers.")));

        return scope.Close(Undefined());
    }

    int64_t a = args[0]->NumberValue();
    int64_t b = args[1]->NumberValue();

    return scope.Close(Number::New(a + b));
}

Handle<Value>
Substract(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(
                    String::New("Arguments should be Numbers.")));

        return scope.Close(Undefined());
    }

    int64_t a = args[0]->NumberValue();
    int64_t b = args[1]->NumberValue();

    return scope.Close(Number::New(a - b));
}

Handle<Value>
Multiply(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(
                    String::New("Arguments should be Numbers.")));

        return scope.Close(Undefined());
    }

    int64_t a = args[0]->NumberValue();
    int64_t b = args[1]->NumberValue();

    return scope.Close(Number::New(a * b));
}

Handle<Value>
Divide(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(
                    String::New("Arguments should be Numbers.")));

        return scope.Close(Undefined());
    }

    int64_t a = args[0]->NumberValue();
    int64_t b = args[1]->NumberValue();

    return scope.Close(Number::New(a / b));
}

Handle<Value>
Power(const Arguments &args) {
    HandleScope scope;

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(Exception::TypeError(
                    String::New("Arguments should be Numbers.")));

        return scope.Close(Undefined());
    }

    int64_t a = args[0]->NumberValue();
    int64_t b = args[1]->NumberValue();

    return scope.Close(Number::New(pow(a, b)));
}

NODE_MODULE(number, Initialize)
