%{
	#include <iostream>
%}

%output		"Parser.cpp"
%defines	"Parser.h"

%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY

%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_PLUS
%token TOKEN_MULTIPLY

%%

input :
	%empty
	| input line
	; 

line :
	'\n'
	| 
