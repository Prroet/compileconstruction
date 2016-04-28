/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   P2Node.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 16:58
 */

#include "P2Node.h"
#include "TreeNode.h"

P2Node::P2Node(TreeNode* f) {
    setFirstNode(f);
}

P2Node::P2Node(TreeNode* m, TreeNode* f) {
    setFirstNode(m);
    setSecondNode(f);
}


P2Node::P2Node(const P2Node& orig) {
}

P2Node::~P2Node() {
}

