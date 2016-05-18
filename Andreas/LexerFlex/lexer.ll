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
{keyword}		{std::cout << "Found Keyword " << yytext << std::endl;}
{id}			{std::cout << "Found identifier " << yytext << std::endl;}
{int}			{std::cout << "Found integer Number " << yytext << std::endl;}
{int}.{int}* 		{std::cout << "Found Float " << yytext << std::endl;}
{delim}			{std::cout << "Found Delimiter " << yytext << std::endl;}
"("			{std::cout << "Found left parenthesis " << yytext << std::endl;}
")"			{std::cout << "Found right parenthesis " << yytext << std::endl;}		
"{"			{std::cout << "Found left curly bracket " << yytext << std::endl;}
"}"			{std::cout << "Found right curly bracket " << yytext << std::endl;}
":="			{std::cout << "Found Assignment operator " << yytext << std::endl;}
"="			{std::cout << "Found equality sign " << yytext << std::endl;}
"\""+{id}*"\""		{std::cout << "Found String " << yytext << std::endl;}
"+"			{std::cout << "Found Operator " << yytext << std::endl;}
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
