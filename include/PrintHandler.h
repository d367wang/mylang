#ifndef _PRINT_HANDLER_H
#define _PRINT_HANDLER_H

#include "base.h"
namespace MYLANG {

    class PrintHandler : public IMaster {
    private:
        /* data */
    public:
        PrintHandler(Context *ctx) : IMaster(ctx) {}

        shared_ptr<IValue> run(IAST *root);

        class PrintFactory : public IFactory {
        private:
            /* data */
        public:
            PrintFactory(IFactory *n) : IFactory(n) {}

            IMaster *create(Context *);

            bool isValid(IAST *);
        };
    };
}
#endif
