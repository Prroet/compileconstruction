#include "Lexer.h"



Lexer::Lexer(std::string& file)
{
    sourceFile.open(file);
    lineNumber = 1;
    while(!sourceFile.eof())
    {
        tokenize();
    }
    printTokens();
}

Lexer::~Lexer()
{
    //dtor
}

void Lexer::printTokens()
{
    std::cout << "Line Number" << "\t" << "Type" << "\t" << "value" << std::endl;
    for(const Token* i : this->tokens)
    {
        std::cout << "\t" << i->lineNumber << "\t" << i->type << "\t" << i->value << std::endl;
    }
}

void Lexer::tokenize()
{
    if(lastChar == '\t' || lastChar == '\n' ||
        lastChar== ' ' || lastChar == '\r')
        skip(lastChar);

    if(lastChar == '"')
        findStringLiteral();

    if(isDelimStartSymbols(lastChar))
        addOperatorDelimiter();

    if(isalpha(lastChar))
        findIdentifier();

    if(isdigit(lastChar))
        findNumLiteral();
}
/**
    skip all chars that equal charToSkip param
**/
void Lexer::skip(char charToSkip)
{
    if(lastChar == charToSkip)
    {
        if(lastChar == '\n')
            lineNumber++;
        sourceFile.get(lastChar);
        while(lastChar == charToSkip && !sourceFile.eof())
        {
            if(lastChar == '\n')
                lineNumber++;
            sourceFile.get(lastChar);
        }
    }
}

/**
    skips all the chars until endString is found
    @param endstring
**/
void Lexer::skipUntil(std::string& endstring)
{

}

/**
    adds all the operator or delimiter symbols to token vector
    still missing comments
**/
void Lexer::addOperatorDelimiter()
{
    while(isDelimStartSymbols(lastChar))
    {
        if(lastChar == '(' || lastChar == ')')
        {
            currentTokenValue = lastChar;
            insertToken(static_cast<int>(TokenType::operatorDelimiter));
            currentTokenValue = ""; // here size is 0
            sourceFile.get(lastChar);
        }
        else
        {
            currentTokenValue += lastChar;
            sourceFile.get(lastChar);
        }
    }
    if(currentTokenValue.size() != 0) // here test for size 0 because of above if
        insertToken(static_cast<int>(TokenType::operatorDelimiter));
    currentTokenValue = ""; // clear currentToken
}

void Lexer::findStringLiteral()
{
    if(lastChar == '"')
    {
        currentTokenValue = lastChar;
        sourceFile.get(lastChar);
        while(lastChar != '"' && !sourceFile.eof())
        {
            currentTokenValue += lastChar;
            sourceFile.get(lastChar);
        }
        currentTokenValue += lastChar;

        insertToken(static_cast<int>(TokenType::literal), static_cast<int> (LiteralType::stringLiteral));

        currentTokenValue = ""; // clear current token
        sourceFile.get(lastChar); // clear last char
    }
}

void Lexer::findIdentifier()
{
    if(isalpha(lastChar))
    {
        currentTokenValue = lastChar;
        sourceFile.get(lastChar);
        while(isalnum(lastChar) && !sourceFile.eof())
        {
            currentTokenValue += lastChar;
            sourceFile.get(lastChar);
        }
        sourceFile.seekg(-1, sourceFile.cur); // set back cursor one time
        if(isKeyWord(currentTokenValue))
        {
            insertToken(static_cast<int>(TokenType::keyword));
        }
        else
        {
            insertToken(static_cast<int>(TokenType::identifier));
        }
        currentTokenValue = ""; // clear
        sourceFile.get(lastChar); // get new last char
    }
}

void Lexer::findNumLiteral()
{
    if(isdigit(lastChar))
    {
        currentTokenValue = lastChar;
        sourceFile.get(lastChar);
        while(isdigit(lastChar) || lastChar == '.')
        {
            currentTokenValue += lastChar;
            sourceFile.get(lastChar);
        }
        sourceFile.seekg(-1, sourceFile.cur);

        insertToken(static_cast<int>(TokenType::literal), static_cast<int>(LiteralType::intLiteral));

        currentTokenValue = "";
        sourceFile.get(lastChar);
    }
}

/**
    insert Token for all non Literal types
**/
void Lexer::insertToken(int type)
{
    Token* toki = new Token(type, currentTokenValue, lineNumber);
    this->tokens.push_back(toki);
}

/**
    insert Token for Literals
**/
void Lexer::insertToken(int type, int literalType)
{
    Token* toki = new Token(type, currentTokenValue, lineNumber, literalType);
    this->tokens.push_back(toki);
}

bool Lexer::isKeyWord(std::string& tokenValue)
{
    bool returnValue = false;
    for(const std::string i : keyWords)
    {
        if(i.compare(tokenValue) == 0)
            returnValue = true;
    }
    return returnValue;
}

bool Lexer::isOperator(std::string& tokenValue)
{
    bool isOp=false;
    for(auto i:operators)
    {
        if(i.compare(tokenValue) == 0)
        {
            isOp=true;
        }
    }
    return isOp;
}

bool Lexer::isDelimStartSymbols(char& character)
{
    bool isDelim=false;
    for(auto i:this->operatorDelimStartSymbols)
    {
        if(i == character)
            isDelim = true;
    }
    return isDelim;
}
