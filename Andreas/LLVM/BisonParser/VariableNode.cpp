#include "VariableNode.h"

VariableNode::VariableNode(std::string Value): Name(Value)
{
//	NamedValues[Name] = NULL; // NULL init is no good!
}

std::string VariableNode::getName()
{
	return this->Name;
}

VariableNode::~VariableNode()
{
}

Value* VariableNode::codegen()
{
	 // Look this variable up in the function.
  Value *V = NamedValues[Name];
  if (!V)
    LogErrorV("Unknown variable name");
  return V;
}

int VariableNode::isTerminalNode()
{
	return 2;
}

void VariableNode::printNodeValue()
{
    std::cout << "Variable Node ";
	std::cout << this->Name;
}
