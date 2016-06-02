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
	char* keyword;
	char* stringLiteral;
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
%token <identifier> TOKEN_IDENTIFIER
%token <keyword> TOKEN_KEYWORD
%token <stringLiteral> TOKEN_STRING_LIT
%token <value> TOKEN_NUMBER
%token <value> TOKEN_INT_LIT

%type <node> expr
 
%%
/*
	set *expression to value of expr
	where does expression come from ??
*/
input  /*first alternative is empty */
    : expr { *expression = $1; }
    ;

expr
    : expr[L] TOKEN_PLUS expr[R] { $$ = createOperation( ePLUS, $L, $R ); }
    | expr[L] TOKEN_MULTIPLY expr[R] { $$ = createOperation( eMULTIPLY, $L, $R ); }
    | TOKEN_LPAREN expr[E] TOKEN_RPAREN { $$ = $E; }
    | TOKEN_NUMBER { $$ = createNumber($1); }
    ;
 
%%
