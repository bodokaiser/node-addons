#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "node.h"

using node::ObjectWrap;

using v8::Arguments;
using v8::Handle;
using v8::Value;
using v8::Object;

class Prototype : public ObjectWrap {
    public:
        static void Initialize(Handle<Object> module);

    private:
        Prototype();
        ~Prototype();

        static Handle<Value> New(const Arguments &args);
        static Handle<Value> Get(const Arguments &args);
        static Handle<Value> Set(const Arguments &args);

        Handle<Object> obj_;
};

#endif
