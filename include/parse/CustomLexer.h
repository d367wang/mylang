#ifndef _CUSTOMLEXER_H
#define _CUSTOMLEXER_H

#include <fstream>

class CustomLexer {
    const char* filename;
public:
    CustomLexer(const char* filename) : filename(filename) {}
    int next();
};


#endif //ECHO_CUSTOMLEXER_H
