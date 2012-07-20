grammar Turtle;

options {
  language     = C;
  output       = AST;
  memoize      = true;
  ASTLabelType = pANTLR3_BASE_TREE;
}

@header {

	#include <ruby.h>
	#include "extern.h"

	#define COLLECTOR_DOCUMENT   rb_funcall( collector, symDocument, 0 )
	#define MATCH(string)        printf("matched " string "\n");

	#define RDF_NS     "http://www.w3.org/1999/02/22-rdf-syntax-ns#"
	#define RDF_TYPE   RDF_NS   "type"
	#define RDF_FIRST  RDF_NS   "first"
	#define RDF_REST   RDF_NS   "rest"
	#define RDF_NIL    RDF_NS   "nil"

}

@lexer::header {
	#include <ruby.h>
}

document[VALUE collector] : statement[collector] * ;

statement[VALUE collector] : ( directive[collector] | triples[collector] ) '.' ;

directive[VALUE collector]
	: namespace_declaration[collector]
	| base_declaration[collector]
	;

namespace_declaration[VALUE collector]
	:
	'@prefix' PREFIX uri[collector]
	{
		VALUE rbPrefix = rb_str_new2( $PREFIX.text->chars );
		VALUE rbFull = $uri.ruby_uri;

		rb_funcall( collector, symRegister, 2, rbPrefix, rbFull );
	}
	;

base_declaration[VALUE collector]
	:
	'@base' uri[collector]
	{
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		rb_funcall( rbDocument, symBaseEQ, 1, $uri.ruby_uri );
	}
	;

triples[VALUE collector]
	:
	subject[collector] predicate_object_list[collector, $subject.node]
	;

predicate_object_list[VALUE collector, VALUE subject]
	:
	predicate_object_pair[collector, subject] ( ';' predicate_object_pair[collector, subject] )*
	;

predicate_object_pair[VALUE collector, VALUE subject]
	:
	verb[collector] object_list[collector, subject, $verb.node]
	;

object_list[VALUE collector, VALUE subject, VALUE predicate]
	@init { VALUE rbDocument = COLLECTOR_DOCUMENT; }
	:
	first=object[collector] {
		VALUE argv[] = { $subject, $predicate, $first.node };
		VALUE statement = rb_class_new_instance( 3, argv, cStatement );
		rb_funcall( rbDocument, symLSHIFT, 1, statement );
	}
	(',' subseq=object[collector] {
		VALUE argv[] = { $subject, $predicate, $subseq.node };
		VALUE statement = rb_class_new_instance( 3, argv, cStatement );
		rb_funcall( rbDocument, symLSHIFT, 1, statement );
	} )*
	;

subject[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	;

verb[VALUE collector] returns [VALUE node]
	@init { $node = Qnil; }
	:
	predicate[collector] { $node = $predicate.node; }
	|
	'a' {
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		rb_funcall( rbDocument, symCommonEXCL, 0 );
		$node = rb_funcall( rbDocument, symResource, 1, rb_str_new2(RDF_TYPE) );
	}
	;

predicate[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	;

object[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	|
	blank[collector] { $node =  $blank.node; }
	;

resource[ VALUE collector ] returns [VALUE node]
	@init{ VALUE rbDocument = COLLECTOR_DOCUMENT; $node = Qnil; }
	:
	qname[collector] { $node = rb_funcall( rbDocument, symResource, 1, $qname.ruby_uri ); }
	| uri[collector] { $node = rb_funcall( rbDocument, symResource, 1, $uri.ruby_uri ); }
	;

qname[VALUE collector] returns [VALUE ruby_uri]
	@init { $ruby_uri = Qnil; }
	:
	qn=QNAME
	{
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		VALUE qnStr = rb_str_new2( $qn.text->chars );
		VALUE split = rb_funcall( qnStr, symSplit, 1, rb_str_new2(":") );
		VALUE prefixURI = rb_funcall( collector, symLookup, 1, rb_ary_entry( split, 0 ) );
		VALUE localStr = rb_ary_entry( split, 1 );
		
		//  Ruby URI replaces the whole last segment when it ends with a #
		//  but this screws up the entire namespacing.
		//  To avoid this, we prepend # to the local part.
		if( prefixURI == Qnil ) {
			rb_raise( rb_eException, "Unknown prefix \%s", RSTRING_PTR( rb_ary_entry( split, 0 ) ) );
		}
		VALUE hash_fragment = rb_funcall( prefixURI, symFragment, 0 );
		if( hash_fragment != Qnil ) {
		  localStr = rb_funcall( rb_str_new2("#"), symPLUS, 1, localStr );
		} 
		
		$ruby_uri = rb_funcall( prefixURI, symPLUS, 1, rb_funcall( cURI, symEscape, 1, localStr ) );
	}
	;

blank[VALUE collector] returns [VALUE node]
	@init { $node = Qnil; }
	:
	BLANK {
		VALUE id = rb_str_new2( $BLANK.text->chars );
		$node = rb_funcall( $collector, symImportBlank, 1, id );
	}
	|
		{
			VALUE rbDocument = COLLECTOR_DOCUMENT;
			$blank.node = rb_funcall( rbDocument, symBlank, 1, Qnil );
		}
		'[' predicate_object_list[ collector, $blank.node ]? ']'
	|
		'(' collection[collector] ')'
		{
			$node = $collection.node;
		}
	;

collection[VALUE collector] returns [VALUE node]
	@init {
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		$node = Qnil;
	}
	:
		{
			rb_funcall( rbDocument, symCommonEXCL, 0 );
			$node = rb_funcall( rbDocument, symResource, 1, rb_str_new2(RDF_NIL) );
		}
	|
		object[collector]
		{
			$node = rb_funcall( rbDocument, symBlank, 1, Qnil );
			VALUE first = rb_funcall( rbDocument, symResource, 1, rb_str_new2(RDF_FIRST) );
			VALUE argv[] = { $node, first, $object.node };
			VALUE statement = rb_class_new_instance( 3, argv, cStatement );
			rb_funcall( rbDocument, symLSHIFT, 1, statement );
		}
		subseq=collection[collector]
		{
			VALUE rest = rb_funcall( rbDocument, symResource, 1, rb_str_new2(RDF_REST) );
			VALUE argv[] = { $node, rest, $subseq.node };
			VALUE statement = rb_class_new_instance( 3, argv, cStatement );
			rb_funcall( rbDocument, symLSHIFT, 1, statement );
		}
	;

uri[VALUE collector] returns [VALUE ruby_uri]
	@init{ $ruby_uri = Qnil; }
	: URI
	{
		pANTLR3_STRING str = $URI.text /*$URI.text->toUTF8($URI.text)*/ ;
		VALUE rb_strUri = rb_str_new2( str->chars );
		$ruby_uri = rb_funcall( cURI, symParse, 1, rb_funcall( cURI, symEscape, 1, rb_strUri ) );

		if( ! rb_funcall($ruby_uri, symAbsoluteQ, 0) ) {
			//  relative uri encountered
			//  document must have a base
			VALUE rbDocument = COLLECTOR_DOCUMENT;
			VALUE rbBase = rb_funcall(rbDocument, symBase, 0 );
			if( rbBase == Qnil ) {
				rb_raise( rb_eException, "Relative URI with no base" );
			}
			else {
				$ruby_uri = rb_funcall( rbBase, symPLUS, 1, $ruby_uri );
			}

		}

	}
	;

URI
	:
	'<' uri=~('>' )* '>'
	{
		pANTLR3_STRING text, sub;
		text = GETTEXT();
		sub = text->subString(text, 1, text->len-2 ); //  all but first and last; for some reason we need to use -2 in antlr 3.4.. investigate
		SETTEXT( sub );
		//printf("extracted URI = \%s\n", GETTEXT()->chars );
	}
	;

IDENT
	:
	(
		'a'..'z'
		| '_'
		| 'A'..'Z'
		| '\u00c0'..'\u00d6'
		| '\u00d8'..'\u00f6'
		| '\u00f8'..'\u02ff'
		| '\u0370'..'\u037d'
		| '\u037f'..'\u1fff'
		| '\u200c'..'\u200d'
		| '\u2070'..'\u218f'
		| '\u2c00'..'\u2fef'
		| '\u3001'..'\ud7ff'
		| '\uf900'..'\ufdcf'
		| '\ufdf0'..'\ufffd'
	)
	(
		'a'..'z'
		| '_'
		| 'A'..'Z'
		| '\u00c0'..'\u00d6'
		| '\u00d8'..'\u00f6'
		| '\u00f8'..'\u02ff'
		| '\u0370'..'\u037d'
		| '\u037f'..'\u1fff'
		| '\u200c'..'\u200d'
		| '\u2070'..'\u218f'
		| '\u2c00'..'\u2fef'
		| '\u3001'..'\ud7ff'
		| '\uf900'..'\ufdcf'
		| '\ufdf0'..'\ufffd'
		| '-'
		| '0'..'9'
		| '\u00b7'
		| '\u0300'..'\u036f'
		| '\u203f'..'\u2040'
	)*
	;

BLANK :
	'_:' ident=IDENT
	{
		SETTEXT( $ident->getText($ident) );
	}
	;

QNAME : IDENT ':' IDENT ;

PREFIX : ident=IDENT ':' 
	{
		SETTEXT( $ident->getText($ident) );
	}
	;


WS
	:
	(' '
	| '\t'
	| '\r'
	| '\n')+
	{
		$channel=HIDDEN;
	}
	;
