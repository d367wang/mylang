#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include "Context.h"
#include <iostream>
#include <tree/ast.h>

class IMaster {
protected: 
    Context* vars;
public:
    IMaster(Context *v) : vars(v) {}
    virtual ~IMaster() {}

    virtual IValue run(IAST* root) = 0;
    virtual void handle_error(string msg) {
        throw std::runtime_error(msg);
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
