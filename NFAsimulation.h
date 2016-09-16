//
// Created by Freddie on 9/14/2016.
//

#ifndef C_COMPILER_NFASIMULATION_H
#define C_COMPILER_NFASIMULATION_H

#include "AutomataNode.h"
#include <set>
#include "NFAgenerator.h"

using namespace std;

set<AutomataNode*> eClosure(AutomataNode* s);

set<AutomataNode*> eClosure(set<AutomataNode*> s);
set<AutomataNode*> move(set<AutomataNode*> s, char c);
bool nfaSimulation(string text,Automata* a);
#endif //C_COMPILER_NFASIMULATION_H
