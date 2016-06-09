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
		 * @recursive function which prints this Node and all the Child Nodes
		**/
		void printNode();
		unsigned getNodeLevel();
		unsigned getNumberOfChildren();
		void incrementLevelCounter();
		void decrementLevelCounter();
		unsigned getLevelCounter();
		/**
		 * Abstract method for printing the Node Value	
		**/
		virtual void printNodeValue()=0;
	private:
	protected:
		std::vector<AbstractNode*> children;
		// on which level is this node? needed for printing the node later!
		unsigned nodeLevel;
		// levels of the tree
		static unsigned levelCounter;
};


#endif /*ABSTRACTNODE_H*/
