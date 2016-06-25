
#include "CodeGenerator.h"
void generateIRCode(AbstractNode* rootNode)
{
	rootNode->printNode(0);
	TheModule = new Module("IR Code ", TheContext);
	std::cout << "TheModule " << TheModule << std::endl;
	if(TheModule == NULL)
	{
		std::cerr << "Error couldn't init TheModule" << std::endl;
	}
	else
	{
		Value* rootVal = rootNode->codegen();
		TheModule->dump();
	}
}
