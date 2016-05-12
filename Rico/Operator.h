#ifndef _OPERATOR_
#define _OPERATOR_

#include "Token.h"

class Operator : public Token
{
	public:
		inline Operator (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Plus : public Operator
{
	public:
		inline Plus (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Minus : public Operator
{
	public:
		inline Minus (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Multiply : public Operator
{
	public:
		inline Multiply (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Divide : public Operator
{
	public:
		inline Divide (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Modulo : public Operator
{
	public:
		inline Modulo (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Assign : public Operator
{
	public:
		inline Assign (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class InitAssign : public Operator
{
	public:
		inline InitAssign (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};

class Dot : public Operator
{
	public:
		inline Dot (const unsigned int& line, const char* const tokenName) : Operator(line, tokenName) {};
};
#endif _OPERATOR_