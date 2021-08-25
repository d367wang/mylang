#ifndef _CONTEXT_H 
#define _CONTEXT_H

#include <map>
#include <string>
#include "types.h"

using std::string;
using std::map;

class Context {
    Context* next; // outer scope
    map<string, IValue> mmap;

public:
    bool isDefined(string key);
    bool isInCurrent(string key);

    void setVal(string key, IValue val);
    IValue& getVal(string key);

    void addVar(string key);
    void addVar(string key, IValue val);
};


#endif
