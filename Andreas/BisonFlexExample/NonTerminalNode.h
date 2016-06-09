#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "AbstractNode.h"
#include <string>

class NonTerminalNode: public AbstractNode 
{
	public:
		NonTerminalNode(std::string);
		~NonTerminalNode();
		void incrementLevelCounter();
		void printNodeValue();
	protected:
		std::string value;
	private:
};

#endif /*NONTERMINALNODE_H*/
