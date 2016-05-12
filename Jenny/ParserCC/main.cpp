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

#include "Lexer.h"
#include "Tree.h"
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
<<<<<<< HEAD
    Tree t;
    t.buildTree();
=======
    std::string codefile = "Beispiel1.go";
    Lexer lex(codefile);
    //Tree t;

>>>>>>> e8bf752993c60f31cf7204cf79c682418f4ddc9b
    return 0;
}

