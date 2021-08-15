/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Aug 2021 06:33:06 PM
 ************************************************************************/

#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include "ExprEvaluator.h"
#include <cassert>
#include <string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;
using std::map;


int main(int argc, char** argv) {
    assert(argc > 1);
    pANTLR3_INPUT_STREAM input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);

    pExprCppTreeLexer lex = ExprCppTreeLexerNew(input);

    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(
                                        ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pExprCppTreeParser parser = ExprCppTreeParserNew(tokens);

    ExprCppTreeParser_prog_return r = parser->prog(parser);

    pANTLR3_BASE_TREE tree = r.tree;

    ExprEvaluator* evaluator = new ExprEvaluator(nullptr);

    evaluator->eval(tree);
    return 0;
}

