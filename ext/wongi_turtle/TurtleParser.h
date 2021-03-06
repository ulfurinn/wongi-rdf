/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : ext/wongi_turtle/Turtle.g
 *     -                            On : 2012-07-20 14:10:13
 *     -                for the parser : TurtleParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
TurtleParser

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
 * a parser context typedef pTurtleParser, which is returned from a call to TurtleParserNew().
 *
 * The methods in pTurtleParser are  as follows:
 *
 *  - 
 TurtleParser_document_return
      pTurtleParser->document(pTurtleParser)
 *  - 
 TurtleParser_statement_return
      pTurtleParser->statement(pTurtleParser)
 *  - 
 TurtleParser_directive_return
      pTurtleParser->directive(pTurtleParser)
 *  - 
 TurtleParser_namespace_declaration_return
      pTurtleParser->namespace_declaration(pTurtleParser)
 *  - 
 TurtleParser_base_declaration_return
      pTurtleParser->base_declaration(pTurtleParser)
 *  - 
 TurtleParser_triples_return
      pTurtleParser->triples(pTurtleParser)
 *  - 
 TurtleParser_predicate_object_list_return
      pTurtleParser->predicate_object_list(pTurtleParser)
 *  - 
 TurtleParser_predicate_object_pair_return
      pTurtleParser->predicate_object_pair(pTurtleParser)
 *  - 
 TurtleParser_object_list_return
      pTurtleParser->object_list(pTurtleParser)
 *  - 
 TurtleParser_subject_return
      pTurtleParser->subject(pTurtleParser)
 *  - 
 TurtleParser_verb_return
      pTurtleParser->verb(pTurtleParser)
 *  - 
 TurtleParser_predicate_return
      pTurtleParser->predicate(pTurtleParser)
 *  - 
 TurtleParser_object_return
      pTurtleParser->object(pTurtleParser)
 *  - 
 TurtleParser_resource_return
      pTurtleParser->resource(pTurtleParser)
 *  - 
 TurtleParser_qname_return
      pTurtleParser->qname(pTurtleParser)
 *  - 
 TurtleParser_blank_return
      pTurtleParser->blank(pTurtleParser)
 *  - 
 TurtleParser_collection_return
      pTurtleParser->collection(pTurtleParser)
 *  - 
 TurtleParser_uri_return
      pTurtleParser->uri(pTurtleParser)
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

#ifndef	_TurtleParser_H
#define _TurtleParser_H
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
typedef struct TurtleParser_Ctx_struct TurtleParser, * pTurtleParser;




	#include <ruby.h>
	#include "extern.h"

	#define COLLECTOR_DOCUMENT   rb_funcall( collector, symDocument, 0 )
	#define MATCH(string)        printf("matched " string "\n");

	#define RDF_NS     "http://www.w3.org/1999/02/22-rdf-syntax-ns#"
	#define RDF_TYPE   RDF_NS   "type"
	#define RDF_FIRST  RDF_NS   "first"
	#define RDF_REST   RDF_NS   "rest"
	#define RDF_NIL    RDF_NS   "nil"



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
typedef struct TurtleParser_document_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_document_return;



typedef struct TurtleParser_statement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_statement_return;



typedef struct TurtleParser_directive_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_directive_return;



typedef struct TurtleParser_namespace_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_namespace_declaration_return;



typedef struct TurtleParser_base_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_base_declaration_return;



typedef struct TurtleParser_triples_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_triples_return;



typedef struct TurtleParser_predicate_object_list_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_predicate_object_list_return;



typedef struct TurtleParser_predicate_object_pair_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_predicate_object_pair_return;



typedef struct TurtleParser_object_list_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    TurtleParser_object_list_return;



typedef struct TurtleParser_subject_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_subject_return;



typedef struct TurtleParser_verb_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_verb_return;



typedef struct TurtleParser_predicate_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_predicate_return;



typedef struct TurtleParser_object_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_object_return;



typedef struct TurtleParser_resource_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_resource_return;



typedef struct TurtleParser_qname_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE ruby_uri;
}
    TurtleParser_qname_return;



typedef struct TurtleParser_blank_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_blank_return;



typedef struct TurtleParser_collection_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE node;
}
    TurtleParser_collection_return;



typedef struct TurtleParser_uri_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

    VALUE ruby_uri;
}
    TurtleParser_uri_return;




/** Context tracking structure for 
TurtleParser

 */
struct TurtleParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     TurtleParser_document_return
     (*document)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_statement_return
     (*statement)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_directive_return
     (*directive)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_namespace_declaration_return
     (*namespace_declaration)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_base_declaration_return
     (*base_declaration)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_triples_return
     (*triples)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_predicate_object_list_return
     (*predicate_object_list)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector, VALUE subject);

     TurtleParser_predicate_object_pair_return
     (*predicate_object_pair)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector, VALUE subject);

     TurtleParser_object_list_return
     (*object_list)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector, VALUE subject, VALUE predicate);

     TurtleParser_subject_return
     (*subject)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_verb_return
     (*verb)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_predicate_return
     (*predicate)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_object_return
     (*object)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_resource_return
     (*resource)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_qname_return
     (*qname)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_blank_return
     (*blank)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_collection_return
     (*collection)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);

     TurtleParser_uri_return
     (*uri)	(struct TurtleParser_Ctx_struct * ctx, VALUE collector);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct TurtleParser_Ctx_struct * ctx);
    void	    (*free)   (struct TurtleParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pTurtleParser TurtleParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pTurtleParser TurtleParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
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
#define T__10      10
#define T__11      11
#define T__12      12
#define T__13      13
#define T__14      14
#define T__15      15
#define T__16      16
#define T__17      17
#define T__18      18
#define T__19      19
#define BLANK      4
#define IDENT      5
#define PREFIX      6
#define QNAME      7
#define URI      8
#define WS      9
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for TurtleParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
