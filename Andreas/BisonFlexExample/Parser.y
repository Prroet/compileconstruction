%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */
 
#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"

int yyerror(SExpression **expression, yyscan_t scanner, const char *msg) {
    // Add error handling routine as needed
}
 
%}

%code requires {

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

}

%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { SExpression **expression }
%parse-param { yyscan_t scanner }

%union {
    int value;
	char* identifier;
    SExpression *node; // terminal!!!!!!
}
 
%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY
 
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_CLPAREN
%token TOKEN_CRPAREN
%token TOKEN_PLUS
%token TOKEN_MULTIPLY
%token TOKEN_IDENTIFIER
%token TOKEN_KEYWORD
%token TOKEN_STRING_LIT
%token <value> TOKEN_NUMBER

%type <node> expr
 
%%


/**
	This will make the first node for the tree
**/ 
input
    : expr { *expression = $1; }
    ;

expr
    : expr[L] TOKEN_PLUS expr[R] { $$ = createOperation( ePLUS, $L, $R ); }
    | expr[L] TOKEN_MULTIPLY expr[R] { $$ = createOperation( eMULTIPLY, $L, $R ); }
    | TOKEN_LPAREN expr[E] TOKEN_RPAREN { $$ = $E; }
    | TOKEN_NUMBER { $$ = createNumber($1); }
    ;
 
%%
