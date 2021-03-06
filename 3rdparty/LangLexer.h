/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : Lang.g
 *     -                            On : 2021-09-19 19:21:03
 *     -                 for the lexer : LangLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
LangLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pLangLexer, which is returned from a call to LangLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in pLangLexer are  as follows:
 *
 *  - 
 void
      pLangLexer->T__40(pLangLexer)
 *  - 
 void
      pLangLexer->T__41(pLangLexer)
 *  - 
 void
      pLangLexer->T__42(pLangLexer)
 *  - 
 void
      pLangLexer->T__43(pLangLexer)
 *  - 
 void
      pLangLexer->T__44(pLangLexer)
 *  - 
 void
      pLangLexer->MOD(pLangLexer)
 *  - 
 void
      pLangLexer->DIV(pLangLexer)
 *  - 
 void
      pLangLexer->DO(pLangLexer)
 *  - 
 void
      pLangLexer->DOWHILE(pLangLexer)
 *  - 
 void
      pLangLexer->WHILE(pLangLexer)
 *  - 
 void
      pLangLexer->FOR(pLangLexer)
 *  - 
 void
      pLangLexer->PRINT(pLangLexer)
 *  - 
 void
      pLangLexer->IF(pLangLexer)
 *  - 
 void
      pLangLexer->ELSE(pLangLexer)
 *  - 
 void
      pLangLexer->OR(pLangLexer)
 *  - 
 void
      pLangLexer->AND(pLangLexer)
 *  - 
 void
      pLangLexer->GE(pLangLexer)
 *  - 
 void
      pLangLexer->NE(pLangLexer)
 *  - 
 void
      pLangLexer->LESSTHAN(pLangLexer)
 *  - 
 void
      pLangLexer->LE(pLangLexer)
 *  - 
 void
      pLangLexer->GT(pLangLexer)
 *  - 
 void
      pLangLexer->EQ(pLangLexer)
 *  - 
 void
      pLangLexer->PLUS(pLangLexer)
 *  - 
 void
      pLangLexer->MINUS(pLangLexer)
 *  - 
 void
      pLangLexer->TIMES(pLangLexer)
 *  - 
 void
      pLangLexer->DOT(pLangLexer)
 *  - 
 void
      pLangLexer->ASSIGN(pLangLexer)
 *  - 
 void
      pLangLexer->BLOCK(pLangLexer)
 *  - 
 void
      pLangLexer->DEF(pLangLexer)
 *  - 
 void
      pLangLexer->FUNC(pLangLexer)
 *  - 
 void
      pLangLexer->INT(pLangLexer)
 *  - 
 void
      pLangLexer->ID(pLangLexer)
 *  - 
 void
      pLangLexer->FLOAT(pLangLexer)
 *  - 
 void
      pLangLexer->COMMENT(pLangLexer)
 *  - 
 void
      pLangLexer->WS(pLangLexer)
 *  - 
 void
      pLangLexer->STRING(pLangLexer)
 *  - 
 void
      pLangLexer->EXPONENT(pLangLexer)
 *  - 
 void
      pLangLexer->HEX_DIGIT(pLangLexer)
 *  - 
 void
      pLangLexer->ESC_SEQ(pLangLexer)
 *  - 
 void
      pLangLexer->OCTAL_ESC(pLangLexer)
 *  - 
 void
      pLangLexer->UNICODE_ESC(pLangLexer)
 *  - 
 void
      pLangLexer->Tokens(pLangLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_LangLexer_H
#define _LangLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct LangLexer_Ctx_struct LangLexer, * pLangLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
LangLexer

 */
struct LangLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mT__40)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mT__41)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mT__42)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mT__43)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mT__44)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mMOD)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mDIV)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mDO)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mDOWHILE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mWHILE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mFOR)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mPRINT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mIF)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mELSE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mOR)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mAND)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mGE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mNE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mLESSTHAN)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mLE)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mGT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mEQ)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mPLUS)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mMINUS)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mTIMES)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mDOT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mASSIGN)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mBLOCK)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mDEF)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mFUNC)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mINT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mID)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mFLOAT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mCOMMENT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mWS)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mSTRING)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mEXPONENT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mHEX_DIGIT)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mESC_SEQ)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mOCTAL_ESC)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mUNICODE_ESC)	(struct LangLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct LangLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct LangLexer_Ctx_struct * ctx);
    void	    (*free)   (struct LangLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pLangLexer LangLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API pLangLexer LangLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define T__44      44
#define AND      4
#define ASSIGN      5
#define BLOCK      6
#define COMMENT      7
#define DEF      8
#define DIV      9
#define DO      10
#define DOT      11
#define DOWHILE      12
#define ELSE      13
#define EQ      14
#define ESC_SEQ      15
#define EXPONENT      16
#define FLOAT      17
#define FOR      18
#define FUNC      19
#define GE      20
#define GT      21
#define HEX_DIGIT      22
#define ID      23
#define IF      24
#define INT      25
#define LE      26
#define LESSTHAN      27
#define MINUS      28
#define MOD      29
#define NE      30
#define OCTAL_ESC      31
#define OR      32
#define PLUS      33
#define PRINT      34
#define STRING      35
#define TIMES      36
#define UNICODE_ESC      37
#define WHILE      38
#define WS      39
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for LangLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
