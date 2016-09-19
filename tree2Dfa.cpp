//
// Created by Freddie on 9/18/2016.
//

#include "tree2Dfa.h"

#include "postfix.h"
#include <algorithm>
#include "Transition.h"

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

AutomataDfa* tree2Dfa(TreeNode* t,string language) {
    set<TreeNode *> t1 = t->getFirstPos();
    set<TreeNode *> t2 = t->getLastPos();

    int counter = 0;
    int same = 0;
    vector<set<TreeNode *>> finalSet;
    vector<AutomataNode *> nodes;
    finalSet.push_back(t1);
    AutomataNode* A = new AutomataNode;
    A->setNumber(0);
    nodes.push_back(A);
    AutomataDfa* dfa = new AutomataDfa(A);
    counter = counter + 1;

    for (int i = 0; i < counter; i++) { //for each new set
        for (int k = 0; k < language.size(); k++) {//for each posible input
            vector<TreeNode *> temp;//vector containing nodes wich came from the same input
            set<TreeNode *> tempSet; //set of the union of followpos of temp

            for (set<TreeNode *>::iterator it2 = t1.begin(); it2 != t1.end(); it2++) {//for each node in firstpos
                TreeNode *state = *it2;
                if (state->getValue() == language[k]) {//if its the same language
                    temp.push_back(state);
                }
            }

                for (int w = 0; temp.size(); w++) {
                    set<TreeNode*> temp3 = temp[w]->getFollowPos();
                    tempSet.insert(temp3.begin(),temp3.end());
                }
                same = 0;
                for (int l = 0; l < finalSet.size(); l++) {
                    if (finalSet[l] == tempSet) {
                        same = same + 1;
                        Transition* tran = new Transition(language[k], nodes[l]); //adding transitions to nodes already in the dfa
                        nodes[i]->addTransition(tran);


                    }
                }

                if (same == 0) { //is new set
                    AutomataNode *A = new AutomataNode;
                    A->setNumber(counter);
                    Transition *tran = new Transition(language[k], A);
                    nodes[i]->addTransition(tran);
                    nodes.push_back(A);
                    nodes[nodes.size() - 1]->setFinal(false);
                    for (set<TreeNode *>::iterator it3 = tempSet.begin(); it3 != tempSet.end(); it3++) {
                        TreeNode *state2 = *it3;
                        for (set<TreeNode *>::iterator it4 = t2.begin(); it4 != t2.end(); it4++) {
                            TreeNode *state3 = *it4;
                            if (state2 == state3) {
                                nodes[nodes.size() - 1]->setFinal(true);
                                dfa->addFinNode(nodes[nodes.size()-1]);
                            }
                        }
                    }

                }

                finalSet.push_back(tempSet);
                counter = counter + 1; // new node was made

            }
        }

    dfa->setInitAutomataNode(nodes[0]);
    return dfa;
}