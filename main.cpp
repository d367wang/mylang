#include "LangLexer.h"
#include "LangParser.h"
#include "base.h"
#include "ProgramHandler.h"
#include <cassert>
#include <string>
#include<iostream>
#include <tree/ast.h>
#include <tree/AntlrASTWrapper.h>
#include <tree/CustomAST.h>
#include <CustomLexer.h>

using std::string;
using std::map;
using MYLANG::ProgramHandler;
using MYLANG::Context;

AntlrASTWrapper* genAstAntlr(char* filename) {
    pANTLR3_INPUT_STREAM input = antlr3FileStreamNew((pANTLR3_UINT8)filename, ANTLR3_ENC_8BIT);

    pLangLexer lex = LangLexerNew(input);

    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(
            ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pLangParser parser = LangParserNew(tokens);

    LangParser_prog_return r = parser->prog(parser);

    return new AntlrASTWrapper(r.tree);
}

//CustomAST* genCustomAST(char* filename) {
//    new CustomLexer(filename);
//}

int main(int argc, char** argv) {
    assert(argc > 1);

    IAST* root = genAstAntlr(argv[1]);
    ProgramHandler eval(new Context);
    eval.run(root);


    return 0;
}

