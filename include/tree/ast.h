//
// Created by d367wang on 2021-08-25.
//

#ifndef ECHO_AST_H
#define ECHO_AST_H

#include <string>
#include <string>

// token type when token is null (root of the entire AST)
class IAST {
public:
    constexpr static int NONE_TOKEN = -1;
    virtual int getTokenType() = 0;
    virtual const std::string getText() = 0;
    virtual IAST* getChild(int i) = 0;
    virtual int getChildCount() = 0;
};

#endif //ECHO_AST_H
