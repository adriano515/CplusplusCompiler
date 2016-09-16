
#include "NFAsimulation.h"
#include <array>
#include <stack>
#include "AutomataNode.h"
#include <set>
#include <string>
#include <algorithm>

using namespace std;


set<AutomataNode*> nodeSet; //global variable for the NFAset on e-closure of single nodes (is cleared on eClosure of sets)

set<AutomataNode*> nodeSet2;// global variable for the NFAset on e-closure for a set of NFAnodes (is cleared on eClosure of sets)


//set of NFA states reachable from NFA state s on epsilon-transitions alone
set<AutomataNode*> eClosure(AutomataNode* s){

    int i = s->getTransition().size();
    while(!i==0){
        if(s->getTransition()[i-1]->getValue()=='e'){
            eClosure(s->getTransition()[i-1]->getNextNode());
            }
        i = i -1;
    }

    nodeSet.insert(s);

    return nodeSet;

}

set<AutomataNode*> eClosure(set<AutomataNode*> s) {


    for (set<AutomataNode *>::iterator i = s.begin(); i != s.end(); i++) {
        AutomataNode *state = *i;
        nodeSet.clear();
        set<AutomataNode*> newSet= eClosure(state);

        for (set<AutomataNode *>::iterator it2 = newSet.begin(); it2 != newSet.end(); it2++) {
            AutomataNode *state2 = *it2;
            nodeSet2.insert(state2);
        }
    }

    set<AutomataNode*> nodeSet3 = nodeSet2; //Clearing global values so we can use the method again without having the previous values
    nodeSet2.clear();
    return nodeSet3;
}

set<AutomataNode*> move(set<AutomataNode*> s, char c){
    set<AutomataNode*> nodeSet3;
    for (set<AutomataNode *>::iterator it2 = s.begin(); it2 != s.end(); it2++) {
        AutomataNode *state = *it2;
        for(int i=0;i<state->getTransition().size();i++){
            if(state->getTransition()[i]->getValue()==c){
                nodeSet3.insert(state->getTransition()[i]->getNextNode());
            }
        }
    }

    return nodeSet3;
}
bool nfaSimulation(string text,Automata* a) {
    set<AutomataNode*> final;
    final.insert(a->getFinNode());

    set<AutomataNode *> set2 = eClosure(a->getInitNode());
    set<AutomataNode *> set3;

    for (int i = 0; i < text.size(); i++) {
        set3 = move(set2, text[i]);
        set2 = eClosure(set3);
    }
    set<AutomataNode*> intersect;
    set_intersection(set2.begin(),set2.end(),final.begin(),final.end(),inserter(intersect,intersect.begin()));

    if (intersect.empty()){
        return false;
    }
    return true;
}
