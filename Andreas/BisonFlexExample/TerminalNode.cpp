#include "TerminalNode.h"

#include <iostream>

TerminalNode::TerminalNode(std::string givenValue):stringValue(givenValue), AbstractNode()
{
    this->isString = true;
}

TerminalNode::TerminalNode(int givenValue): numValue(givenValue)
{
    this->isString = false;
	numValue = -1;
}

TerminalNode::~TerminalNode()
{
    // do not call base class destructor
}

void TerminalNode::printNodeValue()
{
    if(isString && this->stringValue.size() )
        std::cout << this->stringValue;
    else if(numValue != -1)
        std::cout << this->numValue;
	else
		std::cout << "This node has no Value";
}
