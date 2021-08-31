#include "PrintHandler.h"
#include "Chain.h"


    shared_ptr<IValue> PrintHandler::run(IAST *root) {
        shared_ptr<IValue> res;
        // root for AST of the file
        if (root->getTokenType() == PRINT) {
            res = MasterChain::getInstance()->process(root->getChild(0), this->vars);
            return res;
        }

        throw runtime_error("unknown handler: " + root->getText());
    }

    IMaster *PrintHandler::PrintFactory::create(shared_ptr<Context> ctx) {
        return new PrintHandler(ctx);
    }

    bool PrintHandler::PrintFactory::isValid(IAST *tree) {
        return tree->getTokenType() == PRINT;
    }

