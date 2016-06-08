#include <iostream>
#include "AbstractNode.h"
#include "TestNode.h"
int main(int argc, char* args[])
{
	AbstractNode*  an = new TestNode('a');
	delete an;
	return 0;
}
