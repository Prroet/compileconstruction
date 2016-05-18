/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LNode.cpp
 * Author: vagrant
 * 
 * Created on 18. Mai 2016, 11:51
 */

#include "LNode.h"

LNode::LNode(TreeNode* i) {
    plusOp = "+";
    setFirstNode(i);
}

LNode::LNode(const LNode& orig) {
}

LNode::~LNode() {
}

