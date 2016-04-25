#include "Parser.class.h"

#include <iostream>

Parser::Parser(Lexor* lex) {
	this->lexor = lex;
}

Parser* Parser::Start() {
	this->position = 0;
	this->E();

	return this;
}

/** switches to ne next lexor token **/
token* Parser::nextToken() {
	return &this->lexor->tokens.at( this->position++ );
};

/** had all tokens been consumed? **/
bool Parser::eot() {
	return this->position >= this->lexor->tokens.size();
}

// ---------------------------------------------------


/** Expresion **/
treeNode* Parser::E(){
	// no more tokens?
	if(this->eot()) {
		std::cout << "No more tokens to consume. " << this->position << std::endl;
	}
	else {
		return new treeNode(this->E2(), this->E());
	}

	return 0;
}
treeNode* Parser::E2(){
	return 0;
}
