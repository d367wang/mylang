#ifndef _PROGRAM_HANDLER_H
#define _PROGRAM_HANDLER_H

#include "base.h"

class ProgramHandler : public IMaster
{
private:
    /* data */
public:
    ProgramHandler(Context* ctx) : IMaster(ctx) {}
    IValue run(IAST* root);

    class ProgramFactory : public IFactory
    {
    private:
        /* data */
    public:
        ProgramFactory(IFactory* n) : IFactory(n) {}

        IMaster* create(Context* ctx);
        bool isValid(pANTLR3_BASE_TREE tree);
    };
};

#endif
