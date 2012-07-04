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

	#define COLLECTOR_DOCUMENT   rb_funcall( collector, rb_intern("document"), 0 )
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
	'@prefix' IDENT ':' uri[collector]
	{
		VALUE rbPrefix = rb_str_new2( $IDENT.text->chars );
		VALUE rbFull = $uri.ruby_uri;

		rb_funcall( collector, rb_intern("register"), 2, rbPrefix, rbFull );
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
		VALUE statement = rb_class_new_instance( 3, argv, rb_path2class("Wongi::RDF::Statement") );
		rb_funcall( rbDocument, rb_intern("<<"), 1, statement );
	}
	(',' subseq=object[collector] {
		VALUE argv[] = { $subject, $predicate, $subseq.node };
		VALUE statement = rb_class_new_instance( 3, argv, rb_path2class("Wongi::RDF::Statement") );
		rb_funcall( rbDocument, rb_intern("<<"), 1, statement );
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
		rb_funcall( rbDocument, rb_intern("common!"), 0 );
		$node = rb_funcall( rbDocument, rb_intern("resource"), 1, rb_str_new2(RDF_TYPE) );
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
	qname[collector] { $node = rb_funcall( rbDocument, rb_intern("resource"), 1, $qname.ruby_uri ); }
	| uri[collector] { $node = rb_funcall( rbDocument, rb_intern("resource"), 1, $uri.ruby_uri ); }
	;

qname[VALUE collector] returns [VALUE ruby_uri]
	@init { $ruby_uri = Qnil; }
	:
	prefix=IDENT ':' local=IDENT
	{
		VALUE rbDocument = COLLECTOR_DOCUMENT;
		VALUE prefixURI = rb_funcall( collector, rb_intern("lookup"), 1, rb_str_new2( $prefix.text->chars ) );
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

blank[VALUE collector] returns [VALUE node]
	@init { $node = Qnil; }
	:
	'_:' IDENT {
		VALUE id = rb_str_new2( $IDENT.text->chars );
		$node = rb_funcall( $collector, rb_intern("import_blank"), 1, id );
	}
	|
		{
			VALUE rbDocument = COLLECTOR_DOCUMENT;
			$blank.node = rb_funcall( rbDocument, rb_intern("blank"), 1, Qnil );
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
			rb_funcall( rbDocument, rb_intern("common!"), 0 );
			$node = rb_funcall( rbDocument, rb_intern("resource"), 1, rb_str_new2(RDF_NIL) );
		}
	|
		object[collector]
		{
			$node = rb_funcall( rbDocument, rb_intern("blank"), 1, Qnil );
			VALUE first = rb_funcall( rbDocument, rb_intern("resource"), 1, rb_str_new2(RDF_FIRST) );
			VALUE argv[] = { $node, first, $object.node };
			VALUE statement = rb_class_new_instance( 3, argv, rb_path2class("Wongi::RDF::Statement") );
			rb_funcall( rbDocument, rb_intern("<<"), 1, statement );
		}
		subseq=collection[collector]
		{
			VALUE rest = rb_funcall( rbDocument, rb_intern("resource"), 1, rb_str_new2(RDF_REST) );
			VALUE argv[] = { $node, rest, $subseq.node };
			VALUE statement = rb_class_new_instance( 3, argv, rb_path2class("Wongi::RDF::Statement") );
			rb_funcall( rbDocument, rb_intern("<<"), 1, statement );
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
		sub = text->subString(text, 1, text->len-2 ); //  all but first and last; for some reason we need to use -2 in antlr 3.4.. investigate
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
