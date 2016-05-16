/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MNode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:02
 */

#include "MNode.h"
#include "TreeNode.h"

MNode::MNode(TreeNode* s) {
    import.value = "import";
    setFirstNode(s);
}

MNode::MNode(const MNode& orig) {
}

MNode::~MNode() {
}

