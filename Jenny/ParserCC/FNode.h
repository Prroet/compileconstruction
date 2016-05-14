/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:02
 */

#ifndef FNODE_H
#define FNODE_H
#include "TreeNode.h"
#include "Token.h"
#include <string>

typedef Token tokenType;

class FNode : public TreeNode {
public:
    FNode(TreeNode* i, TreeNode* b);
    FNode(const FNode& orig);
    virtual ~FNode();
private:
    tokenType func;
    tokenType brac;

};

#endif /* FNODE_H */

