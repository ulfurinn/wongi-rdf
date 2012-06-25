#include <ruby.h>
#include "extern.h"
#include "parser.h"
#include "collector.h"

VALUE mWongi;
VALUE mRDF;

VALUE cParser;
VALUE cCollector;

VALUE eBase;

ID rbsym_ivar_document;
ID rbsym_ivar_mapping;

void define_prelude() {
	mWongi = rb_define_module( "Wongi" );
	mRDF = rb_define_module_under( mWongi, "RDF" );
}

void Init_wongi_turtle() {

	define_prelude();

	define_parser();
	define_collector();

	eBase = rb_define_class_under( mRDF, "BaseException", rb_eException );

}
