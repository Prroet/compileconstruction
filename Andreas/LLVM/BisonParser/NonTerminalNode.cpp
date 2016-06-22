#include "NonTerminalNode.h"

#include <iostream>

NonTerminalNode::NonTerminalNode(std::string givenValue):value(givenValue)
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
	if(this->value.size())
	{	
		std::cout << "NonTerminal Value " << this->value << std::endl;
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
	for(unsigned i=0; i<this->children.size(); i++)
	{
		returnValue = this->children.at(i)->codegen();
		if(returnValue)
			return returnValue;
	}
}
