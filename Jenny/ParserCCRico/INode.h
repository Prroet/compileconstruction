/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   INode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 15:02
 */

#ifndef INODE_H
#define INODE_H
#include "TreeNode.h"
#include <string>

typedef std::string tokenType;

class INode : public TreeNode {
public:
    INode(tokenType id);
    INode(const INode& orig);
    virtual ~INode();
private:
    tokenType id_;

};

#endif /* INODE_H */

