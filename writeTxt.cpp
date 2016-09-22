//
// Created by Freddie on 9/21/2016.
//

#include <iostream>
#include <fstream>
#include "writeTxt.h"
#include "AutomataNode.h"
#include "Transition.h"
#include <set>

set<AutomataNode*> nodes;
string states = "Estados = {";
string transitions = "Transiciones = {";

void moves(AutomataNode* a) {
    bool is_in = nodes.find(a) != nodes.end();
    if (!is_in) {
        nodes.insert(a);
        vector<Transition *> t = a->getTransition();
        for (int i = 0; i < t.size(); i++) {
            transitions +=
                    to_string(a->getNumber()) + t[i]->getValue() + "->" + to_string(t[i]->getNextNode()->getNumber()) +
                    ",";
            moves(a->getTransition()[i]->getNextNode());
        }
    }
}

void nfaWriter(Automata* a,string language){


    string sym = "Simbolos = {";
    string init = "Inicio = {";
    string end = "Aceptacion = {";

    ofstream file;
    file.open ("C:/Users/Freddie/ClionProjects/C++Compiler/nfa.txt");

    init += to_string(a->getInitNode()->getNumber());
    end += to_string(a->getFinNode()->getNumber());

    for(int i =0;i<language.size();i++){
        sym += (language[i]);
    }
    moves(a->getInitNode());

    for (set<AutomataNode *>::iterator it3 = nodes.begin(); it3 != nodes.end(); it3++) {
        AutomataNode *state2 = *it3;
        states += to_string(state2->getNumber())+",";
    }

    states += "}";
    sym += "}";
    init += "}";
    end += "}";
    transitions += "}";


    file<<states<< endl <<sym<<endl<<init<<endl<<end<<endl<<transitions<<endl;
    file.close();

    nodes.clear();
    transitions.clear();
    states.clear();
    states = "Estados = {";
    transitions = "Transiciones = {";

}


void dfaWriter(AutomataDfa* a,string language){


    string sym = "Simbolos = {";
    string init = "Inicio = {";
    string end = "Aceptacion = {";

    ofstream file;
    file.open ("C:/Users/Freddie/ClionProjects/C++Compiler/dfa.txt");

    init += to_string(a->getInitNode()->getNumber());
    for (int i=0;i<a->getFinNode().size();i++){
        end += to_string(a->getFinNode()[i]->getNumber());
    }

    for(int i =0;i<language.size();i++){
        sym += (language[i]);
    }
    moves(a->getInitNode());

    for (set<AutomataNode *>::iterator it3 = nodes.begin(); it3 != nodes.end(); it3++) {
        AutomataNode *state2 = *it3;
        states += to_string(state2->getNumber())+",";
    }

    states += "}";
    sym += "}";
    init += "}";
    end += "}";
    transitions += "}";


    file<<states<< endl <<sym<<endl<<init<<endl<<end<<endl<<transitions<<endl;
    file.close();

    nodes.clear();
    transitions.clear();
    states.clear();

}
