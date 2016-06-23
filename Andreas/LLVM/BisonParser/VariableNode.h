#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include <string>

using namespace llvm;

class VariableNode: public TerminalNode
{

	private:
		std::string Name;
	protected:
		void printNodeValue();
	public:
		int isTerminalNode();
		VariableNode(std::string);
		virtual ~VariableNode();
		std::string getName();
		virtual Value* codegen();
};

#endif
