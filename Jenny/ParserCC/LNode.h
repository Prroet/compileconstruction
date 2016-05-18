/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LNode.h
 * Author: vagrant
 *
 * Created on 18. Mai 2016, 11:51
 */

#ifndef LNODE_H
#define LNODE_H
#include <string>
#include "TreeNode.h"

class LNode : public TreeNode{
public:
    LNode(TreeNode* i);
    LNode(const LNode& orig);
    virtual ~LNode();
private:
    std::string plusOp;

};

#endif /* LNODE_H */

