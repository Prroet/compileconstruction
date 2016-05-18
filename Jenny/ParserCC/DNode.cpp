/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNode.cpp
 * Author: vagrant
 * 
 * Created on 18. Mai 2016, 11:51
 */

#include "DNode.h"

DNode::DNode(Token numLiteral) {
    numLit = numLiteral.value;
}

DNode::DNode(TreeNode* id, TreeNode* l){
    numLit = "keins";
    setFirstNode(id);
    setSecondNode(l);
}

DNode::DNode(const DNode& orig) {
}

DNode::~DNode() {
}

