#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "AbstractNode.h"
#include <string>

class NonTerminalNode: public AbstractNode 
{
	public:
		TestNode(std::string);
		~TestNode();
		void incrementLevelCounter();
		void printNodeValue();
	protected:
		std::string value;
	private:
};

#endif /*NONTERMINALNODE_H*/
