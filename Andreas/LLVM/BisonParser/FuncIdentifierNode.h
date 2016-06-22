#ifndef FUNCIDENTIFIERNODE_H
#define FUNCIDENTIFIERNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include "VariableNode.h"
#include <string>

using namespace llvm;

class FuncIdentifierNode: public TerminalNode
{

	private:
		virtual Value* codegen();
		std::string Name;
	protected:
		void printNodeValue();
	public:
		int isTerminalNode();
		FuncIdentifierNode(VariableNode* var);
		FuncIdentifierNode(std::string);
		virtual ~FuncIdentifierNode();
};

#endif
