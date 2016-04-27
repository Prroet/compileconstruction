/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:02
 */

#ifndef PNODE_H
#define PNODE_H
#include "TreeNode.h"
#include <string>

typedef std::string tokenType;

class PNode: public TreeNode {
public:
    PNode(TreeNode* i);
    PNode(const PNode& orig);
    virtual ~PNode();
private:
    tokenType package;
    tokenType semicolon;

};

#endif /* PNODE_H */

