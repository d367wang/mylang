//
// Created by d367wang on 2021-08-25.
//

#ifndef ECHO_CUSTOMAST_H
#define ECHO_CUSTOMAST_H


class CustomAST {
public:
    int getTokenType();
    std::string getText();
    IAST* getChild(unsigned int i);
    int getChildCount();
};


#endif //ECHO_CUSTOMAST_H
