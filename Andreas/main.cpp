#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Lexer.h"
#include "Token.h"


int main()
{
    std::string filename("tutorial_ch1.go");
    Lexer myLexer(filename);
    std::cout << "Grüppchen" << std::endl;
    return 0;
}
