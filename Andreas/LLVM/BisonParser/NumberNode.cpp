#include "NumberNode.h"

NumberNode::NumberNode(int Value): Val(Value)
{
}

NumberNode::~NumberNode()
{
}

Value* NumberNode::codegen()
{
 return	ConstantInt::get(TheContext, APInt(sizeof(Val)*8, Val, true));
}

void NumberNode::printNodeValue()
{
    std::cout << "Number Node ";
	std::cout << this->Val;
}
