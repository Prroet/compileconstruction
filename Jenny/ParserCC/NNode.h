/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NNode.h
 * Author: vagrant
 *
 * Created on 17. Mai 2016, 17:19
 */

#ifndef NNODE_H
#define NNODE_H
#include "TreeNode.h"

class NNode : public TreeNode {
public:
    NNode(TreeNode* i, TreeNode* e);
    NNode(const NNode& orig);
    virtual ~NNode();
private:

};

#endif /* NNODE_H */

