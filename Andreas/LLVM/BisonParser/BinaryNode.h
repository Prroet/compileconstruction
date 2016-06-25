#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include "LLVMStuff.h"
#include <string>
#include <iostream>

using namespace llvm;

class BinaryNode: public TerminalNode
{

	private:
		virtual Value* codegen();
		std::string operatorSymbol;
		void printNodeValue();
	protected:
	public:
		int isTerminalNode();
		BinaryNode(std::string);
		virtual ~BinaryNode();
};

#endif
