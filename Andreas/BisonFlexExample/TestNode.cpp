#include "TestNode.h"

#include <iostream>

TestNode::TestNode(char givenValue):value(givenValue), AbstractNode()
{
	std::cout << "Value given " << value << std::endl; 
}

TestNode::~TestNode()
{
//	for(int i=0; i<children.size(); i++)
//		delete(children.at(i));
}

void TestNode::incrementLevelCounter()
{
}
