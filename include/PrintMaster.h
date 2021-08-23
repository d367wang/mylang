#ifndef _PRINTMASTER_H
#define _PRINTMASTER_H

#include "base.h"

class PrintMaster : public IMaster
{
private:
    /* data */
public:
    PrintMaster(Context* ctx) : IMaster(ctx) {}
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
