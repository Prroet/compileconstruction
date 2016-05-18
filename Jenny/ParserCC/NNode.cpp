/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NNode.cpp
 * Author: vagrant
 * 
 * Created on 17. Mai 2016, 17:19
 */

#include "NNode.h"

NNode::NNode(TreeNode* i, TreeNode* e) {
    setFirstNode(i);
    setSecondNode(e);
}

NNode::NNode(const NNode& orig) {
}

NNode::~NNode() {
}

