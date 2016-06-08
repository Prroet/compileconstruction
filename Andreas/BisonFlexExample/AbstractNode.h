#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <vector>

class AbstractNode
{
	public:
		AbstractNode();
		virtual ~AbstractNode()=0;
		void printNode();
		unsigned getNodeLevel();
		unsigned getNumberOfChildren();
		incrementLevelCounter() = 0;
	private:
	protected:
		std::vector<AbstractNode*> children;
		// on which level is this node? needed for printing the node later!
		unsigned nodeLevel;
		// levels of the tree
		static unsigned levelCounter;
}

int AbstractNode::levelCounter = 0;	// because we start at level 0

#endif /*ABSTRACTNODE_H*/
