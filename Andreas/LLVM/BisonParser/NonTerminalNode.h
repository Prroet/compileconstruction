#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "AbstractNode.h"
#include <string>

class NonTerminalNode: public AbstractNode 
{
	public:
		NonTerminalNode(std::string);
		~NonTerminalNode();
//		virtual Value* codegen();
	protected:
		std::string value;
		void printNodeValue();
	private:
};

#endif /*NONTERMINALNODE_H*/
