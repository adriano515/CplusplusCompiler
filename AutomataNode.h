//
// Created by Freddie on 9/4/2016.
//

#ifndef C_COMPILER_AUTOMATANODE_H
#define C_COMPILER_AUTOMATANODE_H

#include <vector>

#include <iostream>
#include "Transition.h"

using namespace std;

class Transition;

class AutomataNode{
private:
    vector<Transition*> transitions;
    int number;
public:
    vector<Transition*> getTransition(){
        return transitions;
    }

    void addTransition(Transition* t){
        transitions.push_back(t);
    }

    void setNumber(int num){
        number = num;
    }

    int getNumber(){
        return number;
    }
};

class Automata{
private:
    AutomataNode* init;
    AutomataNode* fin;
public:
    Automata(AutomataNode* initial, AutomataNode* final){
        init = initial;
        fin = final;
    }

    AutomataNode* getInitNode(){
        return init;
    }
    AutomataNode* getFinNode(){
        return fin;
    }

};

Automata* epsilonAut(AutomataNode *a,AutomataNode *b);
Automata* letterAut(AutomataNode* a,AutomataNode* b, char val);
Automata* orAut (Automata *a,Automata *b);
Automata *andAutomata (Automata *a, Automata *b);
Automata *kleenAutomata(Automata *a);

#endif //C_COMPILER_AUTOMATANODE_H
