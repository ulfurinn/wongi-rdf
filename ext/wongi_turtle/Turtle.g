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

statement[VALUE collector] : ( directive[collector] | triples[collector] ) '.' ;

directive[VALUE collector]
	: namespace_declaration[collector]
	| base_declaration[collector]
	;

namespace_declaration[VALUE collector]
	:
	'@prefix' IDENT ':' uri[collector]
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

triples[VALUE collector]
	:
	subject[collector] predicate[collector] object[collector]
	{
		VALUE argv[] = { $subject.node, $predicate.node, $object.node };
	    VALUE statement = rb_class_new_instance( 3, argv, rb_path2class("Wongi::RDF::Statement") );
	    VALUE rbDocument = COLLECTOR_DOCUMENT;
	    rb_funcall( rbDocument, rb_intern("<<"), 1, statement );
	}
	;

subject[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	;

predicate[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	;

object[VALUE collector] returns [VALUE node]
	:
	resource[collector] { $node = $resource.node; }
	;

resource[ VALUE collector ] returns [VALUE node]
	@init{ VALUE rbDocument = COLLECTOR_DOCUMENT; $node = Qnil; }
	:
	qname[collector] { $node = rb_funcall( rbDocument, rb_intern("resource"), 1, $qname.ruby_uri ); }
	| uri[collector] { $node = rb_funcall( rbDocument, rb_intern("resource"), 1, $uri.ruby_uri ); }
	;

qname[VALUE collector] returns [VALUE ruby_uri]
	@init { $ruby_uri = Qnil; }
	:
	prefix=IDENT ':' local=IDENT
	{
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		VALUE prefixURI = rb_funcall( rbDocument, rb_intern("lookup"), 1, rb_str_new2( $prefix.text->chars ) );
	    VALUE localStr = rb_str_new2( $local.text->chars );
	    
	    //  Ruby URI replaces the whole last segment when it ends with a #
	    //  but this screws up the entire namespacing.
	    //  To avoid this, we prepend # to the local part.
	    if( prefixURI == Qnil ) {
	        rb_raise( rb_eException, "Unknown prefix \%s", $prefix.text->chars );
	    }
	    VALUE hash_fragment = rb_funcall( prefixURI, rb_intern("fragment"), 0 );
	    if( hash_fragment != Qnil ) {
	      localStr = rb_funcall( rb_str_new2("#"), rb_intern("+"), 1, localStr );
	    } 
	    
	    $ruby_uri = rb_funcall( prefixURI, rb_intern("+"), 1, localStr );
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
