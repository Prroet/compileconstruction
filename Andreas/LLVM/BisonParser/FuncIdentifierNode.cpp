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
	for(unsigned i=0;i < this->children.size(); i++)
	{
		Value* returnValue = this->children.at(i)->codegen();
		if(returnValue)
			return returnValue;
	}
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
