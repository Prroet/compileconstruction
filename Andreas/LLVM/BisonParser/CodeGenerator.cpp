
#include "CodeGenerator.h"
void generateIRCode(AbstractNode* rootNode)
{
	rootNode->printNode(0);
	TheModule = new Module("IR Code ", TheContext);
	if(TheModule == NULL)
	{
		std::cerr << "Error couldn't init TheModule" << std::endl;
		Value* rootVal = rootNode->codegen();
	}
	TheModule->dump();
}
