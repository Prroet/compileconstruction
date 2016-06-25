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
	std::cout << "Hello From FuncIdentifierNode::codegen()" << std::endl;
	MainFunction=NULL;
	if(TheModule != NULL)
		MainFunction = TheModule->getFunction(this->Name);
	else 
	{
		LogError("The Module is not initialized!");
	}
	if(MainFunction != NULL)
		LogError("Error this Function should not be defined before!");
	else
	{
		std::vector<Type*> Voids(arguments.size(), Type::getVoidTy(TheContext));
		FunctionType* FT = FunctionType::get(Type::getVoidTy(TheContext), Voids, false);
		MainFunction = Function::Create(FT, Function::ExternalLinkage, this->Name, TheModule);
		if(MainFunction == NULL)
			LogError("FuncIdentifierNode::codegen Function is NULL!");
		else
		{
			BasicBlock* BB = BasicBlock::Create(TheContext, "entry", MainFunction);	// from LLVM Tutorial
			Builder.SetInsertPoint(BB);
			// function has no body yet!
			// Body->Codegen() must be called recursivly so we can add the Body values to the context
			
			//	std::cout << "Hello from while loop!"<< std::endl;
			Value* retVal = NULL;
			for(AbstractNode* i : children)	// if we would have multiple children generate code for it
				retVal = i->codegen();	// the codegen call is most important
			Builder.CreateRet(retVal);
			verifyFunction(*MainFunction);
			return MainFunction;
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
