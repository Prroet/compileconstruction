/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 14:44
 */
#include <iosfwd>
#include <iostream>


#include "ANode.h"
#include "Tree.h"
#include "TreeNode.h"
#include "INode.h"
#include "P2Node.h"
#include "PNode.h"
#include "MNode.h"
#include "SNode.h"
#include "FNode.h"
#include "BNode.h"
#include "B2ndHalfNode.h"

Tree::Tree() {
    Root = nullptr;
    myfile.open("ast.txt");
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
    myfile.close();
}

void Tree::buildTree() { 
   Root = A(1);
    
}

TreeNode* Tree::A(int counter){
    myfile << "Root(A)->\n";
    counter++;
    return new ANode( P(counter), P2ndHalf(counter) );
    
}

TreeNode* Tree::P(int counter){//muss man einen PNode erstellen und an ANode anhängen oder darf man direkt das INode anhängen
    next_token = gettok();//müsste package drin stehen
    if(next_token == "package"){
        tokenType id = Tree::gettok();
        next_token = gettok();
        if(next_token == ";"){
            calcWriteTab(counter);
            myfile << "P(\"package\" id ;)->\n";
            counter++;
            return new PNode( I(counter, id) );
        }else{
            std::cout << "Delimiter \";\" fehlt" << std::endl;
        }
    } 
    std::cout << "Keyword \"package\" fehlt" << std::endl;
    return nullptr; 
    
}

TreeNode* Tree::P2ndHalf(int counter) {
    next_token = gettok();
    if(next_token == "func" ) {
        calcWriteTab(counter);
        myfile << "P2(\"func\")->\n";
        counter++;
        return new P2Node( F(counter) );
    }
    else if(next_token == "import" ){
        calcWriteTab(counter);
        myfile << "P2(\"import\")->\n";
        counter++;
        return new P2Node( M(counter), F(counter) );
    }else{
        std::cout << "keine der beiden Keywords func or import" << std::endl;
        return nullptr;
    }
}

TreeNode* Tree::I(int counter, tokenType id) {
    calcWriteTab(counter);   
    myfile << "I(id)->\n";
    counter++;
    return new INode(id);
}

TreeNode* Tree::M(int counter) {
    next_token = gettok();
    calcWriteTab(counter);   
    myfile << "M()->\n";
    counter++;
    return new MNode( S(counter) );
}

TreeNode* Tree::S(int counter) {
    calcWriteTab(counter);   
    myfile << "S(" << next_token << ")->\n";
    return new SNode(next_token);
}

TreeNode* Tree::F(int counter) {
    tokenType id = gettok();
    next_token = gettok();
    if(next_token == "()"){
        next_token = gettok();
        calcWriteTab(counter);   
        myfile << "F( \"()\" )->\n";
        counter++;
        return new FNode( I(counter, id), B(counter) );
    }
    else{
        std::cout << "kein \"()\"" << std::endl;
        return nullptr;
    }

}

TreeNode* Tree::B(int counter) {
    next_token = gettok();
    if(next_token == "{"){
        tokenType b2 = gettok();       
        next_token = gettok();
        if(next_token == "}"){
            calcWriteTab(counter);   
            myfile << "B()->\n";
            counter++;
            return new BNode( B2Half( counter, b2 ) );
        }else{
            std::cout << "keine \"}\"" << std::endl;
            return nullptr;
        }
    }
    std::cout << "keine \"{\"" << std::endl;
    return nullptr;

}

TreeNode* Tree::B2Half(int counter, tokenType b2 ) {
    return new B2ndHalfNode();

}

void Tree::calcWriteTab(int counter){
    for(int i = 0; i <= counter; i++){
        myfile <<"\t";
    }
}




tokenType Tree::gettok() {
//eigentlich ist das eine Funktion die der Lexer  zu verfügung stellen muss
}

