#ifndef _EXPR_HANDLER_H 
#define _EXPR_HANDLER_H

#include "base.h"

    class ExprHandler : public IMaster {
    private:
        /* data */
    public:
        ExprHandler(shared_ptr<Context> ctx) : IMaster(ctx) {}

        shared_ptr<IValue> run(IAST *root);

        class ExprFactory : public IFactory {
        private:
            /* data */
        public:
            ExprFactory(IFactory *n) : IFactory(n) {}

            IMaster *create(shared_ptr<Context> ctx);

            bool isValid(IAST *tree);
        };

    };
#endif
