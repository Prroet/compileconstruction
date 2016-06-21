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
		virtual Value* codegen();
		std::string Name;
	protected:
		void printNodeValue();
	public:
		VariableNode(std::string);
		virtual ~VariableNode();
};

#endif
