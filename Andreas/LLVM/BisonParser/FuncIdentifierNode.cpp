#include "FuncIdentifierNode.h"

FuncIdentifierNode::FuncIdentifierNode(std::string Value): Name(Value)
{
	
}

FuncIdentifierNode::~FuncIdentifierNode()
{
}

FuncIdentifierNode::FuncIdentifierNode(VariableNode* var)
{
	this->Name = var->getName();
	delete var; // dirty!!!!!
//	NamedValues[]		
}

Value* FuncIdentifierNode::codegen()
{
	Function* TheFunction=NULL;
	if(TheModule != NULL)
		TheFunction = TheModule->getFunction(this->Name);
	else 
	{
		LogError("The Module is not initialized!");
	}
	if(TheFunction != NULL)
		LogError("Error this Function should not be defined before!");
	else
	{
		std::vector<Type*> Voids(arguments.size(), Type::getVoidTy(TheContext));
		FunctionType* FT = FunctionType::get(Type::getVoidTy(TheContext), Voids, false);
		TheFunction = Function::Create(FT, Function::ExternalLinkage, this->Name, TheModule);
		if(TheFunction == NULL)
			LogError("FuncIdentifierNode::codegen Function is NULL!");
		else
		{
			BasicBlock* BB = BasicBlock::Create(TheContext, "entry", TheFunction);	// from LLVM Tutorial
			Builder.SetInsertPoint(BB);
			// function has no body yet!
			// Body->Codegen() must be called recursivly so we can add the Body values to the context
			
			while(Value* RetVal = this->children.at(0)->codegen())
			{
				std::cout << "Hello from while loop!"<< std::endl;
				Builder.CreateRet(RetVal);
			}
			verifyFunction(*TheFunction);
			return TheFunction;
		}
	}
	return NULL;
}

int FuncIdentifierNode::isTerminalNode()
{
	return 2;
}

void FuncIdentifierNode::printNodeValue()
{
    std::cout << "FuncIdentifierNode ";
	std::cout << this->Name;
}
