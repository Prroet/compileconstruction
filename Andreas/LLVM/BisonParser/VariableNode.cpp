#include "VariableNode.h"

VariableNode::VariableNode(std::string Value): Val(Value)
{
}

VariableNode::~VariableNode()
{
}

Value* VariableNode::codegen()
{
	ConstantInt::get(TheContext, APInt(sizeof(Val)*8, Val, true));

}

void VariableNode::printNodeValue()
{
    std::cout << "Variable Node ";
	std::cout << this->Name;
}
