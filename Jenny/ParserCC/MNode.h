/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:02
 */

#ifndef MNODE_H
#define MNODE_H
#include "TreeNode.h"
#include "Token.h"
#include <string>

typedef Token tokenType;

class MNode : public TreeNode {
public:
    MNode(TreeNode* s);
    MNode(const MNode& orig);
    virtual ~MNode();
private:    
    tokenType import;
};

#endif /* MNODE_H */

