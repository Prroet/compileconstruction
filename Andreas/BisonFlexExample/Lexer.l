%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
 
#include "Expression.h"
#include "Parser.h"

#include <stdio.h>
 
%}

%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge
 
LPAREN      "("
RPAREN      ")"
CLPAREN		"{"
CRPAREN		"}"
PLUS        "+"
MULTIPLY    "*"
ASSIGNMENT	"="|":="
NUM_LIT      [0-9]+
DELIM		[;.]
SEMICOLON	;
KEYWORD		break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var
WS          [ \r\n\t]*
IDENTIFIER	[a-zA-Z][a-zA-Z_0-9]*
STRINGLIT	"\"".*"\""
 
%%
 
{WS}            ;
{NUM_LIT}       { sscanf(yytext, "%d", &yylval->value); return TOKEN_NUM_LIT; }
{ASSIGNMENT}	{ sscanf(yytext, "%s", &yylval->operatorString);return TOKEN_ASSIGNMENT; }
{MULTIPLY}      { sscanf(yytext, "%s", &yylval->operatorString);return TOKEN_MULTIPLY; }
{PLUS}          { sscanf(yytext, "%s", &yylval->operatorString); return TOKEN_PLUS; }
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
{CLPAREN}		{ return TOKEN_CLPAREN; }
{CRPAREN}		{ return TOKEN_CRPAREN; }
{IDENTIFIER}	{  sscanf(yytext, "%s", &yylval->identifier); return TOKEN_IDENTIFIER;	}
{STRINGLIT}		{sscanf(yytext, "%s", &yylval->stringLiteral);  return TOKEN_STRING_LIT;}
{SEMICOLON}		{return TOKEN_SEMICOLON; }
 
%%
 
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}
