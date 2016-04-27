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
    
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
}

void Tree::buildTree() {
   TreeNode* Root = A();
    
}

TreeNode* Tree::A(){
    return new ANode( P(), P2ndHalf() );
    
}

TreeNode* Tree::P(){//muss man einen PNode erstellen und an ANode anhängen oder darf man direkt das INode anhängen
    next_token = gettok();//müsste package drin stehen
    if(next_token == "package"){
        tokenType id = Tree::gettok();
        next_token = gettok();
        if(next_token == ";")
            return new PNode( I(id) );
        else{
            std::cout << "Delimiter \";\" fehlt" << std::endl;
        }
    } 
    std::cout << "Keyword \"package\" fehlt" << std::endl;
    return nullptr; 
    
}

TreeNode* Tree::P2ndHalf() {
    next_token = gettok();
    if(next_token == "func" ) {
        return new P2Node( F() );
    }
    else if(next_token == "import" ){
        return new P2Node( M(), F() );
    }else{
        std::cout << "keine der beiden Keywords func or import" << std::endl;
        return nullptr;
    }
}

TreeNode* Tree::I(tokenType id) {
    return new INode(id);
}

TreeNode* Tree::M() {
    next_token = gettok();
    return new MNode( S() );
}

TreeNode* Tree::S() {   
    return new SNode(next_token);
}

TreeNode* Tree::F() {
    tokenType id = gettok();
    next_token = gettok();
    if(next_token == "()"){
        next_token = gettok();
        return new FNode( I(id), B() );
    }
    else{
        std::cout << "kein \"()\"" << std::endl;
        return nullptr;
    }

}

TreeNode* Tree::B() {
    next_token = gettok();
    if(next_token == "{"){
        tokenType b2 = gettok();       
        next_token = gettok();
        if(next_token == "}"){
            return new BNode( B2Half( b2 ) );
        }else{
            std::cout << "keine \"}\"" << std::endl;
            return nullptr;
        }
    }
    std::cout << "keine \"{\"" << std::endl;
    return nullptr;

}

TreeNode* Tree::B2Half( tokenType b2 ) {
    return new B2ndHalfNode();

}




tokenType Tree::gettok() {
//eigentlich ist das eine Funktion die der Lexer  zu verfügung stellen muss
}

