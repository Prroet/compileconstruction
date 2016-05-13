#include "Lexer.h"


/**
    @param file
    expects a string which contains the filename
    then it extracts all the tokens from the file
**/
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

/**
    return: Token*
    return: nullptr if no more tokens
**/
Token* Lexer::gettoken()
{
    Token* tokenToReturn = this->tokens[tokenCounter];
    if(tokenCounter < tokens.size())
        tokenCounter++;
    else
        return nullptr;
    return tokenToReturn;
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
    Splits the currentTokenValue and adds the parts
    as token to tokens
**/
void Lexer::splitCurrentToken()
{
    std::string copyOfCurrentToken = currentTokenValue;
    for(auto i : copyOfCurrentToken)
    {
        currentTokenValue = i;
        insertToken(static_cast<int>(TokenType::operatorDelimiter));
    }

}

bool Lexer::isComment()
{
    if(currentTokenValue == "//")
        return true;
    else
        return false;
}

void Lexer::skipComment()
{
    while(lastChar != '\n')
        sourceFile.get(lastChar);
    currentTokenValue = "";
}

/**
    adds all the operator or delimiter symbols to token vector
    still missing comments
**/
void Lexer::addOperatorDelimiter()
{
    while(isDelimStartSymbols(lastChar) && !sourceFile.eof())
    {
        currentTokenValue += lastChar;
        sourceFile.get(lastChar);
    }
    if(isComment())
        skipComment();
    else if( isOperator(currentTokenValue) )
        insertToken(static_cast<int>(TokenType::operatorDelimiter));
    else
        splitCurrentToken();
}

void Lexer::findStringLiteral()
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
    sourceFile.get(lastChar); // clear last char
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
    currentTokenValue = "";
}

/**
    insert Token for Literals
**/
void Lexer::insertToken(int type, int literalType)
{
    Token* toki = new Token(type, currentTokenValue, lineNumber, literalType);
    this->tokens.push_back(toki);
    currentTokenValue = ""; // clear current
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
