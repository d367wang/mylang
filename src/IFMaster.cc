#include "IfHandler.h"
#include "TreeUtils.h"
#include "Chain.h"
#include <iostream>

const auto getTokenType = TreeUtils::getTokenType;
const auto getText = TreeUtils::getText;
const auto getChild = TreeUtils::getChild;
const auto getChildCount = TreeUtils::getChildCount;

IValue IfHandler::run(IAST* root) {
    assert(getTokenType(root) == IF);

    int res = MasterChain::getInstance()->process(getChild(root, 0), this->vars);
    if (res) {
        // then branch: a statement or a block
        res = MasterChain::getInstance()->process(getChild(root, 1), this->vars);

    } else if (root->getChildCount(root) == 3) {
        // else branch exists: a statement or a block
        res = MasterChain::getInstance()->process(getChild(root, 1), this->vars);
    }

    // TODO: consider `else if`

    return res;
}


IMaster* IfHandler::IFFactory::create(Context* ctx) {
    return new IfHandler(ctx);
}

bool IfHandler::IFFactory::isValid(pANTLR3_BASE_TREE tree) {
    return getTokenType(tree) == IF;
}