#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "AbstractNode.h"
#include <string>
#include <iostream>
#include <vector>
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace llvm;

static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;

void LogError(const char*);
Value* LogErrorV(const char*);

class TerminalNode: public AbstractNode
{
	public:
		TerminalNode(){};
		TerminalNode(std::string);
		TerminalNode(int givenValue);
		~TerminalNode();
		virtual int isTerminalNode();
		virtual Value* codegen();
		virtual void printNodeValue();
	protected:
		std::string stringValue;
        int numValue;
	private:
        bool isString;
};

#endif /*TERMINALNODE_H*/
