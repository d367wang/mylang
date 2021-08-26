//
// Created by d367wang on 2021-08-25.
//

#ifndef ECHO_AST_H
#define ECHO_AST_H

#include <string>
#include <string>

class IAST {
public:
    virtual int getTokenType() = 0;
    virtual std::string getText() = 0;
    virtual IAST* getChild() = 0;
    virtual int getChildCount() = 0;
};

#endif //ECHO_AST_H
