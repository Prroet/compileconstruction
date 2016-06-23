#include "NonTerminalNode.h"

#include <iostream>

NonTerminalNode::NonTerminalNode(std::string givenValue):name(givenValue)
{
}

NonTerminalNode::~NonTerminalNode()
{
//	for(int i=0; i<children.size(); i++)
//		delete(children.at(i));
}

/*void NonTerminalNode::incrementLevelCounter()
{
} */

int NonTerminalNode::isTerminalNode()
{
	return 0;
}

void NonTerminalNode::printNodeValue()
{
	if(this->name.size())
	{	
		std::cout << "NonTerminal Value " << this->name << std::endl;
	}
	else
		std::cout << "This node has no value" << std::endl;
}
// not sure if this works
Value* NonTerminalNode::codegen()
{
	Value* returnValue;
	if(this->children.size() == 0)
		std::cerr << "Error NonTerminal Node has no children !!!!!" << std::endl;
	for(unsigned i=0; i < this->children.size(); i++)
	{
		std::cout << "Children Size NonTerminalNode " << this->children.size() << std::endl;
		std::cout << "Name of this Node " << this->name << std::endl;
		try{
		if(this->children.at(i) != NULL)
		{
			std::cout << "hello from codegen() NonTerminal " << std::endl;
			returnValue = this->children.at(i)->codegen();
		}
		}
		catch(std::exception& e)
		{
			std::cout << "Out of range from NonTerminal!" << std::endl;
		}
		if(returnValue == NULL)
		{
			std::cout << "returnValue "; 
			returnValue->dump(); 
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Found NULL continue" << std::endl;
		}
//			return returnValue;	
	}
	std::cout << "end of loop NonTerminal::codegen()" << std::endl;
}
