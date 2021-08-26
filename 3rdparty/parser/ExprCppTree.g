grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header {
    #include <assert.h>
}

// The suffix '^' means make it a root.
// The suffix '!' means ignore it.

expr: multDivExpr ((PLUS^ | MINUS^) multDivExpr)*
    ;

PLUS: '+';
MINUS: '-';

multDivExpr
    : atom ((TIMES^ | DIVIDE^) atom)*
    ;


TIMES: '*';
DIVIDE: '/';

atom: INT
    | ID
    | '('! expr ')'!
    ;

stmt: expr NEWLINE -> expr  // tree rewrite syntax
    | ID ASSIGN expr NEWLINE -> ^(ASSIGN ID expr) // tree notation
    | NEWLINE ->   // ignore
    | VAR ID ASSIGN expr NEWLINE -> ^(VAR ID expr)
    | PRINT expr NEWLINE -> ^(PRINT expr)
    | block 
    ;

ASSIGN: '=';
VAR: 'var' ;
PRINT: 'print' ;
BLOCK: '&' ;

block_stmts: stmt* 
    ;

block: '{' block_stmts '}' -> ^(BLOCK block_stmts)
    ;


prog
    : (block_stmts {pANTLR3_STRING s = $block_stmts.tree->toStringTree($block_stmts.tree);
             assert(s->chars);
             printf(" tree \%s\n", s->chars);
            }
        )
    ;

ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? '\n' ;
WS : (' '|'\t')+ {$channel = HIDDEN;};
