#ifndef _AST_H
#define _AST_H

#include <string>

using namespace std;

class IAST {
public:
    // token type when token is null (root of the entire AST)
    constexpr static int NONE_TOKEN = -1;
    virtual int getTokenType() = 0;
    virtual const string getText() = 0;
    virtual IAST* getChild(uint32_t i) = 0;
    virtual int getChildCount() = 0;
};


#endif
