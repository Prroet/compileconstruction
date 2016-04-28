#ifndef _TOKEN_
#define _TOKEN_

#include <string>

class Token
{
	private:
		const unsigned int _line;
		const std::string _tokenName;

	private:
		inline Token& operator= (const Token& right) { right; return *this; };
		inline Token(void) : _line(0), _tokenName("") {};

	public:
		inline explicit Token(const unsigned int& line, const char* const tokenName) : _line(line), _tokenName(tokenName) {};
		inline virtual ~Token(void) {};

		inline const unsigned int& getLineNumber(void) const { return _line; };
		inline const std::string& getTokenName(void) const { return _tokenName; };
};

class Identifier : public Token
{
	public:
		inline Identifier (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Keyword : public Token
{
	public:
		inline Keyword (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Operator : public Token
{
	public:
		inline Operator (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Delimiter : public Token
{
	public:
		inline Delimiter (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Semicolon : public Token
{
	public:
		inline Semicolon (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Parenthesis : public Token
{
	public:
		inline Parenthesis (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Literal abstract : public Token
{
	public:
		inline Literal (const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {};
};

class Integer : public Literal
{
	public:
		inline Integer (const unsigned int& line, const char* const tokenName) : Literal(line, tokenName) {};
};

class String : public Literal
{
	public:
		inline String (const unsigned int& line, const char* const tokenName) : Literal(line, tokenName) {};
};

#endif _TOKEN_