//
// Created by Freddie on 8/29/2016.
//

#ifndef C_COMPILER_TREENODE_H
#define C_COMPILER_TREENODE_H


struct TreeNode;

void treeInsert(TreeNode *&root, char newItem);

void postorderPrint( TreeNode *root );

#endif //C_COMPILER_TREENODE_H
