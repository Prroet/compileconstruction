#ifndef _KEYWORD_
#define _KEYWORD_

#include "Token.h"

class Keyword : public Token
{
	public:
		inline Keyword (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Break : public Keyword
{
	public:
		inline Break (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Default : public Keyword
{
	public:
		inline Default (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Func : public Keyword
{
	public:
		inline Func (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Interface : public Keyword
{
	public:
		inline Interface (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Select : public Keyword
{
	public:
		inline Select (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Case : public Keyword
{
	public:
		inline Case (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Defer : public Keyword
{
	public:
		inline Defer (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Go : public Keyword
{
	public:
		inline Go (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Map : public Keyword
{
	public:
		inline Map (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Struct : public Keyword
{
	public:
		inline Struct (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Chan : public Keyword
{
	public:
		inline Chan (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Else : public Keyword
{
	public:
		inline Else (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Goto : public Keyword
{
	public:
		inline Goto (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Package : public Keyword
{
	public:
		inline Package (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Switch : public Keyword
{
	public:
		inline Switch (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Const : public Keyword
{
	public:
		inline Const (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Fallthrough : public Keyword
{
	public:
		inline Fallthrough (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class If : public Keyword
{
	public:
		inline If (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Range : public Keyword
{
	public:
		inline Range (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Type : public Keyword
{
	public:
		inline Type (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Continue : public Keyword
{
	public:
		inline Continue (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class For : public Keyword
{
	public:
		inline For (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Import : public Keyword
{
	public:
		inline Import (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Return : public Keyword
{
	public:
		inline Return (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

class Var : public Keyword
{
	public:
		inline Var (const unsigned int& line, const char* const tokenName) : Keyword(line, tokenName) {};
};

#endif _KEYWORD_