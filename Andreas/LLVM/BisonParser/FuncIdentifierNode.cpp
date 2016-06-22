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
//	ConstantInt::get(TheContext, APInt(sizeof(Name)*8, Val, true));

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
