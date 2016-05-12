#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType
{
    identifier,
    keyword,
    operatorDelimiter,
    literal
};

enum class LiteralType
{
    noLiteral,
    stringLiteral,
    floatLiteral,
    imaginaryLiteral,
    runeLiteral,
    intLiteral
};

enum class operatorType
{

};

enum class delimiterType
{

};

/**
    Token with Value and type of token.
    Notice if token is of type literal
    then
**/
struct Token{
    Token(int type, std::string value, unsigned lineNumber)
    {
        this->lineNumber = lineNumber;
        this->type = type;
        this->value = value;
        this->literalType = static_cast<int>(LiteralType::noLiteral);
    }
    Token(int type, std::string value, unsigned lineNumber, int literalType)
    {
        this->lineNumber = lineNumber;
        this->type = type;
        this->type = literalType;
        this->value = value;
    }
    int type;
    int literalType;
    unsigned lineNumber;
    std::string value;
};

#endif // TOKEN_H
















