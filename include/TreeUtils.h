#ifndef _TREE_UTILS_H
#define _TREE_UTILS_H
#include "base.h"

class TreeUtils
{
public:
    static int getTokenType(pANTLR3_BASE_TREE tree);
    static pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i); 
    static const char* getText(pANTLR3_BASE_TREE tree); 
    static int getChildCount(pANTLR3_BASE_TREE tree);
};

#endif
