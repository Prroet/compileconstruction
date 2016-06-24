#ifndef BODYNODE_H
#define BODYNODE_H

#include "TerminalNode.h"
#include <string>
#include <iostream>
#include <vector>
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

class BodyNode: public TerminalNode
{
	public:
		BodyNode();
		BodyNode(std::string);
		~BodyNode();
		virtual Value* codegen();
		virtual void printNodeValue();
	protected:
		std::string stringValue;
		static unsigned currentChild;
};

#endif /*TERMINALNODE_H*/
