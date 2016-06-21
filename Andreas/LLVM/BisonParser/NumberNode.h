#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"

using namespace llvm;

class NumberNode: public TerminalNode
{
	private:
		virtual Value* codegen();
		int Val;
	protected:
		void printNodeValue();
	public:
		NumberNode(int);
		virtual ~NumberNode();
};

#endif
