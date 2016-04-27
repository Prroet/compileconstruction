/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   P2Node.h
 * Author: vagrant
 *
 * Created on 27. April 2016, 16:58
 */

#ifndef P2NODE_H
#define P2NODE_H
#include "TreeNode.h"

class P2Node : public TreeNode {
public:
    P2Node(TreeNode* f);
    P2Node(TreeNode* m, TreeNode* f);
    P2Node(const P2Node& orig);
    virtual ~P2Node();
private:

};

#endif /* P2NODE_H */

