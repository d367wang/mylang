#ifndef _EXPR_HANDLER_H 
#define _EXPR_HANDLER_H

#include "base.h"

class ExprHandler : public IMaster
{
private:
    /* data */
public:
    ExprHandler(Context* ctx) : IMaster(ctx) {}
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
