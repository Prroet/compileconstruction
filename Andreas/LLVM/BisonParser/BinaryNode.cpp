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
		if(!L || !R)
		{
			std::cerr << "Error Left or Right are not valid BinaryNode::codegen()" << std::endl;
		}
		if(operatorSymbol.compare("+")==0)
			return Builder.CreateFAdd(L,R, "addtmp");
		else
		{
			std::cout << "Operator is " << operatorSymbol << std::endl;
			LogError("Not supported operator!");
		}
	}
	return NULL;		
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
