#include "TerminalNode.h"

void LogError(const char* Str)
{
    std::cerr << Str << std::endl;
}

Value *LogErrorV(const char* Str)
{
    LogError(Str);
    return NULL;
}

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

int TerminalNode::isTerminalNode()
{
	return 1;
}

Value* TerminalNode::codegen()
{
//	std::cout << "Hello from TerminalNode::codgen() NodeName " << this->stringValue << std::endl;
	return NULL;
}

void TerminalNode::printNodeValue()
{
	std::cout << "Terminal Node ";
    if(isString && this->stringValue.size() )
        std::cout << this->stringValue;
    else
		std::cout << this->numValue; 
}

