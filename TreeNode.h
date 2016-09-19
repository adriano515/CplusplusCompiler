//
// Created by Freddie on 8/29/2016.
//

#ifndef C_COMPILER_TREENODE_H
#define C_COMPILER_TREENODE_H


#include <stack>
#include "string"
#include "AutomataNode.h"
#include <set>

class TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
    Automata* automata;
    set<TreeNode*> firstPos;
    set<TreeNode*> lastPos;
    bool nullable;
    set<TreeNode*> followPos;

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

    bool operator<( const TreeNode& other ) const{
        return (automata)<other.automata;
    }

    void setFirstPos(set<TreeNode*> t){
        firstPos = t;
    }

    void setLastPos(set<TreeNode*> t){
        lastPos = t;
    }

    void setFollowPos(set<TreeNode*> t){
        followPos=t;
    }

    void setFirstPos(TreeNode* t){
        firstPos.insert(t);
    }

    void setLastPos(TreeNode* t){
        lastPos.insert(t);
    }

    void setFollowPos(TreeNode* t){
        followPos.insert(t);
    }

    void setNullable(bool bo){
        nullable = bo;
    }

    set<TreeNode*> getFirstPos(){
        return firstPos;
    }

    set<TreeNode*> getLastPos(){
        return lastPos;
    }
    set<TreeNode*> getFollowPos(){
        return followPos;
    }
    bool getNullable(){
        return nullable;
    }

};

stack<TreeNode*> postfix2Tree(string postfix);

#endif //C_COMPILER_TREENODE_H
