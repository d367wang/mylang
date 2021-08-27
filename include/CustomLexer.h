//
// Created by d367wang on 2021-08-25.
//

#ifndef ECHO_CUSTOMLEXER_H
#define ECHO_CUSTOMLEXER_H

#include <fstream>

class CustomLexer {
    const char* filename;
public:
    CustomLexer(const char* filename) : filename(filename) {}
    int next();
};


#endif //ECHO_CUSTOMLEXER_H
