
#include "Utils.h"
#include ""
using ASTree = pAna

pANTLR3_BASE_TREE Utils::getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) (tree->getChild(tree, i));
}
const char* Utils::getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}


