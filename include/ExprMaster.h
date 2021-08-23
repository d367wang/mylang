#ifndef _EXPRMASTER_H
#define _EXPRMASTER_H

#include "base.h"

class ExprMaster : public IMaster
{
private:
    /* data */
public:
    ExprMaster(Context* ctx) : IMaster(ctx) {}
    int run(pANTLR3_BASE_TREE root);

    class ExprFactory : public IFactory
    {
    private:
        /* data */
    public:
        ExprFactory(IFactory* n) : IFactory(n) {}

        IMaster* create(Context* ctx);
        bool isValid(pANTLR3_BASE_TREE tree);
    };
    
};

#endif
