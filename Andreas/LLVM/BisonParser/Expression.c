/*
 * Expression.c
 * Implementation of functions used to build the syntax tree.
 */

#include "Expression.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */
static SExpression *allocateExpression(EOperationType type)
{
    SExpression *b = (SExpression *)malloc(sizeof(SExpression));

    if (b == NULL)
        return NULL;
	b->type = type;
	if(type != eNUMLIT)
		b->stringValue = NULL;
	else
		b->numlit=0;
    b->left = NULL;
    b->right = NULL;

    return b;
}

SExpression *createIdentifier(char* bisonString)
{
	SExpression *b = allocateExpression(eIDENTIFIER);
	if(b == NULL)
		return NULL;
	// allocate mem
	b->stringValue =(char*) malloc(strlen(bisonString)+1 * sizeof(char));
	strcpy(b->stringValue, bisonString);
	if(b->stringValue == NULL)
		return NULL;
	else
		return b;
}

SExpression *createNumber(int numlit)
{
    SExpression *b = allocateExpression(eNUMLIT);

    if (b == NULL)
        return NULL;

    b->type = eNUMLIT;
    b->numlit = numlit;

    return b;
}

SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right)
{
    SExpression *b = allocateExpression(type);

    if (b == NULL)
        return NULL;

    b->left = left;
    b->right = right;

    return b;
}

void deleteExpression(SExpression *b)
{
    if (b == NULL)
        return;
	else if(b->stringValue != NULL)
		free(b->stringValue);

    deleteExpression(b->left);
    deleteExpression(b->right);

    free(b);
}
