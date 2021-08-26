//
// Created by d367wang on 2021-08-25.
//

#ifndef ECHO_ANTLRASTWRAPPER_H
#define ECHO_ANTLRASTWRAPPER_H


class AntlrASTWrapper {
    pANTLR3_BASE_TREE tree;
public:
    AntlrASTWrapper(pANTLR3_BASE_TREE t) : tree(t) {}
    int getTokenType();
    std::string getText();
    IAST* getChild();
    int getChildCount();
};


#endif //ECHO_ANTLRASTWRAPPER_H
