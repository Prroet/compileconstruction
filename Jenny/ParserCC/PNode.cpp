/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PNode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:02
 */
#include "INode.h"
#include "TreeNode.h"
#include "PNode.h"

PNode::PNode(TreeNode* i) {
    package = "package";
    setFirstNode(i);
    semicolon = ";";
    
}

PNode::PNode(const PNode& orig) {
}

PNode::~PNode() {
}

