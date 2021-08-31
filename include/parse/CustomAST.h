#ifndef _CUSTOMAST_H
#define _CUSTOMAST_H
#include "ast.h"

class CustomAST {
public:
    int getTokenType();
    string getText();
    IAST* getChild(unsigned int i);
    int getChildCount();
};


#endif //ECHO_CUSTOMAST_H
