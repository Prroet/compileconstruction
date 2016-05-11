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
// This needs improvement like everything else
void Lexer::addOperatorDelimiter()
{
    while(isDelimStartSymbols(lastChar))
    {
        currentTokenValue += lastChar;
        sourceFile.get(lastChar);
    }
    // or this fucks fucks everything up?
    // std::cout << currentTokenValue << std::endl;
    if(isOperator(currentTokenValue))
    {
        insertToken(static_cast<int>(TokenType::operatorDelimiter));
    }
    else
    {
        sourceFile.seekg(-2, sourceFile.cur); // set back cursor
        sourceFile.get(lastChar);
        currentTokenValue = lastChar;
        insertToken(static_cast<int>(TokenType::operatorDelimiter));
    }
    /*currentTokenValue = lastChar;
    while(isDelimStartSymbols(lastChar))
    {
        if(isOperator(currentTokenValue))
        {
            insertToken(static_cast<int>(TokenType::operatorDelimiter));
        }
        else if(isDelimStartSymbols(lastChar)){
            insertToken(static_cast<int>(TokenType::operatorDelimiter));
            currentTokenValue = "";
        }
        currentTokenValue += lastChar;
        // insertToken(static_cast<int>(TokenType::operatorDelimiter));
        sourceFile.get(lastChar);
        if(sourceFile.eof()) // kill the loop not good but works for now
            break;
    } */

    sourceFile.get(lastChar);
    currentTokenValue = "";
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

void Lexer::insertToken(int type)
{
    Token* toki = new Token(type, currentTokenValue, lineNumber);
    this->tokens.push_back(toki);
}

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
