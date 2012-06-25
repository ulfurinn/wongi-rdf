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

	#define COLLECTOR_DOCUMENT rb_funcall( collector, rb_intern("document"), 0 )
	#define MATCH(string) printf("matched " string "\n");

}

@lexer::header {
	#include <ruby.h>
}

document[VALUE collector] : statement[collector] * ;

statement[VALUE collector] : directive[collector] DOT ;

directive[VALUE collector]
	: namespace_declaration[collector]
	| base_declaration[collector]
	;

namespace_declaration[VALUE collector]
	:
	'@prefix' IDENT? ':' uri[collector]
	{
		VALUE rbPrefix = rb_str_new2( $IDENT.text->chars );
		VALUE rbFull = $uri.ruby_uri;

		VALUE document = COLLECTOR_DOCUMENT;
		VALUE rbNamespaces = rb_funcall( document, rb_intern("namespaces"), 0 );
		rb_hash_aset( rbNamespaces, rbPrefix, rbFull );
	}
	;

base_declaration[VALUE collector]
	:
	'@base' uri[collector]
	{
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		rb_funcall( rbDocument, rb_intern("base="), 1, $uri.ruby_uri );
	}
	;

uri[VALUE collector] returns [VALUE ruby_uri]
	@init{ $ruby_uri = Qnil; }
	: URI
	{
		pANTLR3_STRING str = $URI.text /*$URI.text->toUTF8($URI.text)*/ ;
		VALUE rb_strUri = rb_str_new2( str->chars );
		$ruby_uri = rb_funcall( rb_path2class("URI"), rb_intern("parse"), 1, rb_strUri );

		if( ! rb_funcall($ruby_uri, rb_intern("absolute?"), 0) ) {
			//  relative uri encountered
			//  document must have a base
			VALUE rbDocument = COLLECTOR_DOCUMENT;
			VALUE rbBase = rb_funcall(rbDocument, rb_intern("base"), 0 );
			if( rbBase == Qnil ) {
				rb_raise( rb_eException, "Relative URI with no base" );
			}
			else {
				$ruby_uri = rb_funcall( rbBase, rb_intern("+"), 1, $ruby_uri );
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
		sub = text->subString(text, 1, text->len-1 ); //  all but first and last
		SETTEXT( sub );
		//printf("extracted URI = \%s\n", GETTEXT()->chars );
	}
	;

AT_PREFIX : '@prefix' ;
DOT : '.' ;

IDENT
	:
	(
    	'a'..'z'
    	| 'A'..'Z'
  	)
  	(
    	'A'..'Z'
    	| '_'
    	| 'a'..'z'
    	| '-'
    	| '0'..'9'
  	)*
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
