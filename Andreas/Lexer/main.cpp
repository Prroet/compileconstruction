#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Lexer.h"
#include "Token.h"
#include <cctype>

int main()
{
    std::string filename("tutorial_ch1.go");
    Lexer myLexer(filename);
    return 0;
}
