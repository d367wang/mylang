#include "Chain.h"

MasterChain* MasterChain::getInstance() {
    static MasterChain instance;
    return &instance;
}


int MasterChain::process(pANTLR3_BASE_TREE) {
    IMaster* p = head;
    while (p != nullptr)
}

