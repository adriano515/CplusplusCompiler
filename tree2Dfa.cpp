//
// Created by Freddie on 9/18/2016.
//

#include "tree2Dfa.h"

#include "postfix.h"
#include <algorithm>
#include "Transition.h"
#include <vector>

void nullable(TreeNode* t){
    if(isOperand(t->getValue())){
        t->setNullable(false);
    }
    else if(t->getValue()=='^'){
        nullable(t->getLeft());
        t->setNullable(true);
    }
    else if(t->getValue()=='|'){
        nullable(t->getRight());
        nullable(t->getLeft());
        bool right = t->getRight()->getNullable();
        bool left = t->getLeft()->getNullable();
        if (right == true || left == true){
            t->setNullable(true);
        }
        else{
            t->setNullable(false);
        }
    }

    else if(t->getValue()=='*'){
        nullable(t->getRight());
        nullable(t->getLeft());
        bool right = t->getRight()->getNullable();
        bool left = t->getLeft()->getNullable();
        if (right == true and left == true){
            t->setNullable(true);
        }
        else{
            t->setNullable(false);
        }
    }
}

void firstPos(TreeNode* t){
    if(isOperand(t->getValue())){
        t->setFirstPos(t);
    }
    else if(t->getValue()=='^'){
        firstPos(t->getLeft());
        t->setFirstPos(t->getLeft()->getFirstPos());
    }
    else if(t->getValue()=='|'){
        firstPos(t->getRight());
        firstPos(t->getLeft());
        set<TreeNode*> right = t->getRight()->getFirstPos();
        set<TreeNode*> left = t->getLeft()->getFirstPos();
        set<TreeNode*> temp;

        set_union(right.begin(),right.end(),left.begin(),left.end(),inserter(temp,temp.end()));
        t->setFirstPos(temp);


    }

    else if(t->getValue()=='*'){
        firstPos(t->getRight());
        firstPos(t->getLeft());
        set<TreeNode*> right = t->getRight()->getFirstPos();
        set<TreeNode*> left = t->getLeft()->getFirstPos();
        set<TreeNode*> temp;

        if(t->getLeft()->getNullable()){
            set_union(right.begin(),right.end(),left.begin(),left.end(),inserter(temp,temp.end()));
            t->setFirstPos(temp);
        }

        else{
            t->setFirstPos(t->getLeft()->getFirstPos());
        }

    }
}

void followPos(TreeNode* t) {
    if (isOperand(t->getValue())) {
        t->setFollowPos(nullptr);
    } else if (t->getValue() == '^') {
        followPos(t->getLeft());
        set<TreeNode*> t1 = t->getLeft()->getLastPos();
        for (set<TreeNode*>::iterator it2 = t1.begin(); it2 != t1.end(); it2++) {

            TreeNode *state = *it2;
            state->setFollowPos(t->getFirstPos());
        }
    } else if (t->getValue() == '|') {
        followPos(t->getLeft());
        followPos(t->getRight());
        t->setFollowPos(nullptr);
    } else if (t->getValue() == '*') {
        followPos(t->getLeft());
        followPos(t->getRight());
        set<TreeNode*> t1 = t->getLeft()->getLastPos();
        for (set<TreeNode*>::iterator it2 = t1.begin(); it2 != t1.end(); it2++) {
            TreeNode *state = *it2;
            state->setFollowPos(t->getRight()->getFirstPos());
        }
    }
}


void lastPos(TreeNode* t){
    if(isOperand(t->getValue())){
        t->setLastPos(t);
    }
    else if(t->getValue()=='^'){
        lastPos(t->getLeft());
        t->setLastPos(t->getLeft()->getLastPos());
    }
    else if(t->getValue()=='|'){
        lastPos(t->getRight());
        lastPos(t->getLeft());
        set<TreeNode*> right = t->getRight()->getLastPos();
        set<TreeNode*> left = t->getLeft()->getLastPos();
        set<TreeNode*> temp;

        set_union(right.begin(),right.end(),left.begin(),left.end(),inserter(temp,temp.end()));
        t->setLastPos(temp);
    }

    else if(t->getValue()=='*'){
        lastPos(t->getLeft());
        lastPos(t->getRight());
        set<TreeNode*> right = t->getRight()->getLastPos();
        set<TreeNode*> left = t->getLeft()->getLastPos();
        set<TreeNode*> temp;

        if(t->getRight()->getNullable()){
            set_union(right.begin(),right.end(),left.begin(),left.end(),inserter(temp,temp.end()));
            t->setLastPos(temp);
        }

        else{
            t->setLastPos(t->getRight()->getFirstPos());
        }

    }
}
