#include "AbstractNode.h"

AbstractNode::AbstractNode()
{
	if(levelCounter > 0)
	{
		levelCounter++;	// make the level higher
		nodeLevel = levelCounter;	// give it to this node
		levelCounter--;	// decrement the level for more nodes on the same level
	}
	else
		nodeLevel = levelCounter;	// if this is the first level
}

unsigned AbstractNode::getNodeLevel()
{
	return this->nodeLevel;
}

unsigned AbstractNode::getNumberOfChildren()
{
	return this->children.size();
}

void AbstractNode::printNode()
{
	for(int i=0; i<levelCounter; i++)
		std::cout << "\t";
	std::cout << "Some Value" << std::endl;
}
