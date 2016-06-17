#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <vector>
#include <string>
// #include "llvm/IR/DerivedTypes.h"

//using namespace llvm;

class AbstractNode
{
	public:
		AbstractNode();
		virtual ~AbstractNode();
		/**
		 * recursive function which prints this Node and all the Child Nodes
		**/
		void printNode(int depth);
		unsigned getNodeLevel();
		unsigned getNumberOfChildren();
		/**
            increment level Counter is a good idea!! use it before creating Child Nodes!!
        **/
//		void incrementLevelCounter();
//		void decrementLevelCounter();
//		unsigned getLevelCounter();
		/**
			add child to the node
		**/
		void append(AbstractNode*);
		
//		virtual Value* codegen() = 0;
		/**
		 * Abstract method for printing the Node Value
		**/
	private:
	protected:
		virtual void printNodeValue()=0;
		std::vector<AbstractNode*> children;
		// on which level is this node? needed for printing the node later!
		unsigned nodeLevel;
		// levels of the tree
		static unsigned levelCounter;
};


#endif /*ABSTRACTNODE_H*/
