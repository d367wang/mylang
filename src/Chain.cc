#include "Chain.h"
#include <iostream>

namespace MYLANG {

    MasterChain *MasterChain::getInstance() {
        static MasterChain instance;
        return &instance;
    }


    std::shared_ptr<IValue> MasterChain::process(IAST *tree, shared_ptr<Context> ctx) {
        IFactory *pf = headF;

        while (pf != nullptr) {
            if (pf->isValid(tree)) {
                IMaster *master = pf->create(ctx);
                std::shared_ptr<IValue> res = master->run(tree);
                delete master;
                return res;
            }
            pf = pf->next;
        }

        return nullptr;
    }

}