//
// Created by Freddie on 9/4/2016.
//

#include "NFAgenerator.h"
#include "AutomataNode.h"
#include "TreeNode.h"
#include "postfix.h"



Automata *nfaGen(TreeNode *current) {

    if(!isOperator(current->getValue())){
        AutomataNode* a = new AutomataNode();
        AutomataNode* b = new AutomataNode();
        current->setAutomata(letterAut(a,b,current->getValue()));
        return current->getAutomata();
    }
    else {
        if (current->getValue() == '*') {
            Automata *leftAutom = nfaGen(current->getLeft());
            Automata *rightAutom = nfaGen(current->getRight());
            current->setAutomata(andAutomata(leftAutom, rightAutom));
            return current->getAutomata();
        }

        if (current->getValue() == '^') {
            Automata *leftAutom = nfaGen(current->getLeft());
            current->setAutomata(kleenAutomata(leftAutom));
            return current->getAutomata();
        }
        if (current->getValue() == '|') {
            Automata *leftAutom = nfaGen(current->getLeft());
            Automata *rightAutom = nfaGen(current->getRight());
            current->setAutomata(orAut(leftAutom, rightAutom));
            return current->getAutomata();
        }
    }

    return current->getAutomata();

}
