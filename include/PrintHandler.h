#ifndef _PRINT_HANDLER_H
#define _PRINT_HANDLER_H

#include "base.h"

class PrintHandler : public IMaster
{
private:
    /* data */
public:
    PrintHandler(Context* ctx) : IMaster(ctx) {}
    int run(pANTLR3_BASE_TREE root);

    class PrintFactory : public IFactory
    {
    private:
        /* data */
    public:
        PrintFactory(IFactory* n) : IFactory(n) {}

        IMaster* create(Context*);
        bool isValid(pANTLR3_BASE_TREE);
    };
};

#endif
