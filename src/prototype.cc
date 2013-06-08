#include "v8.h"
#include "node.h"
#include "prototype.h"

using namespace v8;

Prototype::Prototype() {};
Prototype::~Prototype() {};

void
Prototype::Initialize(Handle<Object> module) {
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

    tpl->SetClassName(String::NewSymbol("Prototype"));
    
    tpl->InstanceTemplate()
        ->SetInternalFieldCount(1);

    tpl->PrototypeTemplate()
        ->Set(String::NewSymbol("get"),
                FunctionTemplate::New(Get)->GetFunction());
    tpl->PrototypeTemplate()
        ->Set(String::NewSymbol("set"),
                FunctionTemplate::New(Set)->GetFunction());

    Persistent<Function> constructor = Persistent<Function>::
        New(tpl->GetFunction());

    module->Set(String::NewSymbol("exports"), constructor);
}

Handle<Value>
Prototype::New(const Arguments &args) {
    HandleScope scope;
    
    Prototype * proto = new Prototype();

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(
                    String::New("Argument must be a String.")));

        return scope.Close(Undefined());
    }

    proto->obj_ = Object::New();
    proto->obj_->Set(String::NewSymbol("name"), 
            args[0]->ToString());

    proto->Wrap(args.This());

    return scope.Close(args.This());
}

Handle<Value>
Prototype::Get(const Arguments &args) {
    HandleScope scope;

    Prototype * proto = ObjectWrap::Unwrap<Prototype>(args.This());

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(
                    String::New("Argument must be a String.")));

        return scope.Close(Undefined());
    }

    Local<String> str = args[0]->ToString();

    return scope.Close(proto->obj_->Get(str));
}

Handle<Value>
Prototype::Set(const Arguments &args) {
    HandleScope scope;

    Prototype * proto = ObjectWrap::Unwrap<Prototype>(args.This());

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(
                    String::New("First argument must be a String.")));

        return scope.Close(Undefined());
    }

    proto->obj_->Set(args[0]->ToString(), args[1]);

    return scope.Close(args.This());
}

void 
Initialize(Handle<Object> exports, Handle<Object> module) {
    Prototype::Initialize(module);
}

NODE_MODULE(prototype, Initialize)
