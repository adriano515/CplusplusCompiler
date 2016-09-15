
#include "NFAsimulation.h"
#include <array>
#include <stack>
#include "AutomataNode.h"
#include <set>

using namespace std;

set<AutomataNode*> nodes;
//set of NFA states reachable from NFA state s on epsilon-transitions alone
set<AutomataNode*> eClosure(AutomataNode* s){

    int i = s->getTransition().size();
    while(!i==0){
        if(s->getTransition()[i-1]->getValue()=='e'){
            eClosure(s->getTransition()[i-1]->getNextNode());
            }
        i = i -1;
    }
    nodes.insert(s);
    return nodes;

}

bool nfaSimulation(int size) {

    stack<AutomataNode *> oldStates; //current set of states
    stack<AutomataNode *> newStates; //next set of states
    bool alreadyOn[size] = {false};
    AutomataNode *move[1][1] = {};


}