#include "PrintMaster.h"
#include "Chain.h"
#include "TreeUtils.h"

const auto getTokenType = TreeUtils::getTokenType;
const auto getText = TreeUtils::getText;
const auto getChild = TreeUtils::getChild;
const auto getChildCount = TreeUtils::getChildCount;

int PrintMaster::run(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    int res = -1;

    // root for AST of the file
    if (tok->type == PRINT) {
        res = MasterChain::getInstance()->process(getChild(root, 0), this->vars);
    }

    return handle_error("unknown handler: " + std::string(getText(root)));
}

IMaster* PrintMaster::PrintFactory::create(Context* ctx) {
    return new PrintMaster(ctx);
}

bool PrintMaster::PrintFactory::isValid(pANTLR3_BASE_TREE tree) {
    return getTokenType(tree) == PRINT;
}