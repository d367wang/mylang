#ifndef _EXPR_HANDLER_H 
#define _EXPR_HANDLER_H

#include "base.h"

namespace MYLANG {

    class ExprHandler : public IMaster {
    private:
        /* data */
    public:
        ExprHandler(Context *ctx) : IMaster(ctx) {}

        std::shared_ptr<IValue> run(IAST *root);

        class ExprFactory : public IFactory {
        private:
            /* data */
        public:
            ExprFactory(IFactory *n) : IFactory(n) {}

            IMaster *create(Context *ctx);

            bool isValid(IAST *tree);
        };

    };
}
#endif
