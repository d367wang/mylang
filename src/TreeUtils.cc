
#include "TreeUtils.h"

int TreeUtils::getTokenType(pANTLR3_BASE_TREE tree) {
    return tree->getToken(tree)->type;
}

pANTLR3_BASE_TREE TreeUtils::getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) (tree->getChild(tree, i));
}

const char* TreeUtils::getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}


int TreeUtils::getChildCount(pANTLR3_BASE_TREE tree) {
    return tree->getChildCount(tree);
}


