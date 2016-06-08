#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <vector>

class AbstractNode
{
	public:
		AbstractNode();
	private:
	protected:
		std::vector<AbstractNode*> childNodes;
}

#endif /*ABSTRACTNODE_H*/
