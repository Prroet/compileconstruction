/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 14:45
 */

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    TreeNode();
    TreeNode(const TreeNode& orig);
    virtual ~TreeNode();
    
    void setFirstNode(TreeNode* node){firstNode = node;}
    void setSecondNode(TreeNode* node){secondNode = node;}
    void setThirdNode(TreeNode* node){thirdNode = node;}
    TreeNode* getFirstNode(){return firstNode;}
    TreeNode* getSecondNode(){return secondNode;}
    TreeNode* getThirdNode(){return thirdNode;}
    
private: 
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* thirdNode;

};

#endif /* TREENODE_H */

