#include "BinaryNode.h"

BinaryNode::BinaryNode(std::string binValue): operatorSymbol(binValue)
{
	
}

BinaryNode::~BinaryNode()
{
}

Value* BinaryNode::codegen()
{
	if(this->children.size() == 2)
	{
		Value* L = this->children.at(0)->codegen();
		Value* R = this->children.at(1)->codegen();
		if(operatorSymbol.compare("+"))
			return Builder.CreateFAdd(L,R, "addtmp");
		else
			std::cerr << "Error! invalid operator!" << std::endl;
	}		
}

int BinaryNode::isTerminalNode()
{
	return 2;
}

void BinaryNode::printNodeValue()
{
    std::cout << "Binary Node ";
	std::cout << this->operatorSymbol;
}
