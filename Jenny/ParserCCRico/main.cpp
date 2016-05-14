/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vagrant
 *
 * Created on 27. April 2016, 14:42
 */

#include <cstdlib>

#include "Tree.h"
#include "TokenizerLib.h"
#include "Tokenizer.h"
#include <sstream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    std::string codefile = "Beispiel1.go";
    cout << "beispiel ok" << endl;
    std::ifstream goFile(codefile.c_str(), std::ios::in);
    cout << "goFile ok" << endl;
    SymbolTable symbols;
    cout << "SymbolTable ok" << endl;
    Tokenizer Lexer (&goFile, &symbols);
    
    char testStrLine[200];
    stringstream lStream(testStrLine);
    string da;
    
    while(!goFile.eof()){
        da.clear();
        goFile.getline(testStrLine, 256, '\n');
        stringstream lStream(testStrLine);
        while(!lStream.eof()){
            lStream>>da;
            std::cout << "da : " <<da << std::endl;
        }
    }
   
    cout << "Lexer ok" << endl;
    goFile.close();
    
    
    
    //Tokeniser.getNextToken(); //bekomme nächtsen Token, counter sprint hoch
    // Token t.getLineNo();
    //Token t.getTokenName();
    //Tokeniser.peekNextToken(); //nächst Token anschauen ohne den counter hochzu setzt
    //Tree t;

    return 0;
}

