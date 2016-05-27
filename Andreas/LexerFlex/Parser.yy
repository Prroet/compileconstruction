%{
	#include <iostream>
	#include <stdio.h>
	#define YYPARSE_PARAM scanner
	#define YYLEX_PARAM scanner
	extern "C" int yylex();
	extern "C" FILE *yyin;	
	void yyerror(const char* s);	
%}

%output		"Parser.cpp"
%defines	"Parser.h"

%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY

%union {
	int num;
	char* str;
}

%token<str> TOKEN_LPAREN
%token<str> TOKEN_RPAREN
%token<str> TOKEN_LCPAREN
%token<str> TOKEN_RCPAREN
%token<str> TOKEN_SEMICOLON
%token<str> TOKEN_KEYWORD
%token<str> TOKEN_IDENTIFIER
%token<str> TOKEN_STRING_LIT

%%

A:	P PPrime;
P:	TOKEN_KEYWORD I TOKEN_SEMICOLON;
PPrime:	F | M F;
I:	TOKEN_IDENTIFIER;
M:	TOKEN_KEYWORD S TOKEN_SEMICOLON;
S:	TOKEN_STRING_LIT;
F:	TOKEN_KEYWORD I TOKEN_LPAREN TOKEN_RPAREN B;
B:	TOKEN_LCPAREN BPrime TOKEN_RCPAREN
BPrime:	;

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
		FILE* myFile = fopen(args[1], "r");
		if(!myFile)
		{
			std::cout << "Coldn't open File!" << std::endl;
			return -1;
		}
		else
		{
                	yyin = myFile;
                	do {
				yyparse();
			}while(!feof(yyin));
		}
        }
}
	
void yyerror(char const* s)
{
	std::cout << "Parsing error! Message: " << s << std::endl;
	// should halt here
}
