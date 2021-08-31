#include "Chain.h"
#include <iostream>


    MasterChain *MasterChain::getInstance() {
        static MasterChain instance;
        return &instance;
    }


    shared_ptr<IValue> MasterChain::process(IAST *tree, shared_ptr<Context> ctx) {
        IFactory *pf = headF;

        while (pf != nullptr) {
            if (pf->isValid(tree)) {
                IMaster *master = pf->create(ctx);
                shared_ptr<IValue> res = master->run(tree);
                delete master;
                return res;
            }
            pf = pf->next;
        }

        return nullptr;
    }

