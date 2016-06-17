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

void NonTerminalNode::printNodeValue()
{
	if(this->value.size())
	{	
		std::cout << "NonTerminal Value= " << this->value << std::endl;
	}
	else
		std::cout << "This node has no value" << std::endl;
}

/*Value* NonTerminalNode::codegen()
{
	return NULL;
} */
