#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "TerminalNode.h"

using namespace llvm;

class NumberNode: public TerminalNode
{
	private:
		virtual Value* codegen();
		double Val;
	protected:
	public:
		NumberNode(int);
		virtual ~NumberNode();
		int isTerminalNode();
		void printNodeValue();
};

#endif
