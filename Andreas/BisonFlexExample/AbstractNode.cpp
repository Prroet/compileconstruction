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

void AbstractNode::incrementLevelCounter()
{
	levelCounter++;
}

void AbstractNode::decrementLevelCounter()
{
	levelCounter--;
}

unsigned AbstractNode::getLevelCounter()
{
	return this->levelCounter;
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
void AbstractNode::printNode()
{
	for(int i=0; i<children.size(); i++)
		children.at(i)->printNode();
	for(int i=0; i<nodeLevel; i++)
		std::cout << "\t";
	printNodeValue(); std::cout << std::endl;
}
