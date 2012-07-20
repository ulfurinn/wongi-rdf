#include <ruby.h>
#include "parser.h"

VALUE mWongi;
VALUE mRDF;

VALUE cParser;
VALUE cURI;
VALUE cCollector;
VALUE cStatement;

ID symResource;
ID symDocument;
ID symRegister;
ID symBaseEQ;
ID symLSHIFT;
ID symCommonEXCL;
ID symSplit;
ID symLookup;
ID symFragment;
ID symPLUS;
ID symEscape;
ID symImportBlank;
ID symBlank;
ID symParse;
ID symAbsoluteQ;
ID symBase;

void define_prelude() {
	mWongi = rb_define_module( "Wongi" );
	mRDF = rb_define_module_under( mWongi, "RDF" );
}

void Init_wongi_turtle() {

	define_prelude();

	define_parser();

	cURI = rb_path2class("URI");

	symResource = rb_intern( "resource" );
	symDocument = rb_intern( "document" );
	symRegister = rb_intern( "register" );
	symBaseEQ = rb_intern( "base=" );
	symLSHIFT = rb_intern( "<<" );
	symCommonEXCL = rb_intern( "common!" );
	symSplit = rb_intern( "split" );
	symLookup = rb_intern( "lookup" );
	symFragment = rb_intern( "fragment" );
	symPLUS = rb_intern( "+" );
	symEscape = rb_intern( "escape" );
	symImportBlank = rb_intern( "import_blank" );
	symBlank = rb_intern( "blank" );
	symParse = rb_intern( "parse" );
	symAbsoluteQ = rb_intern( "absolute?" );
	symBase = rb_intern( "base" );

	cCollector = rb_path2class("Wongi::RDF::Collector");
	cStatement = rb_path2class( "Wongi::RDF::Statement" );

}
