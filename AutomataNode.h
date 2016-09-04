//
// Created by Freddie on 9/4/2016.
//

#ifndef C_COMPILER_AUTOMATANODE_H
#define C_COMPILER_AUTOMATANODE_H

#include <vector>
#include <string>

using namespace std;

class Automata;
class AutomataNode;
class Transition;

Automata* epsilon(AutomataNode* i, vector<AutomataNode*> f);
Automata* letter(AutomataNode* i, vector<AutomataNode*> f,string letter);
AutomataNode *automataOR(Automata *a, Automata *b);


#endif //C_COMPILER_AUTOMATANODE_H
