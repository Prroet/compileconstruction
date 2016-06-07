/*
 * Expression.h
 * Definition of the structure used to build the syntax tree.
 */
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

/**
 * @brief The operation type
 */
typedef enum tagEOperationType
{
	eSTRING,
	eNUMLIT,
    eKEYWORD,
	eIDENTIFIER,
	eMULTIPLY,
	ePLUS,
	eASSIGNMENT
} EOperationType;

/**
 * @brief The expression structure
 */
typedef struct tagSExpression
{
    EOperationType type;///< type of operation
	
	char* stringValue;
    int numlit;///< valid only when type is eNUMLIT
    struct tagSExpression *left; ///< left side of the tree
    struct tagSExpression *right;///< right side of the tree
} SExpression;

/**
	@ creates a Node for the tree that contains a string which has the type
		EOperationType
	@param stringLit the value of the Node which will be copied internally
		because of later the string can be gone
	@param EOperationType to set type
	@ return the expression
**/
SExpression *createIdentifier(char* bisonString, EOperationType type);

/**
 * @brief It creates an identifier
 * @param value The number value
 * @return The expression or NULL in case of no memory
 */
SExpression *createNumber(int numlit);

/**
 * @brief It creates an operation
 * @param type The operation type
 * @param left The left operand
 * @param right The right operand
 * @return The expression or NULL in case of no memory
 */
SExpression *createOperation(EOperationType type, SExpression *left, SExpression *right);

/**
 * @brief Deletes a expression
 * @param b The expression
 */
void deleteExpression(SExpression *b);

#endif // __EXPRESSION_H__
