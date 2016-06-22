#ifndef DECLARATIONNODE_H
#define DECLARATIONNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include <string>

using namespace llvm;

class DeclarationNode: public TerminalNode
{

	private:
		virtual Value* codegen();
		void insertChildrenInSymbolTable();
		std::string Value;
	protected:
		void printNodeValue();
	public:
		int isTerminalNode();
		DeclarationNode(std::string);
		virtual ~DeclarationNode();
};

#endif
