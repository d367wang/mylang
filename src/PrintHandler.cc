#include "PrintHandler.h"
#include "Chain.h"
#include "TreeUtils.h"

namespace MYLANG {

    shared_ptr<IValue> PrintHandler::run(IAST *root) {
        std::shared_ptr<IValue> res;
        // root for AST of the file
        if (root->getTokenType() == PRINT) {
            res = MasterChain::getInstance()->process(root->getChild(0), this->vars);
            return res;
        }

        handle_error("unknown handler: " + std::string(root->getText()));
    }

    IMaster *PrintHandler::PrintFactory::create(Context *ctx) {
        return new PrintHandler(ctx);
    }

    bool PrintHandler::PrintFactory::isValid(IAST *tree) {
        return tree->getTokenType() == PRINT;
    }

}