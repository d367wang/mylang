#ifndef _IFMASTER_H
#define _IFMASTER_H

#include "base.h"

class IfHandler: public IMaster
{
private:
    /* data */
public:
    IfHandler(Context* ctx) : IMaster(ctx) {}
    IValue run(IAST* root)

    class IFFactory : public IFactory
    {
    private:
        /* data */
    public:
        IFFactory(IFactory* n) : IFactory(n) {}

        IMaster* create(Context*);
        bool isValid(pANTLR3_BASE_TREE);
    };
    
};
#endif
