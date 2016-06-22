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
			std::string Value;
	protected:
	public:
		int isTerminalNode();
		void insertChildrenInSymbolTable();
		DeclarationNode(std::string);
		virtual ~DeclarationNode();
		void printNodeValue();

};

#endif
