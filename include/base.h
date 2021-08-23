#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include <map>
#include <string>

using std::string;
using std::map;

class VarTable {
    VarTable* next; // outer scope
    map<string, int> mmap;

public:
    int& find(string key);
    int hasDefined(string key);
    int is(string key);
};



class IMaster {
protected: 
    VarTable* vars;
public:
    IMaster(VarTable *v) : vars(v) {}
    virtual int run(pANTLR3_BASE_TREE root) = 0;
    virtual ~IMaster() {}
};



class IFactory {
public:
    IMaster* create(VarTable*);
    IFactory* next;
};




#endif
