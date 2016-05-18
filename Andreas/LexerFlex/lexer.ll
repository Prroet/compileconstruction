%{
#include <iostream>


%}
%option noyywrap nounput batch noinput

id			[a-zA-Z][a-zA-Z_0-9]*
int			[0-9]+
ws			[ \t\n]
delim		[;,]

%%

{ws}	;
{id}	{std::cout << "Found identifier or keyword " << yytext << std::endl;}
{int}	{std::cout << "Found integer Number " << yytext << std::endl;}
{int}.{int}* {std::cout << "Found Float " << yytext << std::endl;}


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
