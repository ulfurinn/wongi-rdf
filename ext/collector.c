#include <ruby.h>
#include "extern.h"
#include "collector.h"

void init_collector_symbols() {
    rbsym_ivar_document = rb_intern("@document");
    rbsym_ivar_mapping = rb_intern("@mapping");
}

VALUE collector_initialize( VALUE self, VALUE document ) {
    rb_ivar_set( self, rbsym_ivar_document, document );
    rb_ivar_set( self, rbsym_ivar_mapping, rb_hash_new() );
    return self;
}

VALUE collector_lookup( VALUE self, VALUE name ) {
    VALUE hash = rb_ivar_get( self, rbsym_ivar_mapping );
    VALUE mapping = rb_hash_aref( hash, name );
    if( NIL_P(mapping) ) {
        VALUE document = rb_ivar_get( self, rbsym_ivar_document );
        mapping = rb_hash_aset( hash, name, rb_funcall( document, rb_intern("new_blank"), 0 ) );
    }
    return mapping;
}


void define_collector() {
	
	init_collector_symbols();

	cCollector = rb_define_class_under( mRDF, "Collector", rb_cObject );
    rb_define_method( cCollector, "initialize", &collector_initialize, 1 );
    rb_define_method( cCollector, "lookup", &collector_lookup, 1 );
    rb_attr( cCollector, rb_intern("document"), 1, 0, 0 );
}
