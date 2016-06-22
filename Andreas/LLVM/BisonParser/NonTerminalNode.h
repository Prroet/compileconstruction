#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "AbstractNode.h"
#include <string>
#include "llvm/IR/DerivedTypes.h"


class NonTerminalNode: public AbstractNode 
{
	public:
		NonTerminalNode(std::string);
		~NonTerminalNode();
		virtual Value* codegen();
		virtual int isTerminalNode();
	protected:
		std::string value;
		void printNodeValue();
	private:
};

#endif /*NONTERMINALNODE_H*/
