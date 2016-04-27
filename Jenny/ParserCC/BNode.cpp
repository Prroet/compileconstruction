/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BNode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:03
 */

#include "BNode.h"
#include "TreeNode.h"

BNode::BNode(TreeNode* b2) {
    braceOpen = "{";
    setFirstNode(b2);
    braceClose = "}";
}

BNode::BNode(const BNode& orig) {
}

BNode::~BNode() {
}

