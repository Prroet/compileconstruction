%{
	#include <iostream>
	#define YYPARSE_PARAM scanner
	#define YYLEX_PARAM scanner
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror(char const*);
%}

%output		"Parser.cpp"
%defines	"Parser.h"

%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY

%union {
	int num;
	char* str;
}

%token<str> TOKEN_LPAREN
%token<str> TOKEN_RPAREN
%token<str> TOKEN_LCPAREN
%token<str> TOKEN_RCPAREN
%token<str> TOKEN_SEMICOLON
%token<str> TOKEN_KEYWORD
%token<str> TOKEN_IDENTIFIER
%token<str> TOKEN_STRING_LIT

%%

A:	P PPrime;
P:	TOKEN_KEYWORD I TOKEN_SEMICOLON;
PPrime:	F | M F;
I:	TOKEN_IDENTIFIER;
M:	TOKEN_KEYWORD S TOKEN_SEMICOLON;
S:	TOKEN_STRING_LIT;
F:	TOKEN_KEYWORD I TOKEN_LPAREN TOKEN_RPAREN B;
B:	TOKEN_LCPAREN BPrime TOKEN_RCPAREN
BPrime:	;
