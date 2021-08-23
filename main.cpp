#include "LangLexer.h"
#include "LangParser.h"
#include "base.h"
#include "ProgramMaster.h"
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

    pLangLexer lex = LangLexerNew(input);

    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(
                                        ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pLangParser parser = LangParserNew(tokens);

    LangParser_prog_return r = parser->prog(parser);

    pANTLR3_BASE_TREE tree = r.tree;


    ProgramMaster eval(new Context);
    eval.run(tree);
    return 0;
}

