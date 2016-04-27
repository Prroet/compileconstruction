/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FNode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:02
 */

#include "FNode.h"
#include "TreeNode.h"

FNode::FNode(TreeNode* i, TreeNode* b) {
    func = "func";
    setFirstNode(i);
    brac = "()";
    setSecondNode(b);
}

FNode::FNode(const FNode& orig) {
}

FNode::~FNode() {
}

