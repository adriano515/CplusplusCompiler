//
// Created by Freddie on 9/16/2016.
//

#include "Nfa2Dfa.h"
#include "AutomataNode.h"
#include <vector>
#include <set>
#include "NFAsimulation.h"
#include <algorithm>

using namespace std;

Automata Nfa2Dfa(Automata* nfa, string language){
    Automata* dfa;

    int counter = 0;
    vector <set<AutomataNode*>> dTran;

    set <AutomataNode*> init;
    init.insert(nfa->getInitNode());

    dTran.push_back(eClosure(init));
    counter = counter + 1;
    int same = 0;
    for(int i = 0; i <counter ; i ++){
        for (int j = 0; j < language.size(); j ++){
            set<AutomataNode*> toFind = eClosure(move(dTran[i], language[j]));
            same =0;
            for (int k=0;k<dTran.size();k++){
                if(dTran[k]==toFind){
                    same = same+1;
                }
            }
            if (same ==0) {
                dTran.push_back(eClosure(move(dTran[i], language[j])));
                vector<set<AutomataNode *>> dTran2 = dTran;
            }
            if (!dTran[counter].empty()) {
                counter = counter + 1;
            }
        }
    }

}

