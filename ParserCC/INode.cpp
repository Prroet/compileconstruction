/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   INode.cpp
 * Author: vagrant
 * 
 * Created on 27. April 2016, 15:02
 */
#include <string>
#include "Tree.h"
#include "INode.h"

INode::INode(tokenType id) {
    id_ = id;
}

INode::INode(const INode& orig) {
}

INode::~INode() {
}

