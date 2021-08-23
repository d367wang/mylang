#ifndef _CHAIN_H
#define _CHAIN_H

#include "base.h"

class MasterChain {
    IMaster* head;
    MasterChain() {}
public:
    static MasterChain* getInstance();
    int process(pANTLR3_BASE_TREE);
};

#endif
