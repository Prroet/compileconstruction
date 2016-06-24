#include "FuncIdentifierNode.h"

FuncIdentifierNode::FuncIdentifierNode(std::string Value): Name(Value)
{
	
}

FuncIdentifierNode::~FuncIdentifierNode()
{
}

FuncIdentifierNode::FuncIdentifierNode(VariableNode* var)
{
	this->Name = var->getName();
	delete var; // dirty!!!!!
//	NamedValues[]		
}

Value* FuncIdentifierNode::codegen()
{
//	std::cout << "Hello From FuncIdentifierNode codegen()" << std::endl;
	if(this->children.size() > 0)
		LogError("FuncIdentifierNode should have no children!!!");
	
	return NULL;
}

int FuncIdentifierNode::isTerminalNode()
{
	return 2;
}

void FuncIdentifierNode::printNodeValue()
{
    std::cout << "FuncIdentifierNode ";
	std::cout << this->Name;
}
