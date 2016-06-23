#include "DeclarationNode.h"

DeclarationNode::DeclarationNode()
{	
}

DeclarationNode::~DeclarationNode()
{
}

// get the number value and then insert the number in symbol table
Value* DeclarationNode::codegen()
{
//	std::cout << "Codegen() DeclNode childrenSize " << this->children.size() << std::endl;
	if(this->children.size() == 2)
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
				}		
			}
		}
		else if(typeNameFirst.compare("10NumberNode"))
		{
			std::cerr << "Error! can't assign Value to a Number!" << std::endl;
		}
		else
		{
			std::cerr << "Error! Unexpected Type!" << std::endl;
		} // still missing binaryOperatorNode !
	}
	else
		std::cerr << "Number of Nodes is not 2 " << std::endl;
}


void DeclarationNode::insertChildrenInSymbolTable()
{//  std::cout << "Codegen() DeclNode childrenSize " << this->children.size() << std::endl;

/*	if(this->children.size() == 2)
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
	} */
}

int DeclarationNode::isTerminalNode()
{
	return 2;
}

void DeclarationNode::printNodeValue()
{
    std::cout << "Declaration Node :=";
}
