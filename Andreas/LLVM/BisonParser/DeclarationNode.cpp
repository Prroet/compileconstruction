#include "DeclarationNode.h"

DeclarationNode::DeclarationNode(std::string binValue): Value(binValue)
{
	
}

DeclarationNode::~DeclarationNode()
{
}

Value* DeclarationNode::codegen()
{
	insertChildrenInSymbolTable();	
}

void DeclarationNode::insertChildrenInSymbolTable()
{
//	for()
}

int DeclarationNode::isTerminalNode()
{
	return 2;
}

void DeclarationNode::printNodeValue()
{
    std::cout << "Declaration Node";
	std::cout << this->Value;
}
