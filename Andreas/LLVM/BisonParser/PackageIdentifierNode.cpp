#include "PackageIdentifierNode.h"

PackageIdentifierNode::PackageIdentifierNode(VariableNode* varNode)
{
	this->Name = varNode->getName();
	std::cout << "Deleting varNode from PackageIdNode()" << std::endl;
	delete varNode;	// dirty
	std::cout << "Delete done "<< std::endl;
	
}

std::string PackageIdentifierNode::getName()
{
	return this->Name;
}

PackageIdentifierNode::~PackageIdentifierNode()
{
}

Value* PackageIdentifierNode::codegen()
{
	for(unsigned i=0; i<this->children.size(); i++)
	{
		Value* returnVal = this->children.at(i)->codegen();
		if(returnVal)
			return returnVal;
	}
	return NULL;
}

int PackageIdentifierNode::isTerminalNode()
{
	return 2;
}

void PackageIdentifierNode::printNodeValue()
{
    std::cout << "Variable Node ";
	std::cout << this->Name;
}
