#ifndef NODE_H
#define NODE_H

enum class NodeType
{
	P,
	PPrime,
	F,
	M,
	B,
	BPrime,
	I,
	Keyword,
	Identifier,
	StringLiteral
};


class Node
{
	public:
		Node(NodeType type): type(type)
		{
			
		}
		Node(){};
	protected:
	private:
		NodeType type;
		
}

#endif
