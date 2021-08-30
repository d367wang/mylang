#ifndef _ANTLRASTWRAPPER_H
#define _ANTLRASTWRAPPER_H

#include "ast.h"

class AntlrASTWrapper : public IAST {
    pANTLR3_BASE_TREE tree;
public:
    explicit AntlrASTWrapper(pANTLR3_BASE_TREE t) : tree(t) {}
    ~AntlrASTWrapper() = default;

    int getTokenType() override;
    const std::string getText() override;
    IAST* getChild(uint32_t i) override;
    int getChildCount() override;
};

#endif
