#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include "Context.h"
#include <iostream>
#include <tree/ast.h>

namespace MYLANG {

    class IMaster {
    protected:
        Context *vars;
    public:
        IMaster(Context *v) : vars(v) {}

        virtual ~IMaster() {}

        virtual shared_ptr<IValue> run(IAST *root) = 0;

        virtual void handle_error(string msg) {
            throw std::runtime_error(msg);
        }
    };


    class IFactory {
    public:
        IFactory(IFactory *n) : next(n) {}

        virtual IMaster *create(Context *) = 0;

        virtual bool isValid(IAST *) = 0;

        IFactory *next;
    };

}
#endif
