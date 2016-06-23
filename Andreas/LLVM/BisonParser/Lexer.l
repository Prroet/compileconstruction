%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */

#include "AbstractNode.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
#include "Parser.h"

#include <stdio.h>
 
%}

%option outfile="Lexer.cpp" header-file="Lexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge
 
LPAREN      "("
RPAREN      ")"
CLPAREN		"{"
CRPAREN		"}"
PLUS        "+"
MULTIPLY    "*"
ASSIGNMENT	"="
DECLARE_ASSIGN ":="
NUM_LIT      [0-9]+
SEMICOLON	";"

KEYWORD		break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var

WS          [ \r\n\t]*
IDENTIFIER	[a-zA-Z][a-zA-Z_0-9]*
STRINGLIT	"\"".*"\""
COMMENT		"//".*
MULTICOMMENT	[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
DEFAULT		.
 
%%

{WS}            { }
"func"			{return TOKEN_KEYWORD_FUNC;}
"package"		{return TOKEN_KEYWORD_PACKAGE;}
"import"		{return TOKEN_KEYWORD_IMPORT;}

{IDENTIFIER}    { 
					yylval->identifier=yytext; 
					return TOKEN_IDENTIFIER;  
				}
{NUM_LIT}       {
					//fprintf(stdout, "NUM_LIT %s\n", yytext); 
					sscanf(yytext, "%d", &yylval->value); 
					return TOKEN_NUM_LIT; 
				}
{DECLARE_ASSIGN} {
					yylval->operatorString=yytext;
					return TOKEN_DECLARE_ASSIGN;
				 }

{ASSIGNMENT}    { 
					yylval->operatorString=yytext; 
					return TOKEN_ASSIGNMENT; 
				}
{MULTIPLY}      { 
					/*yylval->operatorString=yytext ;
					return TOKEN_MULTIPLY;  */
				}
{PLUS}          { 
					yylval->operatorString=yytext ; 
					return TOKEN_PLUS; 
				}
{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}        { return TOKEN_RPAREN; }
{CLPAREN}       { return TOKEN_CLPAREN; }
{CRPAREN}       { return TOKEN_CRPAREN; }
{STRINGLIT}     {
					yylval->stringLiteral=yytext;  
					return TOKEN_STRING_LIT;
				}
{SEMICOLON}     { return TOKEN_SEMICOLON; }
{COMMENT}		{}
{MULTICOMMENT}	{}
{DEFAULT}       { fprintf(stdout, "Unknown Token!!!\n");}

%%
 
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}
