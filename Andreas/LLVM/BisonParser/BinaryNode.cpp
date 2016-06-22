#include "BinaryNode.h"

BinaryNode::BinaryNode(std::string binValue): Value(binValue)
{
	
}

BinaryNode::~BinaryNode()
{
}

Value* BinaryNode::codegen()
{
	
}

int BinaryNode::isTerminalNode()
{
	return 2;
}

void BinaryNode::printNodeValue()
{
    std::cout << "Binary Node ";
	std::cout << this->Value;
}
