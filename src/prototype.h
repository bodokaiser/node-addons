#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "node.h"

class Prototype : public node::ObjectWrap {
    public:
        static void Initialize(v8::Handle<v8::Object> module);

    private:
        Prototype();
        ~Prototype();

        static v8::Handle<v8::Value> New(const v8::Arguments &args);
        static v8::Handle<v8::Value> Get(const v8::Arguments &args);
        static v8::Handle<v8::Value> Set(const v8::Arguments &args);

        v8::Handle<v8::Object> obj_;
};

#endif
