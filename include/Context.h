#ifndef _CONTEXT_H 
#define _CONTEXT_H

#include <map>
#include <memory>
#include <string>
#include "base.h"

using namespace std;

    class IValue;

    class Context {
        Context *next; // outer scope
        map<string, shared_ptr<IValue>> mmap;

    public:
        bool isDefined(const string& key);

        bool isInCurrent(const string& key);

        void setVal(string key, shared_ptr<IValue> val);

        shared_ptr<IValue> getVal(string key);

        void addVar(string key);

        void addVar(string key, shared_ptr<IValue> val);
    };

#endif
