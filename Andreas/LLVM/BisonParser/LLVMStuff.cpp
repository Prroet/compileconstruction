#include "LLVMStuff.h"

using namespace llvm;

LLVMContext TheContext;
IRBuilder<> Builder(getGlobalContext());
Module* TheModule = NULL;
std::map<std::string, AllocaInst*> NamedValues;
Function* MainFunction;


void LogError(const char* Str)
{
    std::cerr << Str << std::endl;
}

Value *LogErrorV(const char* Str)
{
    LogError(Str);
    return NULL;
}
