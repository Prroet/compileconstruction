/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ANode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 14:47
 */

#ifndef ANODE_H
#define ANODE_H
#include "TreeNode.h"

class ANode: public TreeNode {
public:
    ANode();
    ANode(TreeNode* p, TreeNode* p2ndHalf);
    ANode(const ANode& orig);
    virtual ~ANode();
private:

};

#endif /* ANODE_H */

