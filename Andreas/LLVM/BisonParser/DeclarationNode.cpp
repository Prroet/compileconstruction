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
/*	if(this->children.size() == 2)
	{
		std::string typeNameFirst = typeid(this->children.at(0)).name();
		std::string typeNameSecond = typeid(this->children.at(1)).name();
		if(typeNameFirst.compare("10VariableNode"))
		{
			if(typeNameSecond.compare("10NumberNode"))
			{
				VariableNode* firstChild = (VariableNode*) this->children.at(0);
				NumberNode* secondChild = (NumberNode*) this->children.at(1);
				std::string firstChildName = firstChild->getName();
				NamedValues[firstChildName] = secondChild->codegen(); // this gives a value
				return NamedValues[firstChildName];
			}
			else if(typeNameSecond.compare("10VariableNode"))
			{
				VariableNode* firstChild = (VariableNode*) this->children.at(0);	// the variable to declare
				VariableNode* secondChild =(VariableNode*) this->children.at(1);	// the variable where the value is in
				std::string firstChildName = firstChild->getName();
				std::string secondChildName = secondChild->getName();
				Value* valueOfSecondChild = secondChild->codegen();
				if(!valueOfSecondChild)	// if the variable has no value it's undeclared
					std::cerr << "Error undeclared Variable " << secondChildName << std::endl;
				else
				{
					NamedValues[firstChildName] = valueOfSecondChild;
					return NamedValues[firstChildName];
				}		
			}
		}
		else if(typeNameFirst.compare("10NumberNode"))
		{
			std::cerr << "Error! can't assign Value to a Number!" << std::endl;
			return NULL;
		}
		else
		{
			std::cerr << "Error! Unexpected Type!" << std::endl;
			return NULL;
		} // still missing binaryOperatorNode !
	}
	else
		std::cerr << "Number of Nodes is not 2 " << std::endl;
	return NULL; */
}

int DeclarationNode::isTerminalNode()
{
	return 2;
}

void DeclarationNode::printNodeValue()
{
    std::cout << "Declaration Node :=";
}
