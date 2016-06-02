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
/*Integer literal*/
INT_LIT      [0-9]+
DELIM		[;.]
KEYWORD		break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var
WS          [ \r\n\t]*
IDENTIFIER	[a-zA-Z][a-zA-Z_0-9]*
STRINGLIT	"\"".*"\""
 
%%
 
{WS}            { /* Skip blanks. */ }
{INT_LIT}        { sscanf(yytext, "%d", &yylval->value); return TOKEN_INT_LIT; }
 
{MULTIPLY}      { return TOKEN_MULTIPLY; }
{PLUS}          { return TOKEN_PLUS; }
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
{CLPAREN}		{ return TOKEN_CLPAREN; }
{CRPAREN}		{ return TOKEN_CRPAREN; }
{IDENTIFIER}	{ return TOKEN_IDENTIFIER;	}
{STRINGLIT}		{sscanf(yytext, "%s", &yylaval->value);  return TOKEN_STRING_LIT;	}
.               {/* skip everything else*/  }
 
%%
 
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}
