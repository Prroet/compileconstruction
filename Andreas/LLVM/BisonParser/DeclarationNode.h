#ifndef DECLARATIONNODE_H
#define DECLARATIONNODE_H

#include "TerminalNode.h"
#include "VariableNode.h"
#include "NumberNode.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Constants.h"
#include <string>

using namespace llvm;

class DeclarationNode: public TerminalNode
{

	private:
		virtual Value* codegen();
	protected:
	public:
		int isTerminalNode();
		void insertChildrenInSymbolTable();
		DeclarationNode();
		virtual ~DeclarationNode();
		void printNodeValue();

};

#endif
