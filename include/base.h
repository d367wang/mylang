#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include "Context.h"
#include <iostream>

class IMaster {
protected: 
    Context* vars;
public:
    IMaster(Context *v) : vars(v) {}
    virtual ~IMaster() {}

    virtual int run(pANTLR3_BASE_TREE root) = 0;
    virtual int handle_error(string msg) { 
        // TODO: a better way to report error and terminate
        std::cout << msg << std::endl;
        exit(1);
    }
};



class IFactory {
public:
    IFactory(IFactory* n) : next(n) {}

    virtual IMaster* create(Context*) = 0;
    virtual bool isValid(pANTLR3_BASE_TREE) = 0;
    IFactory* next;
};

#endif
