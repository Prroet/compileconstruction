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

void generateIRCode(AbstractNode* rootNode);

#endif
