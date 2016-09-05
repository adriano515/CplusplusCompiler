//
// Created by Freddie on 8/29/2016.
//

#ifndef C_COMPILER_TREENODE_H
#define C_COMPILER_TREENODE_H


#include <stack>
#include "string"
#include "AutomataNode.h"

class TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
    Automata* automata;

public:
    TreeNode(char elem){
        value = elem;
        left = nullptr;
        right  = nullptr;
    }

    void setRight(TreeNode* newRight){
        right = newRight;
    }

    void setLeft(TreeNode* newLeft){
        left = newLeft;
    }

    void setValue(char elem){
        value = elem;
    }

    void setAutomata(Automata* autom){
        automata= autom;
    }

    Automata* getAutomata(){
        return automata;
    }

    TreeNode* getLeft(){
        return left;
    }

    TreeNode* getRight(){
        return right;
    }
    char getValue(){
        return value;
    }

};

stack<TreeNode*> postfix2Tree(string postfix);

#endif //C_COMPILER_TREENODE_H
