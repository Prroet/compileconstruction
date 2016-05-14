/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:03
 */

#ifndef BNODE_H
#define BNODE_H
#include "TreeNode.h"
#include "Token.h"
#include <string>

typedef Token tokenType;

class BNode : public TreeNode {
public:
    BNode(TreeNode* b2);
    BNode(const BNode& orig);
    virtual ~BNode();
private:
    tokenType braceOpen;
    tokenType braceClose;

};

#endif /* BNODE_H */

