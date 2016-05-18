/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ENode.cpp
 * Author: vagrant
 * 
 * Created on 18. Mai 2016, 11:51
 */

#include "ENode.h"

ENode::ENode(TreeNode* d, Token allOp) {
    setFirstNode(d);
    allocOperator = allOp.value;
}

ENode::ENode(const ENode& orig) {
}

ENode::~ENode() {
}

