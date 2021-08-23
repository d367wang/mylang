#ifndef _UTILS_H
#define _UTILS_H

class Utils
{
public:
    static pANTLR3_BASE_TREE Utils::getChild(pANTLR3_BASE_TREE tree, unsigned i); 
    static const char* Utils::getText(pANTLR3_BASE_TREE tree); 
};

#endif
