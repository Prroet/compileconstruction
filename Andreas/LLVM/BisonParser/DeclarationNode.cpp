#include "DeclarationNode.h"

DeclarationNode::DeclarationNode()
{	
}

DeclarationNode::~DeclarationNode()
{
}

// get the number value and then insert the number in symbol table
// this is waay to complex!!!
Value* DeclarationNode::codegen()
{
	unsigned leftIndex = 0;
	unsigned rightIndex = 1;
	if(this->children.size()==2)
	{
		Value* rightNodeValue = this->children.at(rightIndex)->codegen();	// give value
		VariableNode* leftNode = (VariableNode*) this->children.at(leftIndex);
		NamedValues[leftNode->getName()] = rightNodeValue;
		return rightNodeValue;
	}
	else
	{
		LogErrorV(":= has to many children! returning NULL!");
		return NULL;
	}
}

int DeclarationNode::isTerminalNode()
{
	return 2;
}

void DeclarationNode::printNodeValue()
{
    std::cout << "Declaration Node :=";
}
