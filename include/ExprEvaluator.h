#ifndef _EXPR_EVALUATOR
#define _EXPR_EVALUATOR

#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <map>
#include <string>

using std::string;
using std::map;


class ExprEvaluator {
    map<string, int> mmap;
    pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i);
    const char* getText(pANTLR3_BASE_TREE tree);

public:
    ExprEvaluator* next; // outer scope
    ExprEvaluator(ExprEvaluator *next) : next(next) {}
    int eval(pANTLR3_BASE_TREE root);
    int& find(string key); 
};

#endif
