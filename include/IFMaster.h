#ifndef _IFMASTER_H
#define _IFMASTER_H

#include "base.h"

class IFMaster: public IMaster
{
private:
    /* data */
public:
    int run(pANTLR3_BASE_TREE root);
};
#endif
