#include "Parser.class.h"

#include <iostream>

#define DEBUG 1

Parser::Parser(Lexor* lex) {
	this->lexor = lex;
}

Parser* Parser::Start() {
	std::cout << std::endl << "start parsing the " << this->lexor->tokens.size() << " tokens." << std::endl;

	this->position = 0;
	this->rootNode = this->A();

	return this;
}

/** switches to ne next lexor token **/
void Parser::nextToken() {
	this->currToken = this->lexor->tokens.at( this->position++ );
};

/** had all tokens been consumed? **/
bool Parser::eot() {
	return this->position >= this->lexor->tokens.size();
}

// ---------------------------------------------------

Parser* Parser::Print() {
	this->Print(0, this->rootNode);

	// show Symbols
	std::cout << std::endl << "Symbols: " << std::endl;
	for(auto item : this->symb) {
		std::cout << "   " << item->item->value << std::endl;
	}
	return this;
}

void Parser::Print(int level, treeNode* node) {
	if(node==0) { return; }// terminal

	// print spaces
	int sub = 1;
	if(level>99)	 sub = 3;
	else if(level>9) sub = 2;
	
	std::cout << "\033[1;31m" << level << "\033[0m";
	for(int i=0; i<level-sub; i++) std::cout << " ";

	if(node->item!=0)
		std::cout << "+(" << node->gnode << ") " << node->item->value << std::endl;
	else
		std::cout << "+(" << node->gnode << ")" << std::endl;

	for(int i=0; i<3; i++) {
		if(node->children[i]==0) continue;
		this->Print(level+1, node->children[i]);
	}
	/* old for(treeNode* item : node->children) {
		this->Print(level+1, item);
	}/**/
}

// ---------------------------------------------------

Parser* Parser::addSymb(treeNode* node) {
	this->symb.push_back(node);
	/*this->symbols.insert(
		std::pair<std::string, treeNode*>(node->item->value, node)
	);/**/
	return this;
}

treeNode* Parser::getSymb(std::string value) {
	for(void* i : this->symb) {
		treeNode* item = (treeNode*)i;
		if(item->item->value == value) return item;
	}/**/
	return 0;
}

// ---------------------------------------------------

treeNode* Parser::A() {
	return new treeNode("A", 0, this->E());	
	std::cout << "No more tokens to consume. " << this->position << std::endl;
}


/** Expresion **/
treeNode* Parser::E() {
	// no more tokens -> empty
	if(this->eot()) {
		return 0;
	}
	else if(this->currToken->type == ECast(eof)) {
		return 0;
	}
	
	// empty expression?
	else if(this->currToken->type == ECast(delimiter)) {
		return 0;
	}

	// chain
	return new treeNode("E", 0, this->E2(), this->E());
}
treeNode* Parser::E2(){
	if(this->eot()) return 0;
	token* t = this->currToken;

	//P ackage | I mport | F unction | Var defs
	if(this->currToken->type == ECast(keyWord)) {
		//TODO: Grammatik umschreiben?
		if(t->value == "package") {
			return new treeNode("E'", 0, this->P(), this->del());
		}
		else if(t->value == "import") {
			return new treeNode("E'", 0, this->I(), this->del());
		}
		else if(t->value == "func") {
			return new treeNode("E'", 0, this->F(), this->del());
		}
		else if(t->value == "var") {
			return new treeNode("E'", 0, this->V());
		}
		else {
			std::cout << "Error: Unhandled Keyword " << this->currToken->value << std::endl;	
			this->nextToken();
			return 0;			
		}
	}
	
	//TODO remove later to terminals only
	// the big question is: HOW do this code EVER get reached? It does!
	//std::cout << "Error: unhandled expression " << this->currToken->value << std::endl;	
	this->nextToken();
	return 0;
}


treeNode* Parser::P() {
	token* t = this->currToken;
	this->nextToken();	// consume
	return new treeNode("P", t, this->id());
}

treeNode* Parser::I() { 
	//TODO: lists | single
	token* t = this->currToken;
	this->nextToken();	// consume

	treeNode* tn = this->str();
	this->addSymb(tn);
	return new treeNode("I", t, tn);
}

treeNode* Parser::F() { 
	//TODO: lists | single
	token* t = this->currToken;
	this->nextToken();	// consume
	treeNode* tn = this->id();
	this->addSymb(tn);
	return new treeNode("F", t, tn, this->L(), this->B());
}

treeNode* Parser::S() { 
	token* t = this->currToken;

	// delimiter wegwerfen auf verdacht
	//this->del();

	// Z uweisung | Fc Function-Call | V ar declaration
	// var decl	
	if(t->type == ECast(keyWord)) {
		if(t->value == "var") {
			return new treeNode("S", 0, this->V(), this->del());
		}
	}

	// function call ?
	treeNode* tn = this->getSymb( t->value );	
	if(tn != 0) {
		treeNode* tn = new treeNode("S", 0, this->Fc(), this->del());
		return tn;
	}

	// ... else Z()
	std::cout << "unhandled statement " << t-> value << std::endl;
	this->nextToken();
	return 0; 
}


treeNode* Parser::Fc() {
	token* toki = this->currToken;
	this->nextToken();

	// nested function all, or did we reached the list?
	//TODO handle better in lexor
	if(this->currToken->value == ".") {
		// consume .
		this->nextToken();
		return new treeNode("Fc", toki, this->Fc());
	}
	return new treeNode("Fc", toki, this->L());
}

treeNode* Parser::V() {
	token* toki = this->currToken;
	this->nextToken();
	return new treeNode("V", toki, this->id(), this->V2());
}

treeNode* Parser::V2() {
	token* toki = this->currToken;
	if(this->currToken->value!="=") return 0;
	this->nextToken();	// consume =
	
	token* t = this->currToken;
	if(t->type == ECast(string)) {
		return new treeNode("V'", toki, this->str());		
	}
	else {
		//TODO handle more
		return new treeNode("V'", toki, this->id());
	}
}


// -------------------------
// blocks, list and others
treeNode* Parser::L() {
	if(this->currToken->type != ECast(list_open)) {
		std::cout << "no ( found " << this->currToken->value << std::endl;
		return 0;
	}
	token* toki;
	this->nextToken();	// consume (
	return new treeNode("L", 0, this->L2());
	
	// bin Tree implementation
	/** Flat-Tree implementation
	this->nextToken();	// consume (	
	while(this->currToken->type != ECast(list_close)) {
		//TODO: switch to "E" later on
		//TODO: Error Handling
		tn->children.push_back(
			new treeNode("L'", this->currToken)
		);
		this->nextToken();
	}
	this->nextToken();	// consume )
	return tn; /**/
}

treeNode* Parser::L2() {
	token* toki = this->currToken;

	if(toki->type == ECast(list_close)) {
		this->nextToken(); // consume )
		return 0;
	}
	//TODO: right grammar!
	return new treeNode("L'", 0, this->id(), this->L2());	
}


treeNode* Parser::B() {
	if(this->currToken->type != ECast(block_open)) {
		std::cout << "no { found " << this->currToken->value << std::endl;
		return 0;
	}
	token* toki;
	this->nextToken();	// consume {

	// unecessary delimters?
	/*while(this->currToken->type == ECast(keyWord)) {
		this->nextToken();
	}/**/

	return new treeNode("B", 0, this->B2());
}
treeNode* Parser::B2() {
	token* toki = this->currToken;
	if(toki->type == ECast(block_close)) {
		this->nextToken();	// consume }
		return 0;
	}
	return new treeNode("B'", 0, this->S(), this->B2());
}

// -------------------------
// terminals

treeNode* Parser::str() {
	//TODO check if rlly an str
	token* t = this->currToken;
	this->nextToken();		// consume token
	return new treeNode("str", t);
}

treeNode* Parser::id() {
	//TODO check if rlly an id
	token* t = this->currToken;
	this->nextToken();		// consume token
	return new treeNode("id", t);
}

treeNode* Parser::del() {
	if(this->eot()) return 0;	// eof is an delimiter, too.
	token* t = this->currToken;
	if(t->type != ECast(delimiter)) return 0;
	
	this->nextToken();
	return new treeNode("del", t);
}

