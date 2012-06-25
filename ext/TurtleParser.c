/** \file
 *  This C source file was generated by $ANTLR version !Unknown version!
 *
 *     -  From the grammar source file : Turtle.g
 *     -                            On : 2012-06-25 15:24:24
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
	#include "extern.h"

	#define COLLECTOR_DOCUMENT rb_funcall( collector, rb_intern("document"), 0 )
	#define MATCH(string) printf("matched " string "\n");


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
pANTLR3_UINT8   TurtleParserTokenNames[7+4]
     = {
        (pANTLR3_UINT8) "<invalid>",       /* String to print to indicate an invalid token */
        (pANTLR3_UINT8) "<EOR>",
        (pANTLR3_UINT8) "<DOWN>", 
        (pANTLR3_UINT8) "<UP>", 
        (pANTLR3_UINT8) "DOT",
        (pANTLR3_UINT8) "IDENT",
        (pANTLR3_UINT8) "URI",
        (pANTLR3_UINT8) "AT_PREFIX",
        (pANTLR3_UINT8) "WS",
        (pANTLR3_UINT8) "':'",
        (pANTLR3_UINT8) "'@base'"
       };

        

// Forward declare the locally static matching functions we have generated.
//
static TurtleParser_document_return	document    (pTurtleParser ctx, VALUE collector);
static TurtleParser_statement_return	statement    (pTurtleParser ctx, VALUE collector);
static TurtleParser_directive_return	directive    (pTurtleParser ctx, VALUE collector);
static TurtleParser_namespace_declaration_return	namespace_declaration    (pTurtleParser ctx, VALUE collector);
static TurtleParser_base_declaration_return	base_declaration    (pTurtleParser ctx, VALUE collector);
static TurtleParser_uri_return	uri    (pTurtleParser ctx, VALUE collector);
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
static const char fileName[] = "Turtle.g";

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
    ctx->statement	= statement;
    ctx->directive	= directive;
    ctx->namespace_declaration	= namespace_declaration;
    ctx->base_declaration	= base_declaration;
    ctx->uri	= uri;
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

/** Bitset defining follow set for error recovery in rule state: FOLLOW_statement_in_document82  */
static	ANTLR3_BITWORD FOLLOW_statement_in_document82_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000482) };
static  ANTLR3_BITSET_LIST FOLLOW_statement_in_document82	= { FOLLOW_statement_in_document82_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_directive_in_statement95  */
static	ANTLR3_BITWORD FOLLOW_directive_in_statement95_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000010) };
static  ANTLR3_BITSET_LIST FOLLOW_directive_in_statement95	= { FOLLOW_directive_in_statement95_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_DOT_in_statement98  */
static	ANTLR3_BITWORD FOLLOW_DOT_in_statement98_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_DOT_in_statement98	= { FOLLOW_DOT_in_statement98_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_namespace_declaration_in_directive109  */
static	ANTLR3_BITWORD FOLLOW_namespace_declaration_in_directive109_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_namespace_declaration_in_directive109	= { FOLLOW_namespace_declaration_in_directive109_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_base_declaration_in_directive115  */
static	ANTLR3_BITWORD FOLLOW_base_declaration_in_directive115_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_base_declaration_in_directive115	= { FOLLOW_base_declaration_in_directive115_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_AT_PREFIX_in_namespace_declaration129  */
static	ANTLR3_BITWORD FOLLOW_AT_PREFIX_in_namespace_declaration129_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000220) };
static  ANTLR3_BITSET_LIST FOLLOW_AT_PREFIX_in_namespace_declaration129	= { FOLLOW_AT_PREFIX_in_namespace_declaration129_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_IDENT_in_namespace_declaration131  */
static	ANTLR3_BITWORD FOLLOW_IDENT_in_namespace_declaration131_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000200) };
static  ANTLR3_BITSET_LIST FOLLOW_IDENT_in_namespace_declaration131	= { FOLLOW_IDENT_in_namespace_declaration131_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_9_in_namespace_declaration134  */
static	ANTLR3_BITWORD FOLLOW_9_in_namespace_declaration134_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000040) };
static  ANTLR3_BITSET_LIST FOLLOW_9_in_namespace_declaration134	= { FOLLOW_9_in_namespace_declaration134_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_uri_in_namespace_declaration136  */
static	ANTLR3_BITWORD FOLLOW_uri_in_namespace_declaration136_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_uri_in_namespace_declaration136	= { FOLLOW_uri_in_namespace_declaration136_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_10_in_base_declaration153  */
static	ANTLR3_BITWORD FOLLOW_10_in_base_declaration153_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000040) };
static  ANTLR3_BITSET_LIST FOLLOW_10_in_base_declaration153	= { FOLLOW_10_in_base_declaration153_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_uri_in_base_declaration155  */
static	ANTLR3_BITWORD FOLLOW_uri_in_base_declaration155_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_uri_in_base_declaration155	= { FOLLOW_uri_in_base_declaration155_bits, 1	};
/** Bitset defining follow set for error recovery in rule state: FOLLOW_URI_in_uri180  */
static	ANTLR3_BITWORD FOLLOW_URI_in_uri180_bits[]	= { ANTLR3_UINT64_LIT(0x0000000000000002) };
static  ANTLR3_BITSET_LIST FOLLOW_URI_in_uri180	= { FOLLOW_URI_in_uri180_bits, 1	};
     

 
 
/* ==============================================
 * Parsing rules
 */
/** 
 * $ANTLR start document
 * Turtle.g:24:1: document[VALUE collector] : ( statement[collector] )* ;
 */
static TurtleParser_document_return
document(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_document_return retval;
    ANTLR3_UINT32 document_StartIndex;
    pANTLR3_BASE_TREE root_0;

    TurtleParser_statement_return statement1;
    #undef	RETURN_TYPE_statement1
    #define	RETURN_TYPE_statement1 TurtleParser_statement_return


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
    statement1.tree = NULL;

    retval.start = LT(1); retval.stop = retval.start;



    retval.tree  = NULL;
    {
        // Turtle.g:24:27: ( ( statement[collector] )* )
        // Turtle.g:24:29: ( statement[collector] )*
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));


            // Turtle.g:24:29: ( statement[collector] )*

            for (;;)
            {
                int alt1=2;
                switch ( LA(1) ) 
                {
                case AT_PREFIX:
                case 10:
                	{
                		alt1=1;
                	}
                    break;

                }

                switch (alt1) 
                {
            	case 1:
            	    // Turtle.g:24:29: statement[collector]
            	    {
            	        FOLLOWPUSH(FOLLOW_statement_in_document82);
            	        statement1=statement(ctx, collector);

            	        FOLLOWPOP();
            	        if  (HASEXCEPTION())
            	        {
            	            goto ruledocumentEx;
            	        }

            	        ADAPTOR->addChild(ADAPTOR, root_0, statement1.tree);

            	    }
            	    break;

            	default:
            	    goto loop1;	/* break out of the loop */
            	    break;
                }
            }
            loop1: ; /* Jump out to here if this rule does not match */


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

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end document */

/** 
 * $ANTLR start statement
 * Turtle.g:26:1: statement[VALUE collector] : directive[collector] DOT ;
 */
static TurtleParser_statement_return
statement(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_statement_return retval;
    ANTLR3_UINT32 statement_StartIndex;
    pANTLR3_BASE_TREE root_0;

    pANTLR3_COMMON_TOKEN    DOT3;
    TurtleParser_directive_return directive2;
    #undef	RETURN_TYPE_directive2
    #define	RETURN_TYPE_directive2 TurtleParser_directive_return

    pANTLR3_BASE_TREE DOT3_tree;

    /* Initialize rule variables
     */
    statement_StartIndex = INDEX();


    root_0 = NULL;

    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(2)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    DOT3       = NULL;
    directive2.tree = NULL;

    retval.start = LT(1); retval.stop = retval.start;

    DOT3_tree   = NULL;


    retval.tree  = NULL;
    {
        // Turtle.g:26:28: ( directive[collector] DOT )
        // Turtle.g:26:30: directive[collector] DOT
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

            FOLLOWPUSH(FOLLOW_directive_in_statement95);
            directive2=directive(ctx, collector);

            FOLLOWPOP();
            if  (HASEXCEPTION())
            {
                goto rulestatementEx;
            }

            ADAPTOR->addChild(ADAPTOR, root_0, directive2.tree);
            DOT3 = (pANTLR3_COMMON_TOKEN) MATCHT(DOT, &FOLLOW_DOT_in_statement98); 
            if  (HASEXCEPTION())
            {
                goto rulestatementEx;
            }

            DOT3_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, DOT3));
            ADAPTOR->addChild(ADAPTOR, root_0, DOT3_tree);


        }

    }
    

    // This is where rules clean up and exit
    //
    goto rulestatementEx; /* Prevent compiler warnings */
    rulestatementEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end statement */

/** 
 * $ANTLR start directive
 * Turtle.g:28:1: directive[VALUE collector] : ( namespace_declaration[collector] | base_declaration[collector] );
 */
static TurtleParser_directive_return
directive(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_directive_return retval;
    ANTLR3_UINT32 directive_StartIndex;
    pANTLR3_BASE_TREE root_0;

    TurtleParser_namespace_declaration_return namespace_declaration4;
    #undef	RETURN_TYPE_namespace_declaration4
    #define	RETURN_TYPE_namespace_declaration4 TurtleParser_namespace_declaration_return

    TurtleParser_base_declaration_return base_declaration5;
    #undef	RETURN_TYPE_base_declaration5
    #define	RETURN_TYPE_base_declaration5 TurtleParser_base_declaration_return


    /* Initialize rule variables
     */
    directive_StartIndex = INDEX();


    root_0 = NULL;

    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(3)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    namespace_declaration4.tree = NULL;

    base_declaration5.tree = NULL;

    retval.start = LT(1); retval.stop = retval.start;



    retval.tree  = NULL;
    {
        {
            //  Turtle.g:29:2: ( namespace_declaration[collector] | base_declaration[collector] )
            
            ANTLR3_UINT32 alt2;

            alt2=2;

            switch ( LA(1) ) 
            {
            case AT_PREFIX:
            	{
            		alt2=1;
            	}
                break;
            case 10:
            	{
            		alt2=2;
            	}
                break;

            default:
                CONSTRUCTEX();
                EXCEPTION->type         = ANTLR3_NO_VIABLE_ALT_EXCEPTION;
                EXCEPTION->message      = (void *)"";
                EXCEPTION->decisionNum  = 2;
                EXCEPTION->state        = 0;


                goto ruledirectiveEx;
            }

            switch (alt2) 
            {
        	case 1:
        	    // Turtle.g:29:4: namespace_declaration[collector]
        	    {
        	        root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

        	        FOLLOWPUSH(FOLLOW_namespace_declaration_in_directive109);
        	        namespace_declaration4=namespace_declaration(ctx, collector);

        	        FOLLOWPOP();
        	        if  (HASEXCEPTION())
        	        {
        	            goto ruledirectiveEx;
        	        }

        	        ADAPTOR->addChild(ADAPTOR, root_0, namespace_declaration4.tree);

        	    }
        	    break;
        	case 2:
        	    // Turtle.g:30:4: base_declaration[collector]
        	    {
        	        root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

        	        FOLLOWPUSH(FOLLOW_base_declaration_in_directive115);
        	        base_declaration5=base_declaration(ctx, collector);

        	        FOLLOWPOP();
        	        if  (HASEXCEPTION())
        	        {
        	            goto ruledirectiveEx;
        	        }

        	        ADAPTOR->addChild(ADAPTOR, root_0, base_declaration5.tree);

        	    }
        	    break;

            }
        }
    }
    

    // This is where rules clean up and exit
    //
    goto ruledirectiveEx; /* Prevent compiler warnings */
    ruledirectiveEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end directive */

/** 
 * $ANTLR start namespace_declaration
 * Turtle.g:33:1: namespace_declaration[VALUE collector] : '@prefix' ( IDENT )? ':' uri[collector] ;
 */
static TurtleParser_namespace_declaration_return
namespace_declaration(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_namespace_declaration_return retval;
    ANTLR3_UINT32 namespace_declaration_StartIndex;
    pANTLR3_BASE_TREE root_0;

    pANTLR3_COMMON_TOKEN    string_literal6;
    pANTLR3_COMMON_TOKEN    IDENT7;
    pANTLR3_COMMON_TOKEN    char_literal8;
    TurtleParser_uri_return uri9;
    #undef	RETURN_TYPE_uri9
    #define	RETURN_TYPE_uri9 TurtleParser_uri_return

    pANTLR3_BASE_TREE string_literal6_tree;
    pANTLR3_BASE_TREE IDENT7_tree;
    pANTLR3_BASE_TREE char_literal8_tree;

    /* Initialize rule variables
     */
    namespace_declaration_StartIndex = INDEX();


    root_0 = NULL;

    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(4)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    string_literal6       = NULL;
    IDENT7       = NULL;
    char_literal8       = NULL;
    uri9.tree = NULL;

    retval.start = LT(1); retval.stop = retval.start;

    string_literal6_tree   = NULL;
    IDENT7_tree   = NULL;
    char_literal8_tree   = NULL;


    retval.tree  = NULL;
    {
        // Turtle.g:34:2: ( '@prefix' ( IDENT )? ':' uri[collector] )
        // Turtle.g:35:2: '@prefix' ( IDENT )? ':' uri[collector]
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

            string_literal6 = (pANTLR3_COMMON_TOKEN) MATCHT(AT_PREFIX, &FOLLOW_AT_PREFIX_in_namespace_declaration129); 
            if  (HASEXCEPTION())
            {
                goto rulenamespace_declarationEx;
            }

            string_literal6_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, string_literal6));
            ADAPTOR->addChild(ADAPTOR, root_0, string_literal6_tree);


            // Turtle.g:35:12: ( IDENT )?
            {
                int alt3=2;
                switch ( LA(1) ) 
                {
                    case IDENT:
                    	{
                    		alt3=1;
                    	}
                        break;
                }

                switch (alt3) 
                {
            	case 1:
            	    // Turtle.g:35:12: IDENT
            	    {
            	        IDENT7 = (pANTLR3_COMMON_TOKEN) MATCHT(IDENT, &FOLLOW_IDENT_in_namespace_declaration131); 
            	        if  (HASEXCEPTION())
            	        {
            	            goto rulenamespace_declarationEx;
            	        }

            	        IDENT7_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, IDENT7));
            	        ADAPTOR->addChild(ADAPTOR, root_0, IDENT7_tree);


            	    }
            	    break;

                }
            }
            char_literal8 = (pANTLR3_COMMON_TOKEN) MATCHT(9, &FOLLOW_9_in_namespace_declaration134); 
            if  (HASEXCEPTION())
            {
                goto rulenamespace_declarationEx;
            }

            char_literal8_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, char_literal8));
            ADAPTOR->addChild(ADAPTOR, root_0, char_literal8_tree);

            FOLLOWPUSH(FOLLOW_uri_in_namespace_declaration136);
            uri9=uri(ctx, collector);

            FOLLOWPOP();
            if  (HASEXCEPTION())
            {
                goto rulenamespace_declarationEx;
            }

            ADAPTOR->addChild(ADAPTOR, root_0, uri9.tree);
            {

                		VALUE rbPrefix = rb_str_new2( (IDENT7->getText(IDENT7))->chars );
                		VALUE rbFull = uri9.ruby_uri;

                		VALUE document = COLLECTOR_DOCUMENT;
                		VALUE rbNamespaces = rb_funcall( document, rb_intern("namespaces"), 0 );
                		rb_hash_aset( rbNamespaces, rbPrefix, rbFull );
                	
            }

        }

    }
    

    // This is where rules clean up and exit
    //
    goto rulenamespace_declarationEx; /* Prevent compiler warnings */
    rulenamespace_declarationEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end namespace_declaration */

/** 
 * $ANTLR start base_declaration
 * Turtle.g:46:1: base_declaration[VALUE collector] : '@base' uri[collector] ;
 */
static TurtleParser_base_declaration_return
base_declaration(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_base_declaration_return retval;
    ANTLR3_UINT32 base_declaration_StartIndex;
    pANTLR3_BASE_TREE root_0;

    pANTLR3_COMMON_TOKEN    string_literal10;
    TurtleParser_uri_return uri11;
    #undef	RETURN_TYPE_uri11
    #define	RETURN_TYPE_uri11 TurtleParser_uri_return

    pANTLR3_BASE_TREE string_literal10_tree;

    /* Initialize rule variables
     */
    base_declaration_StartIndex = INDEX();


    root_0 = NULL;

    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(5)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    string_literal10       = NULL;
    uri11.tree = NULL;

    retval.start = LT(1); retval.stop = retval.start;

    string_literal10_tree   = NULL;


    retval.tree  = NULL;
    {
        // Turtle.g:47:2: ( '@base' uri[collector] )
        // Turtle.g:48:2: '@base' uri[collector]
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

            string_literal10 = (pANTLR3_COMMON_TOKEN) MATCHT(10, &FOLLOW_10_in_base_declaration153); 
            if  (HASEXCEPTION())
            {
                goto rulebase_declarationEx;
            }

            string_literal10_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, string_literal10));
            ADAPTOR->addChild(ADAPTOR, root_0, string_literal10_tree);

            FOLLOWPUSH(FOLLOW_uri_in_base_declaration155);
            uri11=uri(ctx, collector);

            FOLLOWPOP();
            if  (HASEXCEPTION())
            {
                goto rulebase_declarationEx;
            }

            ADAPTOR->addChild(ADAPTOR, root_0, uri11.tree);
            {

                		VALUE rbDocument = COLLECTOR_DOCUMENT;
                		VALUE existing_base = rb_funcall( rbDocument, rb_intern("base"), 0 );
                		if( RTEST(existing_base) ) {
                			rb_raise( eBase, "A base has already been specified" );
                		}
                		else {
                			rb_funcall( rbDocument, rb_intern("base="), 1, uri11.ruby_uri );
                		}
                	
            }

        }

    }
    

    // This is where rules clean up and exit
    //
    goto rulebase_declarationEx; /* Prevent compiler warnings */
    rulebase_declarationEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end base_declaration */

/** 
 * $ANTLR start uri
 * Turtle.g:61:1: uri[VALUE collector] returns [VALUE ruby_uri] : URI ;
 */
static TurtleParser_uri_return
uri(pTurtleParser ctx, VALUE collector)
{   
    TurtleParser_uri_return retval;
    ANTLR3_UINT32 uri_StartIndex;
    pANTLR3_BASE_TREE root_0;

    pANTLR3_COMMON_TOKEN    URI12;

    pANTLR3_BASE_TREE URI12_tree;

    /* Initialize rule variables
     */
    uri_StartIndex = INDEX();


    root_0 = NULL;

     retval.ruby_uri= Qnil; 
    if ( (BACKTRACKING>0) && (HAVEPARSEDRULE(6)) )
    {
    	retval.start = 0;

        {
        }


        return retval; 
    }
    URI12       = NULL;
    retval.start = LT(1); retval.stop = retval.start;

    URI12_tree   = NULL;


    retval.tree  = NULL;
    {
        // Turtle.g:63:2: ( URI )
        // Turtle.g:63:4: URI
        {
            root_0 = (pANTLR3_BASE_TREE)(ADAPTOR->nilNode(ADAPTOR));

            URI12 = (pANTLR3_COMMON_TOKEN) MATCHT(URI, &FOLLOW_URI_in_uri180); 
            if  (HASEXCEPTION())
            {
                goto ruleuriEx;
            }

            URI12_tree = (pANTLR3_BASE_TREE)(ADAPTOR->create(ADAPTOR, URI12));
            ADAPTOR->addChild(ADAPTOR, root_0, URI12_tree);

            {

                		pANTLR3_STRING str = (URI12->getText(URI12)) /*(URI12->getText(URI12))->toUTF8((URI12->getText(URI12)))*/ ;
                		VALUE rb_strUri = rb_str_new2( str->chars );
                		retval.ruby_uri= rb_funcall( rb_path2class("URI"), rb_intern("parse"), 1, rb_strUri );

                		if( ! rb_funcall(retval.ruby_uri, rb_intern("absolute?"), 0) ) {
                			//  relative uri encountered
                			//  document must have a base
                			VALUE rbDocument = COLLECTOR_DOCUMENT;
                			VALUE rbBase = rb_funcall(rbDocument, rb_intern("base"), 0 );
                			if( rbBase == Qnil ) {
                				rb_raise( rb_eException, "Relative URI with no base" );
                			}
                			else {
                				retval.ruby_uri= rb_funcall( rbBase, rb_intern("+"), 1, retval.ruby_uri );
                			}

                		}

                	
            }

        }

    }
    

    // This is where rules clean up and exit
    //
    goto ruleuriEx; /* Prevent compiler warnings */
    ruleuriEx: ;
    retval.stop = LT(-1);

    	retval.stop = LT(-1);
    	retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->rulePostProcessing(ADAPTOR, root_0));
    	ADAPTOR->setTokenBoundaries(ADAPTOR, retval.tree, retval.start, retval.stop);

            if (HASEXCEPTION())
            {
                PREPORTERROR();
                PRECOVER();
                retval.tree = (pANTLR3_BASE_TREE)(ADAPTOR->errorNode(ADAPTOR, INPUT, retval.start, LT(-1), EXCEPTION));
            }


    return retval;
}
/* $ANTLR end uri */
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