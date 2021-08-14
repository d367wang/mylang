/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Aug 2021 06:33:06 PM
 ************************************************************************/

#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;
using std::map;


pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE);

class ExprEvaluator {
    map<string, int> mmap;
public:
    int eval(pANTLR3_BASE_TREE root) {
        pANTLR3_COMMON_TOKEN tok = root->getToken(root);
        if (tok != nullptr) {
            switch (tok->type) {
                case INT: {
                    const char* str = getText(root);
                    if (str[0] == '-')
                        return -atoi(getText(root));
                    else 
                        return atoi(getText(root));
                } 

                case ID: {
                    string s(getText(root));
                    return mmap[s];
                } 

                case PLUS:
                    return eval(getChild(root, 0)) +
                            eval(getChild(root, 1));

                case MINUS:
                    return eval(getChild(root, 0)) -
                            eval(getChild(root, 1));

                case TIMES:
                    return eval(getChild(root, 0)) *
                            eval(getChild(root, 1));

                case ASSIGN: {
                    string varname = getText(getChild(root, 0));
                    int rval = eval(getChild(root, 1));
                    mmap[varname] = rval;
                    return rval;
                } 

                default:
                    std::cout << "unknown handler: " 
                                << getText(root) << std::endl;
                    return -1;
            }

        } else {
            int res, cnt;
            cnt = root->getChildCount(root);
            for (int i = 0; i < cnt; i++) {
                res = eval(getChild(root, i));
            }

            return res;
        }
    }
};


int main(int argc, char** argv) {
    assert(argc > 1);
    pANTLR3_INPUT_STREAM input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);

    pExprCppTreeLexer lex = ExprCppTreeLexerNew(input);

    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(
                                        ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pExprCppTreeParser parser = ExprCppTreeParserNew(tokens);

    ExprCppTreeParser_prog_return r = parser->prog(parser);

    pANTLR3_BASE_TREE tree = r.tree;

    ExprEvaluator* evaluator = new ExprEvaluator();
    cout << evaluator->eval(tree);
    return 0;
}
