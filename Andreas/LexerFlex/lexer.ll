%{
#include <iostream>
#define YY_DECL extern "C" int yylex()
#include "Parser.h"

%}
%option noyywrap nounput batch noinput

id			[a-zA-Z][a-zA-Z_0-9]*
int			[0-9]+
ws			[ \t\n\r]*
delim		[;,]
keyword		break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var

%%

{ws}								;
{keyword}							{ /* std::cout << "keyword " << yytext << std::endl; */
									 yylval.str = yytext;
									 /*std::cout << "yylval value " << yylval.str << std::endl; */ 
									 return TOKEN_KEYWORD; 
									}
{id}								{yylval.str = yytext;return TOKEN_IDENTIFIER;}
{int}								{std::cout << "Found integer Number " << yytext << std::endl;}
{int}.{int}* 						{std::cout << "Found Float " << yytext << std::endl;}
";"									{/*std::cout << "Lexer semicolon " << yylval.str =  yytext << std::endl*/ yylval.str = yytext ; return TOKEN_SEMICOLON;}
"("									{return TOKEN_LPAREN;}
")"									{return TOKEN_RPAREN;}		
"{"									{return TOKEN_LCPAREN;}
"}"									{return TOKEN_RCPAREN;}
":="								{/*TOKEN_ASSIGNMENT needs to be defined in parser.yy for now do nothing */ }
"="									{}
"\""+{id}*+"\""						{return TOKEN_STRING_LIT;}
"+"									{}
"//".*								{}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]	{}
%%


