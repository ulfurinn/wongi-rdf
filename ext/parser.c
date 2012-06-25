#include <ruby.h>
#include <stdlib.h>
#include "extern.h"
#include "parser.h"
#include "TurtleParser.h"
#include "TurtleLexer.h"


typedef struct _ParserComplect ParserComplect;
typedef struct _ParserComplect * pParserComplect;

struct _ParserComplect {
    pANTLR3_INPUT_STREAM stream;
    #ifdef	_TurtleLexer_H
    pTurtleLexer lexer;
    #endif
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pTurtleParser parser;
};

void reset_complect( pParserComplect complect ) {
    complect->stream = NULL;
    #ifdef	_TurtleLexer_H
    complect->lexer = NULL;
    #endif
    complect->tokens = NULL;
    complect->parser = NULL;
}

int open_file_stream( pParserComplect complect, pANTLR3_UINT8 file ) {

    complect->stream = antlr3AsciiFileStreamNew( file );

    if ( complect->stream == NULL ) {
        fprintf( stderr, "returned null stream\n" );
        return 0;
    }
    else if ( complect->stream == (pANTLR3_INPUT_STREAM) ANTLR3_ERR_NOMEM ) {
        fprintf( stderr, "no memory\n" );
        return 0;
    }
    else if ( complect->stream == (pANTLR3_INPUT_STREAM) ANTLR3_ERR_NOFILE ) {
        fprintf( stderr, "file not found\n" );
        return 0;
    }
    return 1;
}

int fill_parser_complect( pParserComplect complect, pANTLR3_UINT8 file ) {

    if ( !open_file_stream( complect, file ) ) {
        complect->stream = NULL;
        return 0;
    }

    complect->lexer = TurtleLexerNew( complect->stream );
    if ( complect->lexer == NULL ) {
        fprintf( stderr, "failed to alloc lexer\n" );
        return 0;
    }
    complect->tokens = antlr3CommonTokenStreamSourceNew (ANTLR3_SIZE_HINT,
        TOKENSOURCE(complect->lexer));

    complect->parser = TurtleParserNew( complect->tokens );
    return 1;
}

void release_complect( pParserComplect complect ) {
    //printf("Releasing parser complect\n");
    if ( complect->parser != NULL ) {
        complect->parser->free( complect->parser );
        complect->parser = NULL;
    }
    if ( complect->tokens != NULL ) {
        complect->tokens->free( complect->tokens );
        complect->tokens = NULL;
    }
    #ifdef	_TurtleLexer_H
    if ( complect->lexer != NULL ) {
        complect->lexer->free( complect->lexer );
        complect->lexer = NULL;
    }
    #endif
    if ( complect->stream != NULL ) {
        complect->stream->close( complect->stream );
        complect->stream = NULL;
    }
}

void free_complect( pParserComplect complect ) {
    //  In case parsing was aborted by a Ruby exception, we must try releasing again
    release_complect( complect );
    free( complect );
}

VALUE turtle_parser_new( VALUE klass ) {
    VALUE inst;
    pParserComplect complect;
    inst = Data_Make_Struct( klass, ParserComplect, 0, free_complect, complect );
    reset_complect( complect );
    rb_obj_call_init( inst, 0, NULL );
    return inst;
}

VALUE turtle_parser_parse_file( int argc, VALUE * argv, VALUE self ) {
	VALUE source_file;
	VALUE working_document = Qnil;
    pParserComplect complect;
    pANTLR3_UINT8 file;
    int alloc;

    if ( argc == 0 || ( argc > 0 && NIL_P(argv[0]) ) ) {
        rb_raise( rb_eArgError, "file name required" );
    }
    source_file = argv[ 0 ];

    if( argc > 1 )
      working_document = argv[ 1 ];

  if ( NIL_P(working_document) ) {
    working_document = rb_class_new_instance( 0, NULL, rb_path2class( "Wongi::RDF::Document" ) );
}

Data_Get_Struct( self, ParserComplect, complect );
file = (pANTLR3_UINT8) StringValueCStr( source_file );
alloc = fill_parser_complect( complect, file );

if ( alloc ) {
    VALUE argv[ ] = { working_document };
    VALUE collector = rb_class_new_instance( 1, argv, cCollector );
    complect->parser->document( complect->parser, collector );
}

release_complect( complect );


return working_document;
}

void define_parser() {
	cParser = rb_define_class_under( mRDF, "Parser", rb_cObject );
	rb_define_singleton_method( cParser, "new", &turtle_parser_new, 0 );
	rb_define_method( cParser, "parse_file", &turtle_parser_parse_file, -1 );
}
