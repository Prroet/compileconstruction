%{
#include <iostream>


%}
%option noyywrap nounput batch noinput

id			[a-zA-Z][a-zA-Z_0-9]*
int			[0-9]+
ws			[ \t\n]
delim		[;,]
keyword		break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var

%%

{ws}			;
{keyword}		{std::cout << "Found Keyword " << yytext << std::endl; return TOKEN_KEYWORD;}
{id}			{std::cout << "Found identifier " << yytext << std::endl;return TOKEN_IDENTIFIER;}
{int}			{std::cout << "Found integer Number " << yytext << std::endl;}
{int}.{int}* 		{std::cout << "Found Float " << yytext << std::endl;}
";"			{return TOKEN_SEMICOLON;}
"("			{std::cout << "Found left parenthesis " << yytext << std::endl; return TOKEN_LPAREN;}
")"			{std::cout << "Found right parenthesis " << yytext << std::endl;return TOKEN_RPAREN;}		
"{"			{std::cout << "Found left curly bracket " << yytext << std::endl;return TOKEN_LCPAREN;}
"}"			{std::cout << "Found right curly bracket " << yytext << std::endl;return TOKEN_RCPAREN;}
":="			{std::cout << "Found Assignment operator " << yytext << std::endl;}
"="			{std::cout << "Found equality sign " << yytext << std::endl;}
"\""+{id}*+"\""		{std::cout << "Found String " << yytext << std::endl;}
"+"			{std::cout << "Found Operator " << yytext << std::endl;}
"//".*			{std::cout << "Found comment " << yytext << std::endl;}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]	{std::cout << "Found Multilinecomment " << yytext << std::endl;}
%%

void printUsage()
{
	std::cout << "Usage: lexer gofile.go" << std::endl;
}

int main(int argc, char* args[])
{
	if(argc != 2)
		printUsage();
	else
	{
		yyin = fopen(args[1], "r");
		yylex();
	}
}
