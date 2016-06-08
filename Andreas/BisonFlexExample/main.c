/*
 * main.c file
 */

#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"
 
#include <stdio.h>
 
int yyparse(SExpression **expression, yyscan_t scanner);
// extern "C" FILE *yyin;

 
SExpression *getAST(const char *filename)
{
    SExpression *expression;
    yyscan_t scanner;
    YY_BUFFER_STATE state;
 
    if (yylex_init(&scanner)) {
        // couldn't initialize
        return NULL;
    }
	FILE* inputFile=NULL;
	inputFile = yyget_in(scanner);
	inputFile = fopen(filename, "r");
	if(inputFile == NULL)
	{
		fprintf(stdout, "Error couldn't open file!\n");
		return NULL;
	}

	if(yyparse(&expression, scanner))
	{
		return NULL;
	}
	 	// state = yy_scan_string(expr, scanner);
	/*FILE* myFile = fopen(filename, "r");
	if(!myFile)
	{
		fprintf(stdout, "Couldn't open File! \n");
	}
	else
	{
		yyin = myFile;
	}
*/ 
    yy_delete_buffer(state, scanner);
 
    yylex_destroy(scanner);
 
    return expression;
}
 
int main(int argc, char* args[])
{
    SExpression *e = NULL;
 	if(argc != 2)
	{
		// printUsage();
		return -1;
	}
    e = getAST(args[1]);
   
    deleteExpression(e);
 
    return 0;
}
