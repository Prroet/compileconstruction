#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include "AbstractNode.h"
/*#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/DerivedTypes.h" */
#include "NumberNode.h"
#include "TerminalNode.h"
#include <typeinfo>
#include <string>
#include "llvm/IR/Module.h"
#include "llvm/Support/Compiler.h"
using namespace llvm;

/*static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues; */

void printSymbolTableNames()
{
	for(std::map<std::string, Value*>::iterator it=NamedValues.begin(); it!=NamedValues.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
}

void generateIRCode(AbstractNode* rootNode)
{
	TheModule = new Module("sth", TheContext);
	
	if(rootNode != NULL)
		rootNode->printNode(0);
	Value* rootValue = rootNode->codegen(); // recursive Call to codegen
	std::cout << "Now dumping code !" << std::endl;	
	TheModule->dump();
}

#endif
