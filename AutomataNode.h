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
    bool final;
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

    bool operator<( const AutomataNode& other ) const{
        return (number)<other.number;
    }

    void setFinal(bool bo){
        final = bo;
    }

    bool getFinal(){
        return final;
    }
};

class AutomataDfa{
private:
    AutomataNode* init;
    vector<AutomataNode*> fin;
public:
    AutomataDfa(AutomataNode* initial){
        init = initial;
    }

    void setInitAutomataNode(AutomataNode* node){
        init = node;
    }

    void addFinNode(AutomataNode* node){
        fin.push_back(node);
    }

    AutomataNode* getInitNode(){
        return init;
    }
    vector<AutomataNode*> getFinNode(){
        return fin;
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

    void setInitAutomataNode(AutomataNode* node){
        init = node;
    }

    void setFinalAutomataNode(AutomataNode* node){
        fin = node;
    }

    AutomataNode* getInitNode(){
        return init;
    }
    AutomataNode* getFinNode(){
        return fin;
    }

};

Automata* epsilonAut(AutomataNode *a, AutomataNode *b);
Automata* letterAut(AutomataNode* a, AutomataNode* b, char val);
Automata* orAut (Automata *a, Automata *b);
Automata *andAutomata (Automata *a, Automata *b);
Automata *kleenAutomata(Automata *a);

#endif //C_COMPILER_AUTOMATANODE_H