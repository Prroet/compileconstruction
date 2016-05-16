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

Tree::Tree(std::string codefile): lexer(codefile) {
    Root = nullptr;
    //In der Datei steht dann der Baum
    myfile.open("ast.txt");

    buildTree();
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
    myfile.close();
}

void Tree::buildTree() { 
   Root = A(0);
    
}

TreeNode* Tree::A(int counter){
    myfile << "Root(A)->\n";
    counter++;
    return new ANode( P(counter), P2ndHalf(counter) );
    
}

TreeNode* Tree::P(int counter){//muss man einen PNode erstellen und an ANode anhängen oder darf man direkt das INode anhängen
    next_token = *lexer.gettoken();//müsste "package" drin stehen
    if((next_token.type == static_cast<int>(TokenType::keyword))&& (next_token.value == "package")){
        Token id = *lexer.gettoken();
        next_token = *lexer.gettoken();
        if(next_token.value == ";"){
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
    next_token = *lexer.gettoken();
    if(next_token.value == "func" ) {
        calcWriteTab(counter);
        myfile << "P2(\"func\")->\n";
        counter++;
        return new P2Node( F(counter) );
    }
    else if(next_token.value == "import" ){
        calcWriteTab(counter);
        myfile << "P2(\"import\")->\n";
        counter++;
        return new P2Node( M(counter), F(counter) );
    }else{
        std::cout << "keine der beiden Keywords func or import" << std::endl;
        return nullptr;
    }
}

TreeNode* Tree::I(int counter, Token id) {
    calcWriteTab(counter);   
    myfile << "I(id="<< id <<")->\n";
    counter++;
    return new INode(id);
}

TreeNode* Tree::M(int counter) {
    next_token = *lexer.gettoken();
    calcWriteTab(counter);   
    myfile << "M()->\n";
    counter++;
    return new MNode( S(counter) );
}

TreeNode* Tree::S(int counter) {
    calcWriteTab(counter);   
    myfile << "S(" << next_token.value << ")->\n";
    return new SNode(next_token);
}

TreeNode* Tree::F(int counter) {
    Token id = *lexer.gettoken();
    next_token = *lexer.gettoken();
    if(next_token.value == "("){
        next_token = *lexer.gettoken();
        if(next_token.value == ")"){
            next_token = *lexer.gettoken();
            calcWriteTab(counter);   
            myfile << "F( \"()\" )->\n";
            counter++;
            return new FNode( I(counter, id), B(counter) );
        }
    }

    std::cout << "kein \"(\"" << std::endl;
    return nullptr;
}

TreeNode* Tree::B(int counter) {
    next_token = (*lexer.gettoken());
    std::cout << next_token.value << std::endl; //Ausgabe}
    if(next_token.value == "{"){
        Token b2 = *lexer.gettoken();       
        next_token = *lexer.gettoken();
        if(next_token.value == "}"){
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

TreeNode* Tree::B2Half(int counter, Token b2 ) {
    return new B2ndHalfNode();

}

void Tree::calcWriteTab(int counter){
    for(int i = 0; i < counter; i++){
        myfile <<"\t";
    }
}
