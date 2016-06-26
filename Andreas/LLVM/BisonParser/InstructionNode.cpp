#include "InstructionNode.h"

unsigned InstructionNode::currentChild=0;

InstructionNode::InstructionNode(std::string givenValue):stringValue(givenValue)
{
}

InstructionNode::~InstructionNode()
{
    // do not call base class destructor
}

Value* InstructionNode::codegen()
{
//	std::cout << "Hello from TerminalNode::codgen() NodeName " << this->stringValue << std::endl;
	// need to go through all children recursively
/*	if(currentChild < this->children.size())
	{
		Value* retValue = this->children.at(currentChild)->codegen();
		if(ret)
		return retValue; 
	}  */
	unsigned firstChild = 0;
	unsigned secondChild = 1;
	if(this->children.size() == 0)	// so we are at the end of instructions 
		return NULL;
	else if(this->children.at(firstChild)->codegen() != NULL) // so first child was not NULL
		return this->children.at(secondChild)->codegen();	// call codegen of the next instruction node and so on....
}

void InstructionNode::printNodeValue()
{
	std::cout << "Instruction Node ";
	std::cout << this->stringValue;
}

