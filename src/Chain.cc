#include "Chain.h"
#include <iostream>

MasterChain* MasterChain::getInstance() {
    static MasterChain instance;
    return &instance;
}


int MasterChain::process(pANTLR3_BASE_TREE tree, Context* ctx) {
    IFactory* pf = headF;

    while (pf != nullptr)
    {
        if (pf->isValid(tree)) {
            IMaster* master = pf->create(ctx);
            int res = master->run(tree);
            delete master;
            return res;
        }
        pf = pf->next;
    }

    std::cout << "Cannot process unknown token" << std::endl;
    return -1;
}

