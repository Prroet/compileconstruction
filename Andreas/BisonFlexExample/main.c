/*
 * main.c file
 */

#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"
 
#include <stdio.h>

int yylex(YYSTYPE * lvalp, yyscan_t scanner); 
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
	inputFile = fopen(filename, "r");
	if(inputFile == NULL)
	{
		fprintf(stdout, "Error couldn't open file!\n");
		return NULL;
	}
	yyset_in(inputFile,scanner);		
	// &expression instead NULL
	if(yyparse(NULL, scanner))
	{
		return NULL;
	}
	 	// state = yy_scan_string(expr, scanner);	
 
//     yy_delete_buffer(state, scanner);
 
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
	getAST(args[1]);
	// e = getAST(args[1]);

    deleteExpression(e);

    return 0;
}
