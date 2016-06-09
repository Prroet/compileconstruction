#include "NonTerminalNode.h"

#include <iostream>

NonTerminalNode::NonTerminalNode(std::string givenValue):value(givenValue), AbstractNode()
{
}

NonTerminalNode::~NonTerminalNode()
{
//	for(int i=0; i<children.size(); i++)
//		delete(children.at(i));
}

void NonTerminalNode::incrementLevelCounter()
{
}

void NonTerminalNode::printNodeValue()
{
	std::cout << this->value;
}
