//
// Created by d367wang on 2021-08-25.
//

#include "tree/AntlrASTWrapper.h"

int AntlrASTWrapper::getTokenType();
std::string AntlrASTWrapper::getText();
IAST* AntlrASTWrapper::getChild();
int AntlrASTWrapper::getChildCount()
int AntlrASTWrapper::getTokenType(pANTLR3_BASE_TREE tree) {
    return tree->getToken(tree)->type;
}

AntlrASTWrapper* AntlrASTWrapper::getChild(unsigned i) {
    assert(i < tree->getChildCount(tree));
    return tree->getChild(tree, i);
}

const char* AntlrASTWrapper::getText() {
    return (const char*) tree->getText(tree)->chars;
}


int AntlrASTWrapper::getChildCount() {
    return tree->getChildCount(tree);
}