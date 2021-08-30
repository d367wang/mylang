#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include "Context.h"
#include "ast.h"
#include "types.h"
#include <memory>

using std::shared_ptr;

namespace MYLANG {

    class IMaster {
    protected:
        shared_ptr<Context> vars;
    public:
        IMaster(shared<Context> v) : vars(v) {}

        virtual ~IMaster() {}

        virtual shared_ptr<IValue> run(IAST *root) = 0;

        virtual void handle_error(string msg) {
            throw std::runtime_error(msg);
        }
    };


    class IFactory {
    public:
        IFactory(IFactory *n) : next(n) {}

        virtual IMaster *create(shared_ptr<Context>) = 0;

        virtual bool isValid(IAST *) = 0;

        IFactory *next;
    };

}
#endif
