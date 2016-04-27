/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ANode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 14:47
 */

#include "PNode.h"
#include "ANode.h"

ANode::ANode() {
        
}

ANode::ANode(TreeNode* p, TreeNode* p2ndHalf){
    setFirstNode(p);
    setSecondNode(p2ndHalf);
}


ANode::ANode(const ANode& orig) {
}

ANode::~ANode() {
}

