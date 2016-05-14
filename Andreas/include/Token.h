#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType
{
    identifier,     // 0
    keyword,        // 1
    operatorDelimiter,  // 2
    literal            // 3
};

enum class LiteralType
{
    noLiteral,  // 0
    stringLiteral,  // 1
    floatLiteral,   // 2
    imaginaryLiteral,   // 3
    runeLiteral,    // 4
    intLiteral  // 5
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
        this->value = value;
        this->type = literalType;
    }
    
    int type;
    int literalType;
    unsigned lineNumber;
    std::string value;
};

#endif // TOKEN_H
















