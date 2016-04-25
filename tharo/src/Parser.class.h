#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "Lexor.class.h"

typedef struct treeNode treeNode; 

struct treeNode {
	treeNode* left;
	treeNode* right;

	treeNode(treeNode* a, treeNode* b) {
		this->left = a;
		this->right = b;
	}
};


class Parser {
	private:
		Lexor* lexor;
		token* currToken;
		int position;

		token* nextToken();
		bool eot();		

		treeNode* E();
		treeNode* E2();		

	public:
		Parser(Lexor*);
		Parser* Start();
};

#endif
