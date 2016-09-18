//
// Created by Freddie on 9/16/2016.
//

#include "Nfa2Dfa.h"
#include <set>
#include "Simulation.h"
#include <algorithm>

using namespace std;

AutomataDfa* Nfa2Dfa(Automata* nfa, string language){
    //counter for amount of new sets on DFA
    int counter = 0;
    //contains the sets of each node on DFA
    vector <set<AutomataNode*>> dTran;
    //vector for dfa nodes
    vector<AutomataNode*> nodes;
    //initial node on dfa
    set <AutomataNode*> init;
    init.insert(nfa->getInitNode());

    dTran.push_back(eClosure(init));

    AutomataNode* A = new AutomataNode;
    A->setNumber(0);
    nodes.push_back(A);
    AutomataDfa* dfa = new AutomataDfa(A);
    counter = counter + 1;
    //int for comparing if a set of nodes has been added to the dfa
    int same = 0;
    for(int i = 0; i <counter ; i ++){//for on amount of new Nodes on nfa( changes dynamically)
        for (int j = 0; j < language.size(); j ++){//for on amount of posibble letter transitions

            set<AutomataNode*> toFind = eClosure(move(dTran[i], language[j]));//sets

            same =0;
            for (int k=0;k<dTran.size();k++){
                if(dTran[k]==toFind){
                    same = same+1;
                    Transition* t = new Transition(language[j], nodes[k]); //adding transitions to nodes already in the dfa
                    nodes[i]->addTransition(t);
                }
            }
            if (same ==0) { //is new set

                AutomataNode* A = new AutomataNode;
                A->setNumber(counter);
                Transition* t = new Transition(language[j], A);
                nodes[i]->addTransition(t);
                nodes.push_back(A);
                nodes[nodes.size() - 1]->setFinal(false);

                for(set<AutomataNode *>::iterator it2 = toFind.begin(); it2 != toFind.end(); it2++){ //iterates the set to check if a node in it was final on nfa
                    AutomataNode *state = *it2;
                    if(state->getTransition().empty()==1){
                        nodes[nodes.size() - 1]->setFinal(true);
                        dfa->addFinNode(nodes[nodes.size()-1]);
                    }
                }

                dTran.push_back(eClosure(move(dTran[i], language[j])));
                counter = counter + 1; // new node was made

            }

        }
    }

    dfa->setInitAutomataNode(nodes[0]);
    return dfa;
}