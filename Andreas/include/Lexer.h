#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Token.h"

class Lexer
{
    public:
        Lexer(std::string& filename);
        virtual ~Lexer();
        Token* gettoken();
    protected:
        std::ifstream sourceFile;
        std::vector<Token*> tokens;
        std::string currentTokenValue;
        // all keywords ?Keyword = Type 1?
        std::vector<std::string> keyWords = {"break","default","func","interface","select",
                                                "case","defer","go","map","struct","chan",
                                            "else","goto","package","switch","const", "fallthrough",
                                            "if", "range", "type", "continue","for", "import", "return", "var"};
        // maybe too much ?operators = Type ????
        std::vector<std::string> operators = { "||", "&&", "==", "!=", "<", "<=", ">",
                                                ">=", "+", "-", "|", "^", "*", "/", "%",
                                                "<<", ">>", "&", "&^", "+", "-", "!", "^", "*", "&", "<-", ".", ":="};
        //?operatorDelimStartSymbols = Type 2??
        std::vector<char> operatorDelimStartSymbols = {'(', ')', '{', '}', '.', ';', ',', '+', '=', ':'}; // might need further extension
        unsigned lineNumber;
        unsigned tokenCounter = 0;
        char lastChar = ' ';

        void tokenize();
        void printTokens();
        void skip(char charToSkip);
        void skipUntil(std::string&);
        void addOperatorDelimiter();
        void findStringLiteral();
        void findIdentifier(); //?id = Type 0?
        void findNumLiteral();
        void insertToken(int type);
        void insertToken(int type, int literalType);
        bool isKeyWord(std::string& );
        bool isOperator(std::string&);
        bool isDelimStartSymbols(char&);
    private:
};

#endif // LEXER_H
