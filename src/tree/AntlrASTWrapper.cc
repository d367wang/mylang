#include "AntlrASTWrapper.h"
#include <cassert>

int AntlrASTWrapper::getTokenType() {
    if (tree->getToken(tree))
        return tree->getToken(tree)->type;
    return -1;
}

IAST* AntlrASTWrapper::getChild(uint32_t i) {
    assert(i < tree->getChildCount(tree));
    return tree->getChild(tree, i);
}

const std::string AntlrASTWrapper::getText() {
    return tree->getText(tree)->chars;
}


int AntlrASTWrapper::getChildCount() {
    return tree->getChildCount(tree);
}