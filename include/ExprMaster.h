#ifndef _INCLUDE/EXPRMASTER_H
#define _INCLUDE/EXPRMASTER_H

#include "base.h"

class ExprMaster : public IMaster
{
private:
    /* data */
public:
    int run(pANTLR3_BASE_TREE root);
};

#endif
