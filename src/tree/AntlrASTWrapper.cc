#include "AntlrASTWrapper.h"
#include <cassert>

int AntlrASTWrapper::getTokenType() {
    if (tree->getToken(tree))
        return tree->getToken(tree)->type;
    return -1;
}

IAST* AntlrASTWrapper::getChild(uint32_t i) {
    assert(i < tree->getChildCount(tree));
    return new AntlrASTWrapper((pANTLR3_BASE_TREE) tree->getChild(tree, i));
}

const string AntlrASTWrapper::getText() {
    return (const char*) tree->getText(tree)->chars;
}


int AntlrASTWrapper::getChildCount() {
    return tree->getChildCount(tree);
}