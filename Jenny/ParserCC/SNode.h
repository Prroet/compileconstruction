/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:02
 */

#ifndef SNODE_H
#define SNODE_H
#include "TreeNode.h"
#include "Token.h"
#include <string>

typedef Token tokenType;

class SNode : public TreeNode {
public:
    SNode(Token strLit);
    SNode(const SNode& orig);
    virtual ~SNode();
private:
    tokenType string_literal;

};

#endif /* SNODE_H */

