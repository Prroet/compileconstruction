#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "AbstractNode.h"
#include <string>
#include <iostream>
#include "llvm/IR/DerivedTypes.h"

using namespace llvm;

class TerminalNode: public AbstractNode
{
	public:
		TerminalNode(std::string);
		TerminalNode(int givenValue);
		~TerminalNode();
		virtual Value* codegen();
	protected:
		std::string stringValue;
        int numValue;
		void printNodeValue();
	private:
        bool isString;
};

#endif /*TERMINALNODE_H*/
