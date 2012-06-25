grammar Turtle;

options {
  language     = C;
  output       = AST;
  memoize      = true;
  ASTLabelType = pANTLR3_BASE_TREE;
}

@header {
	#include <ruby.h>
}

@lexer::header {
	#include <ruby.h>
}

document[VALUE collector]
	:
	;
