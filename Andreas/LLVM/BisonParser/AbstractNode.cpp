#include "AbstractNode.h"

#include <iostream>

unsigned AbstractNode::levelCounter = 0;    // because we start at level 0


AbstractNode::AbstractNode()
{
	nodeLevel = levelCounter;
}

AbstractNode::~AbstractNode()
{
	for(unsigned i=0; i<children.size(); i++)
		delete(children.at(i));
	while(children.size())
		children.pop_back();
}

/*void AbstractNode::incrementLevelCounter()
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
*/
void AbstractNode::append(AbstractNode* newNode)
{
	this->children.push_back(newNode);	
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
void AbstractNode::printNode(int depth)
{
	for(int i=0; i<depth; i++)
		std::cout << "\t";
	printNodeValue(); std::cout << std::endl;
	for(unsigned i=0; i<children.size(); i++)
	{
		if(children.at(i) != NULL)
			children.at(i)->printNode(depth+1);
	}
}
