#ifndef LLVMSTUFF_H
#define LLVMSTUFF_H

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <iostream>

using namespace llvm;

extern LLVMContext TheContext;
extern IRBuilder<> Builder;
extern Module* TheModule;
extern std::map<std::string, AllocaInst*> NamedValues;
extern Function* MainFunction;


void LogError(const char*);
Value* LogErrorV(const char*);

#endif
