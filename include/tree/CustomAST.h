#ifndef _CUSTOMAST_H
#define _CUSTOMAST_H


class CustomAST {
public:
    int getTokenType();
    std::string getText();
    IAST* getChild(unsigned int i);
    int getChildCount();
};


#endif //ECHO_CUSTOMAST_H
