#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <vector>
#include <string>

class AbstractNode
{
	public:
		AbstractNode();
		virtual ~AbstractNode();
		/**
		 * @param string with Node Value information
		**/
		void printNode(std::string);
		unsigned getNodeLevel();
		unsigned getNumberOfChildren();
		virtual void incrementLevelCounter() = 0;
	private:
	protected:
		std::vector<AbstractNode*> children;
		// on which level is this node? needed for printing the node later!
		unsigned nodeLevel;
		// levels of the tree
		static unsigned levelCounter;
};


#endif /*ABSTRACTNODE_H*/
