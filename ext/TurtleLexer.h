/** \file
 *  This C header file was generated by $ANTLR version !Unknown version!
 *
 *     -  From the grammar source file : Turtle.g
 *     -                            On : 2012-06-25 15:24:24
 *     -                 for the lexer : TurtleLexerLexer *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer TurtleLexer has the callable functions (rules) shown below,
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
 * a parser context typedef pTurtleLexer, which is returned from a call to TurtleLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 * * The methods in pTurtleLexer are  as follows:
 *
 *  -  void      pTurtleLexer->T__9(pTurtleLexer)
 *  -  void      pTurtleLexer->T__10(pTurtleLexer)
 *  -  void      pTurtleLexer->URI(pTurtleLexer)
 *  -  void      pTurtleLexer->AT_PREFIX(pTurtleLexer)
 *  -  void      pTurtleLexer->DOT(pTurtleLexer)
 *  -  void      pTurtleLexer->IDENT(pTurtleLexer)
 *  -  void      pTurtleLexer->WS(pTurtleLexer)
 *  -  void      pTurtleLexer->Tokens(pTurtleLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
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

#ifndef	_TurtleLexer_H
#define _TurtleLexer_H
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
typedef struct TurtleLexer_Ctx_struct TurtleLexer, * pTurtleLexer;



	#include <ruby.h>


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

/** Context tracking structure for TurtleLexer
 */
struct TurtleLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;


     void (*mT__9)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mT__10)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mURI)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mAT_PREFIX)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mDOT)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mIDENT)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mWS)	(struct TurtleLexer_Ctx_struct * ctx);
     void (*mTokens)	(struct TurtleLexer_Ctx_struct * ctx);    const char * (*getGrammarFileName)();
    void	    (*free)   (struct TurtleLexer_Ctx_struct * ctx);
        
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pTurtleLexer TurtleLexerNew         (pANTLR3_INPUT_STREAM instream);
ANTLR3_API pTurtleLexer TurtleLexerNewSSD      (pANTLR3_INPUT_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the lexer will work with.
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
#define WS      8
#define AT_PREFIX      7
#define T__10      10
#define IDENT      5
#define DOT      4
#define EOF      -1
#define T__9      9
#define URI      6
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for TurtleLexer
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
