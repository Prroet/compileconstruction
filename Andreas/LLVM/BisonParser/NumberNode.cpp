#include "NumberNode.h"

NumberNode::NumberNode(int Value): Val(Value)
{
}

NumberNode::~NumberNode()
{
}

Value* NumberNode::codegen()
{
  Value* retVal = ConstantFP::get(TheContext, APFloat(this->Val));
//  retVal->dump();
  return retVal;
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
