/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 14:44
 */

#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"
#include "Lexer.h"
#include "Token.h"
#include <string>
#include <fstream>

typedef Token tokenType;

class Tree {
public:
    Tree(Lexer &lexer);
    Tree(const Tree& orig);
    virtual ~Tree();
    
protected:    
    void buildTree();
    
private:
    TreeNode* A(int counter);
    TreeNode* P(int counter);
    TreeNode* P2ndHalf(int counter);
    TreeNode* I(int counter, tokenType id);
    TreeNode* M(int counter);
    TreeNode* S(int counter);
    TreeNode* F(int counter);
    TreeNode* B(int counter);
    TreeNode* B2Half(int counter, tokenType b2);
    void calcWriteTab(int counter);
    
    Lexer lexer;
    tokenType next_token;
    TreeNode* Root;
    std::ofstream myfile;
    
};

#endif /* TREE_H */

