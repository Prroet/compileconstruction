#include "AbstractNode.h"

#include <iostream>

unsigned AbstractNode::levelCounter = 0;    // because we start at level 0


AbstractNode::AbstractNode()
{
	nodeLevel = levelCounter;
}

AbstractNode::~AbstractNode()
{
	for(int i=0; i<children.size(); i++)
		delete(children.at(i));
	while(children.size())
		children.pop_back();
}
unsigned AbstractNode::getNodeLevel()
{
	return this->nodeLevel;
}

unsigned AbstractNode::getNumberOfChildren()
{
	return this->children.size();
}
// the calling Node has to give his nodeValue to this func
void AbstractNode::printNode(std::string nodeValue)
{
	for(int i=0; i<levelCounter; i++)
		std::cout << "\t";
	std::cout << nodeValue << std::endl;
}
