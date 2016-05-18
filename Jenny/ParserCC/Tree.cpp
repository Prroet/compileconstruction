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
#include "NNode.h"
#include "ENode.h"
#include "DNode.h"
#include "LNode.h"

Tree::Tree(std::string codefile): lexer(codefile) {
    Root = nullptr;
    epsilon = false;
    //In dieser Datei steht dann der AST-Baum
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

TreeNode* Tree::A(int tabCounter){//counter ist für die Anzahl der Tabulatoren die in die Datei ast.txt gesschrieben werden um eine Baumstruktur darzustellen
    writeInASTfile(tabCounter, "Root(A->P P2)->");
    tabCounter++;
    return new ANode( P(tabCounter), P2ndHalf(tabCounter) );
    
}

TreeNode* Tree::P(int tabCounter){//muss man einen PNode erstellen und an ANode anhängen oder darf man direkt das INode anhängen
    next_token = saveGetToken();
    if((next_token.type == static_cast<int>(TokenType::keyword))&& (next_token.value == "package")){
        Token id = saveGetToken();
        if((next_token = saveGetToken()).value == ";"){
            writeInASTfile(tabCounter, "P(\"package\" I ;)->");
            tabCounter++;
            return new PNode( I(tabCounter, id) );
        }else{
            std::cout << next_token.lineNumber <<": Delimiter \";\" fehlt" << std::endl;
        }
    } 
    std::cout << next_token.lineNumber << ": Keyword \"package\" fehlt" << std::endl;
    return nullptr; 
    
}

TreeNode* Tree::P2ndHalf(int tabCounter) {
    next_token = saveGetToken();
    if(next_token.value == "func" ) {
        writeInASTfile(tabCounter, "P2(\"func\")->");
        tabCounter++;
        return new P2Node( F(tabCounter) );
    }
    else if(next_token.value == "import" ){
        writeInASTfile(tabCounter, "P2(\"import\")->");
        tabCounter++;
        Token strLit = next_token = saveGetToken();
        
        //Ist Deliminator da?
        if((next_token = saveGetToken()).value != ";"){std::cout << next_token.lineNumber << ": kein \";\""<< std::endl;}
        
        //nach F() Gültigkeit abfragen
        next_token = saveGetToken();
        if(next_token.value == "func"){
            return new P2Node( M(tabCounter, strLit), F(tabCounter) );
        }
    }else{
        std::cout << next_token.lineNumber << ": keine der beiden Keywords func or import" << std::endl;
        return nullptr;
    }
}

TreeNode* Tree::I(int tabCounter, Token id) {
    if(id.type != static_cast<int>(TokenType::identifier)){
        std::cout << next_token.lineNumber << ": "<< id.value << " ist nicht vom Tokentyp identifier" << std::endl;
        return nullptr;
    }
    else{
        //In datei schreiben
        calcWriteTab(tabCounter);
        myfile << "I(id= "<< id.value <<")\n";
        myfile.flush();
        
        tabCounter++;
        return new INode(id);
    }
}

TreeNode* Tree::M(int tabCounter, Token strLit) {
    writeInASTfile(tabCounter, "M()->");   
    tabCounter++;
    return new MNode( S(tabCounter, strLit) );
}

TreeNode* Tree::S(int tabCounter, Token strLit) {
    calcWriteTab(tabCounter);   
    myfile << "S(" << strLit.value << ")->\n";
    return new SNode(strLit);
}

TreeNode* Tree::F(int tabCounter) {
    Token id = saveGetToken();
    next_token = saveGetToken();
    if(next_token.value == "("){
        next_token = saveGetToken();
        if(next_token.value == ")"){
            writeInASTfile(tabCounter, "F( \"()\" )->");   
            tabCounter++;
            return new FNode( I(tabCounter, id), B(tabCounter) );
        }
    }
    std::cout << next_token.lineNumber << ": kein \"(\"" << std::endl;
    return nullptr;
}

TreeNode* Tree::B(int tabCounter) {
    next_token = saveGetToken();
    if(next_token.value == "{"){
        Token b2 = saveGetToken(); 
        //sind die {} leer?
        if(b2.value == "}"){
            epsilon =true;
        }
        else{
            std::cout << (next_token.lineNumber +1) << ": die {} ist NICHT leer" << std::endl;
            //tokenBUffer füllen, alles zwischen {}
            tokenBuffer.push_back(b2);
            while((next_token = saveGetToken()).value != "}"){
                tokenBuffer.push_back(next_token);
            }
            //nur zum testen:
            for(Token element : tokenBuffer){
               std::cout<< element.value << std::endl; 
            }
        }
        //egal ob leer oder nicht
        if (next_token.value == "}"){
            writeInASTfile(tabCounter, "B( \"{ N B oder Epsilon }\")->");   
            tabCounter++;
            return new BNode( B2Half( tabCounter) );
        }else{
            std::cout << next_token.lineNumber << ": keine \"}\"" << std::endl;
            return nullptr;
        }
    }
    std::cout << next_token.lineNumber << ": keine \"{\"" << std::endl;
    return nullptr;

}

TreeNode* Tree::B2Half(int tabCounter) {
    calcWriteTab(tabCounter);
    myfile << "B2ndHalf(N B2ndHalf)->\n";
    tabCounter++;
    if(epsilon){
        return new B2ndHalfNode();
    }
    return new B2ndHalfNode(N(tabCounter), B2Half(tabCounter));

}

void Tree::calcWriteTab(int tabCounter){
    for(int i = 0; i < tabCounter; i++){
        myfile <<"\t";
    }
}

Token Tree::saveGetToken(){
   Token* tok = lexer.gettoken();
   if(tok != nullptr){
       return *tok;
   }
   std::cout<< "Kein Token mehr im Lexer: lexer.gettoken() == nullptr" << std::endl;
}

bool Tree::writeInASTfile(int tabCounter, std::string branch){
    calcWriteTab(tabCounter);
    myfile << branch << "\n";
    myfile.flush();
}

TreeNode* Tree::N(int tabCounter){
    //hier wird nur noch mit dem tokenBuffer gearbeitet, nicht mit dem Lexer;
    Token id = getTokenFromBuffer();
    next_token = getTokenFromBuffer();
    if(next_token.type != -1){//-1 = TokenBuffer ist leer
        if(next_token.value == ":=" || next_token.value == "="  ){
            writeInASTfile(tabCounter, "N( I E )->");
            tabCounter++;
            return new NNode( I(tabCounter, id), E(tabCounter, next_token));
        }
        std::cout << next_token.lineNumber << ": Kein := oder =" <<std::endl;
    }//Epsilon
    epsilon = true; //für B2ndHalf
    std::cout << "TokenBuffer ist leer => Epsilon" << std::endl;
    return nullptr;
}

TreeNode* Tree::E(int tabCounter, Token allocOp){
    next_token = getTokenFromBuffer();
    //ist es ein Numberliteral oder id?
    if(next_token.literalType == static_cast<int>(LiteralType::intLiteral) || 
            next_token.literalType == static_cast<int>(LiteralType::floatLiteral) ||
            next_token.type == static_cast<int>(TokenType::identifier)){
        Token idOrNumLit = next_token;
        
        writeInASTfile(tabCounter, "E(:= oder =)->");
        tabCounter++;
        return new ENode(D(tabCounter, idOrNumLit), allocOp) ;
    }        
    return nullptr;
}

TreeNode* Tree::D(int tabCounter, Token idOrNumLit){
    if(idOrNumLit.literalType == static_cast<int>(LiteralType::intLiteral) || 
            idOrNumLit.literalType == static_cast<int>(LiteralType::floatLiteral)){
        //in Datei schreiben
        calcWriteTab(tabCounter);
        myfile << "D( numLiteral = "<< idOrNumLit.value << " )->\n";
        myfile.flush();
        
        //; wegschmeisen
        next_token = getTokenFromBuffer();
        if(next_token.type != static_cast<int>(TokenType::operatorDelimiter) && next_token.value != ";"){
            std::cout << "Kein ; nach dem := D in D" << std::endl;
        }
               
        return new DNode(idOrNumLit);
    }//dann isses IL
    
    writeInASTfile(tabCounter, "D(I L)->");
    tabCounter++;
    return new DNode(I(tabCounter, idOrNumLit), L(tabCounter));
}

TreeNode* Tree::L(int tabCounter){//!!!
    next_token = getTokenFromBuffer();
    //ist es + id?
    if(next_token.value == "+" && next_token.type != (-1)){//tokenBuffer ist nicht leer
        next_token = getTokenFromBuffer();
        if(next_token.type == static_cast<int>(TokenType::identifier)){
            Token id = next_token;            
            //; wegschmeisen
            next_token = getTokenFromBuffer();
            if(next_token.type != static_cast<int>(TokenType::operatorDelimiter) && next_token.value != ";"){
                std::cout << "Kein ; nach dem := D in L" << std::endl;
            }
            
            writeInASTfile(tabCounter, "L(\"+\" I )->");
            tabCounter++;
            return new LNode(I(tabCounter, id));
        }
        std::cout << "Nach dem \"+\" kommt KEINE id" << std::endl;
    }//also Epsilon bzw. kein "+" oder id
    return nullptr;
}

//get first Token from Buffer and deletes it
Token Tree::getTokenFromBuffer(){
    Token tok;
    tok.type = -1;//um abfragen zu können ob der TokenBuffer leer ist
    if(tokenBuffer.size() != 0){
        tok = tokenBuffer.front();//erstes Zeichen auslesen
        tokenBuffer.pop_front();
    }
//    Token test = tokenBuffer.front();
//    std::cout << "1. Token in Buffer: " << test.value << std::endl;
//    std::cout << "Tok: " << tok.value << std::endl;
    return tok;
}