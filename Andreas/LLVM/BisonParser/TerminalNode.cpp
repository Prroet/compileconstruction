#include "TerminalNode.h"

TerminalNode::TerminalNode(std::string givenValue):stringValue(givenValue)
{
    this->isString = true;
}

TerminalNode::TerminalNode(int givenValue): numValue(givenValue), isString(false)
{
}

TerminalNode::~TerminalNode()
{
    // do not call base class destructor
}

void TerminalNode::printNodeValue()
{
	std::cout << "Terminal Node ";
    if(isString && this->stringValue.size() )
        std::cout << this->stringValue;
    else
		std::cout << this->numValue; 
}
