#ifndef _PARENTHESIS_
#define _PARENTHESIS_

#include "Token.h"

class Parenthesis : public Token
{
	public:
		inline Parenthesis (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class LeftParenthesis : public Parenthesis
{
	public:
		inline LeftParenthesis (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};

class RightParenthesis : public Parenthesis
{
	public:
		inline RightParenthesis (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};

class SquaredBracketOpen : public Parenthesis
{
	public:
		inline SquaredBracketOpen (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};

class SquaredBracketClose : public Parenthesis
{
	public:
		inline SquaredBracketClose (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};

class LeftCurlyBracket : public Parenthesis
{
	public:
		inline LeftCurlyBracket (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};

class RightCurlyBracket : public Parenthesis
{
	public:
		inline RightCurlyBracket (const unsigned int& line, const char* const tokenName) : Parenthesis(line, tokenName) {};
};



#endif _PARENTHESIS_