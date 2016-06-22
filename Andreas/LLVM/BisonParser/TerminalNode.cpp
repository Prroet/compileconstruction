#include "TerminalNode.h"

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

void LogError(const char* Str)
{
    std::cerr << Str << std::endl;
}

Value *LogErrorV(const char* Str)
{
    LogError(Str);
    return NULL;
}

TerminalNode::TerminalNode(std::string givenValue):stringValue(givenValue)
{
    this->isString = true;
}

TerminalNode::TerminalNode(int givenValue): numValue(givenValue), isString(false)
{
}

TerminalNode::~TerminalNode()
{
    // do not call base class destructor
}

int TerminalNode::isTerminalNode()
{
	return 1;
}

Value* TerminalNode::codegen()
{
	return NULL;
}

void TerminalNode::printNodeValue()
{
	std::cout << "Terminal Node ";
    if(isString && this->stringValue.size() )
        std::cout << this->stringValue;
    else
		std::cout << this->numValue; 
}

