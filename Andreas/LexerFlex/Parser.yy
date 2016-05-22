%{
	#include <iostream>
	int yylex(YYSTYPE* lvalp, YYLTYPE* llocp, yyscan_t scanner);
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

%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LCPAREN
%token TOKEN_RCPAREN
%token TOKEN_SEMICOLON
%token TOKEN_KEYWORD
%token TOKEN_IDENTIFIER
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
