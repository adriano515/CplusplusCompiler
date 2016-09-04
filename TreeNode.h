//
// Created by Freddie on 8/29/2016.
//

#ifndef C_COMPILER_TREENODE_H
#define C_COMPILER_TREENODE_H


#include <stack>

struct TreeNode;

stack<TreeNode*> postfix2Tree(string postfix);

#endif //C_COMPILER_TREENODE_H
