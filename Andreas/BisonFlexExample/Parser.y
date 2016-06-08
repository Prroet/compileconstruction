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
	fprintf(stdout, "Error Parsing! %s\n", msg);
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
	char* operatorString;
	SExpression *node; // terminal!!!!!!
}
 
%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY

%token TOKEN_SEMICOLON 
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_CLPAREN
%token TOKEN_CRPAREN
%token TOKEN_PLUS 
%token TOKEN_MULTIPLY
%token TOKEN_ASSIGNMENT
%token TOKEN_EOF
%token <identifier> TOKEN_IDENTIFIER
%token <keyword> TOKEN_KEYWORD
%token <stringLiteral> TOKEN_STRING_LIT
%token <value> TOKEN_NUMBER
%token <value> TOKEN_NUM_LIT

%type <node> expr A P PPrime I M S F B BPrime N L 
 
%%
/*
	set *expression to value of expr
*/

input  /*first alternative is empty */
    : expr {fprintf(stdout, "Hello from Input Production!! \n");  }
    ;

expr
    : A;

A: 	P PPrime {/* Do sth with the tokens */};
P:	TOKEN_KEYWORD I TOKEN_SEMICOLON{/**/};
PPrime: F | M F {};
I:	TOKEN_IDENTIFIER {};
M: TOKEN_KEYWORD S  TOKEN_SEMICOLON{/**/};
S: TOKEN_STRING_LIT {/**/};
F: TOKEN_KEYWORD I TOKEN_LPAREN TOKEN_RPAREN B {/**/};
B: TOKEN_CLPAREN BPrime TOKEN_CRPAREN {/**/};
BPrime: {} | N BPrime {};
N: I TOKEN_ASSIGNMENT L  TOKEN_SEMICOLON{};
L: L TOKEN_PLUS L | I | TOKEN_NUM_LIT {/* $$ = createN( )*/ };

%%
