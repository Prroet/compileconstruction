#ifndef TESTNODE_H
#define TESTNODE_H

#include "AbstractNode.h"

class TestNode: public AbstractNode 
{
	public:
		TestNode(char);
		~TestNode();
		void incrementLevelCounter();
	protected:
		char value;
	private:
};

#endif /*TESTNODE_H*/ 