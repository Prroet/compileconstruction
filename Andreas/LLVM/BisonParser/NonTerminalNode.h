#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "AbstractNode.h"
#include <string>
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Value.h"

class NonTerminalNode: public AbstractNode 
{
	public:
		NonTerminalNode(std::string);
		~NonTerminalNode();
		virtual Value* codegen();
		virtual int isTerminalNode();
	protected:
		std::string name;
		void printNodeValue();
	private:
};

#endif /*NONTERMINALNODE_H*/
