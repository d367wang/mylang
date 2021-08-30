#ifndef _IFMASTER_H
#define _IFMASTER_H

#include "base.h"
namespace MYLANG {
    class IfHandler : public IMaster {
    private:
        /* data */
    public:
        IfHandler(shared_ptr<Context> ctx) : IMaster(ctx) {}

        shared_ptr<IValue> run(IAST *root);

        class IFFactory : public IFactory {
        private:
            /* data */
        public:
            IFFactory(IFactory *n) : IFactory(n) {}

            IMaster *create(shared_ptr<Context>);

            bool isValid(IAST *);
        };

    };
}
#endif
