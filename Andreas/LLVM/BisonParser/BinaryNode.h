#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "TerminalNode.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Constants.h"
#include <string>

using namespace llvm;

class BinaryNode: public TerminalNode
{

	private:
		virtual Value* codegen();
		std::string Value;
		void printNodeValue();
	protected:
	public:
		int isTerminalNode();
		BinaryNode(std::string);
		virtual ~BinaryNode();
};

#endif
