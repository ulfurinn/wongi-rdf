#include <ruby.h>
#include "extern.h"
#include "parser.h"

VALUE mWongi;
VALUE mRDF;

VALUE cParser;
VALUE cCollector;

ID rbsym_ivar_document;
ID rbsym_ivar_mapping;

void define_prelude() {
	mWongi = rb_define_module( "Wongi" );
	mRDF = rb_define_module_under( mWongi, "RDF" );
}

void Init_wongi_turtle() {

	define_prelude();

	define_parser();
	cCollector = rb_path2class("Wongi::RDF::Collector");

}
