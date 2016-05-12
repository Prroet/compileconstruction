#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>
#include <string>

#include "Lexor.class.h"

#define SUBNODES 3

typedef struct treeNode treeNode; 
struct treeNode {
	//std::vector<treeNode*> children;
	treeNode* children[SUBNODES];
	token* item;
	std::string gnode;

	treeNode(std::string gn, token* i) {
		this->item = i;
		this->gnode = gn;
		for(int i=0; i<SUBNODES; i++)
			this->children[i] = 0;
	}
	treeNode(std::string gn, token* i, treeNode* a) {
		this->item = i;
		this->gnode = gn;
		for(int i=0; i<SUBNODES; i++)
			this->children[i] = 0;
		this->children[0] = a;
	}
	treeNode(std::string gn, token* i, treeNode* a, treeNode* b) {
		this->item = i;
		this->gnode = gn;
		for(int i=0; i<SUBNODES; i++)
			this->children[i] = 0;
		this->children[0] = a;
		this->children[1] = b;
	}
	treeNode(std::string gn, token* i, treeNode* a, treeNode* b, treeNode* c) {
		this->item = i;
		this->gnode = gn;
		for(int i=0; i<SUBNODES; i++)
			this->children[i] = 0;
		this->children[0] = a;
		this->children[1] = b;
		this->children[2] = c;
	}
};


class Parser {
	private:
		Lexor* lexor;
		token* currToken;
		treeNode* rootNode;
		
		std::vector<treeNode*> symb;	// causes malloc error on runtime
		//TODO std::map<std::string, treeNode*> symbols;

		int position;

		void nextToken();
		bool eot();
		void Print(int level, treeNode* node);

		treeNode* A();
		treeNode* E();
		treeNode* E2();		

		treeNode* P();		
		treeNode* I();	
		treeNode* F();
		treeNode* S();
		treeNode* Fc();
		treeNode* V();
		treeNode* V2();

		treeNode* L();
		treeNode* L2();
		treeNode* B();
		treeNode* B2();
		
		treeNode* str();
		treeNode* del();
		treeNode* id();
	public:
		Parser(Lexor*);
		Parser* Start();
		Parser* Print();
		Parser* addSymb(treeNode* node);
		treeNode* getSymb(std::string value);
};

#endif
