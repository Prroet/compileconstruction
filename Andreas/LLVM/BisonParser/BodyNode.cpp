#include "BodyNode.h"

unsigned BodyNode::currentChild=0;

BodyNode::BodyNode(std::string givenValue):stringValue(givenValue)
{
}

BodyNode::~BodyNode()
{
    // do not call base class destructor
}

Value* BodyNode::codegen()
{
//	std::cout << "Hello from TerminalNode::codgen() NodeName " << this->stringValue << std::endl;
	// need to go through all children recursively
	if(currentChild < this->children.size())
	{
		Value* retValue = this->children.at(currentChild)->codegen();
		currentChild++;
		return retValue; 
	} 
	return NULL;
}

void BodyNode::printNodeValue()
{
	std::cout << "Body Node ";
    std::cout << this->stringValue;
}

