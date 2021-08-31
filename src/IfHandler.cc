#include "IfHandler.h"
#include "Chain.h"
#include <iostream>


    shared_ptr<IValue> IfHandler::run(IAST *root) {
        assert(root->getTokenType() == IF);

        shared_ptr<IValue> res = MasterChain::getInstance()->process(root->getChild(0), this->vars);
        if (res) {
            // then branch: a statement or a block
            res = MasterChain::getInstance()->process(root->getChild(1), this->vars);

        } else if (root->getChildCount() == 3) {
            // else branch exists: a statement or a block
            res = MasterChain::getInstance()->process(root->getChild(1), this->vars);
        }

        // TODO: consider `else if`

        return res;
    }


    IMaster *IfHandler::IFFactory::create(shared_ptr<Context> ctx) {
        return new IfHandler(ctx);
    }

    bool IfHandler::IFFactory::isValid(IAST *tree) {
        return tree->getTokenType() == IF;
    }

