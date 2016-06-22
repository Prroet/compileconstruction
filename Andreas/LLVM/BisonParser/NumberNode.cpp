#include "NumberNode.h"

NumberNode::NumberNode(int Value): Val(Value)
{
}

NumberNode::~NumberNode()
{
}

Value* NumberNode::codegen()
{
  return ConstantFP::get(TheContext, APFloat(this->Val));
}

int NumberNode::isTerminalNode()
{
	return 2;
}

void NumberNode::printNodeValue()
{
    std::cout << "Number Node ";
	std::cout << this->Val;
}
