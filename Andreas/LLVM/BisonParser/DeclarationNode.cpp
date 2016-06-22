#include "DeclarationNode.h"

DeclarationNode::DeclarationNode(std::string binValue): Value(binValue)
{
	
}

DeclarationNode::~DeclarationNode()
{
}

Value* DeclarationNode::codegen()
{
}

void DeclarationNode::insertChildrenInSymbolTable()
{
	if(this->children.size() == 2)
	{
		std::string typeNameFirst = typeid(this->children.at(0)).name();
		std::string typeNameSecond = typeid(this->children.at(1)).name();
		if(typeNameFirst.compare("10VariableNode"))
		{
			if(typeNameSecond.compare("10NumberNode"))
			{
					
			}
			else if(typeNameSecond.compare("10VariableNode"))
			{
			}
		}
		else if(typeNameFirst.compare("10NumberNode"))
		{
			std::cerr << "Error! can't assign Value to a Number!" << std::endl;
		}
		else
		{
			std::cerr << "Error! Unexpected Type!" << std::endl;
		}
	}
}

int DeclarationNode::isTerminalNode()
{
	return 2;
}

void DeclarationNode::printNodeValue()
{
    std::cout << "Declaration Node";
	std::cout << this->Value;
}
