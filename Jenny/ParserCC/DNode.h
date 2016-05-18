/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNode.h
 * Author: vagrant
 *
 * Created on 18. Mai 2016, 11:51
 */

#ifndef DNODE_H
#define DNODE_H
#include <string>
#include "TreeNode.h"

class DNode : public TreeNode {
public:
    DNode(Token numLiteral);
    DNode(TreeNode* id, TreeNode* l);
    DNode(const DNode& orig);
    virtual ~DNode();
private:
    std::string numLit;

};

#endif /* DNODE_H */

