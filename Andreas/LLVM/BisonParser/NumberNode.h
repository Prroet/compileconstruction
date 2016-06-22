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
		void printNodeValue();
	public:
		NumberNode(int);
		virtual ~NumberNode();
		int isTerminalNode();
};

#endif
