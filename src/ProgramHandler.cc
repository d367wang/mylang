#include "ProgramHandler.h"
#include "Chain.h"
#include "TreeUtils.h"
#include <iostream>
#include <memory>


const auto getTokenType = TreeUtils::getTokenType;
const auto getText = TreeUtils::getText;
const auto getChild = TreeUtils::getChild;
const auto getChildCount = TreeUtils::getChildCount;

IValue ProgramHandler::run(IAST* root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    int res;

    MasterChain* chain = MasterChain::getInstance();
    // root for AST of the file
    if (!tok) {
        int cnt;
        cnt = root->getChildCount(root);
        for (int i = 0; i < cnt; i++)
        {
            res = chain->process(getChild(root, i), this->vars);
        }
        return res;
    }

    // tree with a token, some element in the code 
    switch (tok->type)
    {
    case BLOCK:
    {
        std::unique_ptr<Context> newCtx = std::make_unique<Context>();        

        int cnt = root->getChildCount(root), res;
        for (int i = 0; i < cnt; i++)
        {
            res = chain->process(getChild(root, i), newCtx.get());
        }
        return res;
    }

    default:
        return handle_error("unknown handler: " + std::string(getText(root)));
    }

}


IMaster* ProgramHandler::ProgramFactory::create(Context *ctx) {
    return new ProgramHandler(ctx);
}

bool ProgramHandler::ProgramFactory::isValid(pANTLR3_BASE_TREE tree) {
    return getTokenType(tree) == BLOCK;
}