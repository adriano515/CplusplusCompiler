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

Automata* automataEpsilon(AutomataNode* i, vector<AutomataNode*> f);
Automata *automataEpsilon(AutomataNode *i,AutomataNode *f);
Automata* automataLetter(AutomataNode* i, vector<AutomataNode*> f,string letter);
Automata *automataLetter(AutomataNode *i, AutomataNode *f, string letter);
Automata* automataOR(Automata *a, Automata *b);
Automata *automataAnd(Automata *a, Automata *b);
Automata *automataKleen(Automata *a);


#endif //C_COMPILER_AUTOMATANODE_H
