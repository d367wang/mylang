#ifndef _CONTEXT_H 
#define _CONTEXT_H

#include <map>
#include <memory>
#include <string>
#include "type/types.h"

using std::string;
using std::map;
using std::shared_ptr;

namespace MYLANG {

    class Context {
        Context *next; // outer scope
        map<string, shared_ptr<IValue>> mmap;

    public:
        bool isDefined(string key);

        bool isInCurrent(string key);

        void setVal(string key, shared_ptr<IValue> val);

        shared_ptr<IValue> getVal(string key);

        void addVar(string key);

        void addVar(string key, shared_ptr<IValue> val);
    };

}
#endif
