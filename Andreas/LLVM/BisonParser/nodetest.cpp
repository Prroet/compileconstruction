#include <iostream>
#include "AbstractNode.h"
#include "TestNode.h"
int main(int argc, char* args[])
{
	AbstractNode*  parent = new TestNode('a');
	AbstractNode*  child1 = new TestNode('b');
	an->printNodeValue(); std::cout << std::endl;
	delete an;
	return 0;
}


// NonTerminalNode("A");

// NonTerminalNode("PPrime");


