#ifndef PACKAGEIDENTIFIERNODE_H
#define PACKAGEIDENTIFIERNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include "VariableNode.h"
#include <string>

using namespace llvm;

class PackageIdentifierNode: public TerminalNode
{

	private:
		virtual Value* codegen();
		std::string Name;
	protected:
		void printNodeValue();
	public:
		int isTerminalNode();
		PackageIdentifierNode(VariableNode*);
		virtual ~PackageIdentifierNode();
		std::string getName();
};

#endif
