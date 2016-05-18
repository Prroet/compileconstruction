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
#include <vector>


class Tree {
public:
    Tree(std::string codefile);
    Tree(const Tree& orig);
    virtual ~Tree();
    
protected:    
    void buildTree();
    
private:
    TreeNode* A(int tabCounter);
    TreeNode* P(int tabCounter);
    TreeNode* P2ndHalf(int tabCounter);
    TreeNode* I(int tabCounter, Token id);
    TreeNode* M(int tabCounter, Token strLit);
    TreeNode* S(int tabCounter, Token strLit);
    TreeNode* F(int tabCounter);
    TreeNode* B(int tabCounter);
    TreeNode* B2Half(int tabCounter);
    void calcWriteTab(int tabCounter);
    Token saveGetToken();
    bool writeInASTfile(int tabCounter, std::string branch);
    TreeNode* N(int tabCounter);
    TreeNode* E(int tabcounter);
    TreeNode* D(int tabCounter);
    TreeNode* L(int tabcounter);
    
    Lexer lexer;
    Token next_token;
    TreeNode* Root;
    std::ofstream myfile;
    std::vector<Token> tokenBuffer;
    bool epsilon;
};

#endif /* TREE_H */

