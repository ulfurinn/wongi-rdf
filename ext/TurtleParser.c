/** \file
 *  This C source file was generated by $ANTLR version !Unknown version!
 *
 *     -  From the grammar source file : ext/Turtle.g
 *     -                            On : 2012-06-25 10:38:11
 *     -                for the parser : TurtleParserParser *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
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


/* =============================================================================
 * This is what the grammar programmer asked us to put at the top of every file.
 */

	#include <ruby.h>

/* End of Header action.
 * =============================================================================
 */
/* -----------------------------------------
 * Include the ANTLR3 generated header file.
 */
#include    "TurtleParser.h"
/* ----------------------------------------- */





/* MACROS that hide the C interface implementations from the
 * generated code, which makes it a little more understandable to the human eye.
 * I am very much against using C pre-processor macros for function calls and bits
 * of code as you cannot see what is happening when single stepping in debuggers
 * and so on. The exception (in my book at least) is for generated code, where you are
 * not maintaining it, but may wish to read and understand it. If you single step it, you know that input()
 * hides some indirect calls, but is always referring to the input stream. This is
 * probably more readable than ctx->input->istream->input(snarfle0->blarg) and allows me to rejig
 * the runtime interfaces without changing the generated code too often, without
 * confusing the reader of the generated output, who may not wish to know the gory
 * details of the interface inheritance.
 */
 
#define		CTX	ctx

/* Aids in accessing scopes for grammar programmers
 */
#undef	SCOPE_TYPE
#undef	SCOPE_STACK
#undef	SCOPE_TOP
#define	SCOPE_TYPE(scope)   pTurtleParser_##scope##_SCOPE
#define SCOPE_STACK(scope)  pTurtleParser_##scope##Stack
#define	SCOPE_TOP(scope)    ctx->pTurtleParser_##scope##Top
#define	SCOPE_SIZE(scope)		ctx->pTurtleParser_##scope##Stack_limit
#define SCOPE_INSTANCE(scope, i)	(ctx->SCOPE_STACK(scope)->get(ctx->SCOPE_STACK(scope),i))

/* Macros for accessing things in the parser
 */
 
#undef	    PARSER		    
#undef	    RECOGNIZER		    
#undef	    HAVEPARSEDRULE
#undef		MEMOIZE
#undef	    INPUT
#undef	    STRSTREAM
#undef	    HASEXCEPTION
#undef	    EXCEPTION
#undef	    MATCHT
#undef	    MATCHANYT
#undef	    FOLLOWSTACK
#undef	    FOLLOWPUSH
#undef	    FOLLOWPOP
#undef	    PRECOVER
#undef	    PREPORTERROR
#undef	    LA
#undef	    LT
#undef	    CONSTRUCTEX
#undef	    CONSUME
#undef	    MARK
#undef	    REWIND
#undef	    REWINDLAST
#undef	    PERRORRECOVERY
#undef	    HASFAILED
#undef	    FAILEDFLAG
#undef	    RECOVERFROMMISMATCHEDSET
#undef	    RECOVERFROMMISMATCHEDELEMENT
#undef		INDEX
#undef      ADAPTOR
#undef		SEEK
#undef	    RULEMEMO		    
#undef		DBG

#define	    PARSER							ctx->pParser  
#define	    RECOGNIZER						PARSER->rec
#define		PSRSTATE						RECOGNIZER->state
#define	    HAVEPARSEDRULE(r)				RECOGNIZER->alreadyParsedRule(RECOGNIZER, r)
#define		MEMOIZE(ri,si)					RECOGNIZER->memoize(RECOGNIZER, ri, si)
#define	    INPUT							PARSER->tstream
#define	    STRSTREAM						INPUT
#define		ISTREAM							INPUT->istream
#define		INDEX()							ISTREAM->index(INPUT->istream)
#define	    HASEXCEPTION()					(PSRSTATE->error == ANTLR3_TRUE)
#define	    EXCEPTION						PSRSTATE->exception
#define	    MATCHT(t, fs)					RECOGNIZER->match(RECOGNIZER, t, fs)
#define	    MATCHANYT()						RECOGNIZER->matchAny(RECOGNIZER)
#define	    FOLLOWSTACK					    PSRSTATE->following
#define	    FOLLOWPUSH(x)					FOLLOWSTACK->push(FOLLOWSTACK, ((void *)(&(x))), NULL)
#define	    FOLLOWPOP()						FOLLOWSTACK->pop(FOLLOWSTACK)
#define	    PRECOVER()						RECOGNIZER->recover(RECOGNIZER)
#define	    PREPORTERROR()					RECOGNIZER->reportError(RECOGNIZER)
#define	    LA(n)							INPUT->istream->_LA(ISTREAM, n)
#define	    LT(n)							INPUT->_LT(INPUT, n)
#define	    CONSTRUCTEX()					RECOGNIZER->exConstruct(RECOGNIZER)
#define	    CONSUME()						ISTREAM->consume(ISTREAM)
#define	    MARK()							ISTREAM->mark(ISTREAM)
#define	    REWIND(m)						ISTREAM->rewind(ISTREAM, m)
#define	    REWINDLAST()					ISTREAM->rewindLast(ISTREAM)
#define		SEEK(n)							ISTREAM->seek(ISTREAM, n)
#define	    PERRORRECOVERY					PSRSTATE->errorRecovery
#define	    FAILEDFLAG						PSRSTATE->failed
#define	    HASFAILED()						(FAILEDFLAG == ANTLR3_TRUE)
#define	    BACKTRACKING					PSRSTATE->backtracking
#define	    RECOVERFROMMISMATCHEDSET(s)		RECOGNIZER->recoverFromMismatchedSet(RECOGNIZER, s)
#define	    RECOVERFROMMISMATCHEDELEMENT(e)	RECOGNIZER->recoverFromMismatchedElement(RECOGNIZER, s)
#define     ADAPTOR                         ctx->adaptor
#define		RULEMEMO						PSRSTATE->ruleMemo
#define		DBG								RECOGNIZER->debugger

#define		TOKTEXT(tok, txt)				tok, (pANTLR3_UINT8)txt

/* The 4 tokens defined below may well clash with your own #defines or token types. If so
 * then for the present you must use different names for your defines as these are hard coded
 * in the code generator. It would be better not to use such names internally, and maybe
 * we can change this in a forthcoming release. I deliberately do not #undef these
 * here as this will at least give you a redefined error somewhere if they clash.
 */
#define	    UP	    ANTLR3_TOKEN_UP
#define	    DOWN    ANTLR3_TOKEN_DOWN
#define	    EOR	    ANTLR3_TOKEN_EOR
#define	    INVALID ANTLR3_TOKEN_INVALID


/* =============================================================================
 * Functions to create and destroy scopes. First come the rule scopes, followed
 * by the global declared scopes.
 */



/* ============================================================================= */

/* =============================================================================
 * Start of recognizer
 */



/** \brief Table of all token names in symbolic order, mainly used for
 *         error reporting.
 */
pANTLR3_UINT8   TurtleParserTokenNames[0+4]
     = {
        (pANTLR3_UINT8) "<invalid>",       /* String to print to indicate an invalid token */
        (pANTLR3_UINT8) "<EOR>",
        (pANTLR3_UINT8) "<DOWN>", 
        (pANTLR3_UINT8) "<UP>", 
       };

        

// Forward declare the locally static matching functions we have generated.
//
static TurtleParser_document_return	document    (pTurtleParser ctx, VALUE collector);
static void	TurtleParserFree(pTurtleParser ctx);
/* For use in tree output where we are accumulating rule labels via label += ruleRef
 * we need a function that knows how to free a return scope when the list is destroyed. 
 * We cannot just use ANTLR3_FREE because in debug tracking mode, this is a macro.
 */
static	void ANTLR3_CDECL freeScope(void * scope)
{
    ANTLR3_FREE(scope);
}

/** \brief Name of the grammar file that generated this code
 */
static const char fileName[] = "ext/Turtle.g";

/** \brief Return the name of the grammar file that generated this code.
 */
static const char * getGrammarFileName()
{
	return fileName;
}
/** \brief Create a new TurtleParser parser and return a context for it.
 *
 * \param[in] instream Pointer to an input stream interface.
 *
 * \return Pointer to new parser context upon success.
 */
ANTLR3_API pTurtleParser
TurtleParserNew   (pANTLR3_COMMON_TOKEN_STREAM instream)
{
	// See if we can create a new parser with the standard constructor
	//
	return TurtleParserNewSSD(instream, NULL);
}

/** \brief Create a new TurtleParser parser and return a context for it.
 *
 * \param[in] instream Pointer to an input stream interface.
 *
 * \return Pointer to new parser context upon success.
 */
ANTLR3_API pTurtleParser
TurtleParserNewSSD   (pANTLR3_COMMON_TOKEN_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state)
{
    pTurtleParser ctx;	    /* Context structure we will build and return   */
    
    ctx	= (pTurtleParser) ANTLR3_CALLOC(1, sizeof(TurtleParser));
    
    if	(ctx == NULL)
    {
		// Failed to allocate memory for parser context
		//
        return  NULL;
    }
    
    /* -------------------------------------------------------------------
     * Memory for basic structure is allocated, now to fill in
     * the base ANTLR3 structures. We initialize the function pointers
     * for the standard ANTLR3 parser function set, but upon return
     * from here, the programmer may set the pointers to provide custom
     * implementations of each function. 
     *
     * We don't use the macros defined in TurtleParser.h here, in order that you can get a sense
     * of what goes where.
     */

    /* Create a base parser/recognizer, using the supplied token stream
     */
    ctx->pParser	    = antlr3ParserNewStream(ANTLR3_SIZE_HINT, instream->tstream, state);
    /* Install the implementation of our TurtleParser interface
     */
    ctx->document	= document;
    ctx->free			= TurtleParserFree;
    ctx->getGrammarFileName	= getGrammarFileName;
    
    /* Install the scope pushing methods.
     */
    ADAPTOR	= ANTLR3_TREE_ADAPTORNew(instream->tstream->tokenSource->strFactory);
    ctx->vectors	= antlr3VectorFactoryNew(0);
    

	
    /* Install the token table
     */
    PSRSTATE->tokenNames   = TurtleParserTokenNames;
    
    
    /* Return the newly built parser to the caller
     */
    return  ctx;
}

/** Free the parser resources
 */
 static void
 TurtleParserFree(pTurtleParser ctx)
 {
    /* Free any scope memory
     */
    
    ctx->vectors->close(ctx->vectors);
    /* We created the adaptor so we must free it
     */
    ADAPTOR->free(ADAPTOR);
	// Free this parser
	//
    ctx->pParser->free(ctx->pParser);
    ANTLR3_FREE(ctx);

    /* Everything is released, so we can return
     */
    return;
 }
 
/** Return token names used by this parser
 *
 * The returned pointer is used as an index into the token names table (using the token 
 * number as the index).
 * 
 * \return Pointer to first char * in the table.
 */
static pANTLR3_UINT8    *getTokenNames() 
{
        return TurtleParserTokenNames; 
}

    
/* Declare the bitsets
 */
     

 
 
/* ==============================================
 * Parsing rules
 */
/** 
 * $ANTLR start document
 * ext/Turtle.g:18:1: document[VALUE collector] : ;
 */
static TurtleParser_document_return
document(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_document_return retval;
    ANTLR3_UINT32 document_StartIndex;
    pANTLR3_BASE_TREE root_0;

    /* Initialize rule variables
     */
    document_StartIndex = INDEX();


    root_0 = NULL;

    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(1)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    retval.start = LT(1); retval.stop = retval.start;



    retval.tree  = NULL;
    {
        // ext/Turtle.g:19:2: ()
        // ext/Turtle.g:20:2: 
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

        }

    }
    

    // This is where rules clean up and exit
    //
    goto ruledocumentEx; /* Prevent compiler warnings */
    ruledocumentEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);


    return retval;
}
/* $ANTLR end document */
/* End of parsing rules
 * ==============================================
 */

/* ==============================================
 * Syntactic predicates
 */
/* End of syntactic predicates
 * ==============================================
 */

 
 



/* End of code
 * =============================================================================
 */
