/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SNode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:02
 */

#include "SNode.h"
#include "TreeNode.h"

SNode::SNode(tokenType strLit) {
    string_literal = strLit;
}

SNode::SNode(const SNode& orig) {
}

SNode::~SNode() {
}

