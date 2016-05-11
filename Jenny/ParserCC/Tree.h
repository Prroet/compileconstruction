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
#include <string>

typedef std::string tokenType;

class Tree {
public:
    Tree();
    Tree(const Tree& orig);
    virtual ~Tree();
    
protected:    
    void buildTree();
    TreeNode* A();
    TreeNode* P();
    TreeNode* P2ndHalf();
    TreeNode* I(tokenType id);
    TreeNode* M();
    TreeNode* S();
    TreeNode* F();
    TreeNode* B();
    TreeNode* B2Half(tokenType b2);
    
    tokenType gettok();
private:
    tokenType next_token;

};

#endif /* TREE_H */

