#ifndef FUNCIDENTIFIERNODE_H
#define FUNCIDENTIFIERNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include "VariableNode.h"
#include <string>
#include <vector>

using namespace llvm;
/**
	Function definition and declaration
	because there is no definition in our Grammar
**/
class FuncIdentifierNode: public TerminalNode
{
	private:
		std::string Name;
		std::vector<std::string> arguments;
	protected:
	public:
		int isTerminalNode();
		FuncIdentifierNode(VariableNode* var);
		FuncIdentifierNode(std::string);
		virtual ~FuncIdentifierNode();
		void printNodeValue();
		virtual Value* codegen();
};

#endif
