/*
 * main.c file
 */

//#include "Expression.h"
#include "AbstractNode.h"
#include "Parser.h"
#include "Lexer.h"
 
#include <stdio.h>

int yylex(YYSTYPE * lvalp, yyscan_t scanner); 
int yyparse(AbstractNode **expression, yyscan_t scanner);

// extern "C" FILE *yyin;


AbstractNode *getAST(const char *filename)
{
    AbstractNode *abstractNode=NULL;
    yyscan_t scanner;
 
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

	if(yyparse(&abstractNode, scanner))
	{
		return NULL;
	}
//	fprintf(stdout, "Hello after Parsing!\n");
 
    yylex_destroy(scanner);
	return abstractNode;
}
 
int main(int argc, char* args[])
{
    AbstractNode *abstractNode = NULL;
 	if(argc != 2)
	{
		// printUsage();
		return -1;
	}	 	
	abstractNode = getAST(args[1]);
	if(abstractNode== NULL)
	{
		fprintf(stdout, "Error Tree is empty!!\n");
		return -1;
	}
	abstractNode->printNode(0); 
//	delete(abstractNode);
    return 0;
}
