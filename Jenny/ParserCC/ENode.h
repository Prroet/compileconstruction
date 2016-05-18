/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ENode.h
 * Author: vagrant
 *
 * Created on 18. Mai 2016, 11:51
 */

#ifndef ENODE_H
#define ENODE_H
#include <string>
#include "TreeNode.h"

class ENode : public TreeNode{
public:
    ENode(TreeNode* d, Token allocOp);
    ENode(const ENode& orig);
    virtual ~ENode();
private:
    std::string allocOperator;

};

#endif /* ENODE_H */

