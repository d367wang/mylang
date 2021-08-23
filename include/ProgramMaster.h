#ifndef _PROGRAM_MASTER_H
#define _PROGRAM_MASTER_H

#include "base.h"

class ProgramMaster : public IMaster
{
private:
    /* data */
public:
    ProgramMaster(Context* ctx) : IMaster(ctx) {}
    int run(pANTLR3_BASE_TREE root);

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
