#include "ProgramHandler.h"
#include "Chain.h"
#include <iostream>
#include <memory>
#include "ast.h"

namespace MYLANG {

shared_ptr<IValue> ProgramHandler::run(IAST* root) {
    shared_ptr<IValue> res;
    MasterChain* chain = MasterChain::getInstance();

    switch (root->getTokenType())
    {
        case IAST::NONE_TOKEN: {
            // root for AST of the file
            int cnt;
            cnt = root->getChildCount();
            for (int i = 0; i < cnt; i++)
            {
                res = chain->process(root->getChild(i), this->vars);
            }
            return res;
        }
        case BLOCK:
        {
            std::unique_ptr<Context> newCtx; // make_unique is not supported until 14

            int cnt = root->getChildCount();
            for (int i = 0; i < cnt; i++)
            {
                res = chain->process(root->getChild(i), newCtx.get());
            }
            return res;
        }

        default:
            throw std::runtime_error("unknown handler: " + std::string(root->getText()));
    }

}


IMaster* ProgramHandler::ProgramFactory::create(shared_ptr<Context> ctx) {
    return new ProgramHandler(ctx);
}

bool ProgramHandler::ProgramFactory::isValid(IAST* tree) {
    return tree->getTokenType() == BLOCK;
}
}