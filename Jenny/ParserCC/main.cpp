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

    //Tree t("Beispiel1.go");
    //Tree t("Beispiel1a.go");
    //Tree t("WrongInputFile1.go");
    Tree t("Beispiel2.go");
    //Tree t("WrongInputFile1a.go");
    //Tree t("WrongInputFile2.go");
    //Tree t("WrongInputFile2a.go");
    std::cout << "Bin bis zum Ende gekommen" <<std::endl;
    
    return 0;
}

