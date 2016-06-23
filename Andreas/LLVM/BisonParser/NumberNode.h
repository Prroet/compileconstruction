#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "TerminalNode.h"

using namespace llvm;

class NumberNode: public TerminalNode
{
	private:
		double Val;
	protected:
	public:
		NumberNode(int);
		virtual ~NumberNode();
		int isTerminalNode();
		void printNodeValue();
		virtual Value* codegen();
};

#endif
