#ifndef _CONTEXT_H 
#define _CONTEXT_H

#include <map>
#include <string>

using std::string;
using std::map;

class Context {
    Context* next; // outer scope
    map<string, int> mmap;

public:
    bool isDefined(string key);
    bool isInCurrent(string key);

    void setVal(string key, int val);
    int& getVal(string key);

    void addVal(string key);
    void addVal(string key, int val);
};


#endif
