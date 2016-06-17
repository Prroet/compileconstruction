#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include "AbstractNode.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/DerivedTypes.h"

using namespace llvm;

static LLVMContext TheContext;
/*static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;*/

void generateIRCode(AbstractNode* rootNode)
{
	if(rootNode != NULL)
		rootNode->printNode(0);
		
}

#endif
