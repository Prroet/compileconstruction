#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "AbstractNode.h"
#include <string>

class TerminalNode: public AbstractNode
{
	public:
		TerminalNode(std::string);
		TerminalNode(int givenValue);
		~TerminalNode();
		void printNodeValue();
	protected:
		std::string stringValue;
        int numValue;
	private:
        bool isString;
};

#endif /*TERMINALNODE_H*/
