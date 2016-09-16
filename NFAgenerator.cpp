//
// Created by Freddie on 9/4/2016.
//

#include "NFAgenerator.h"
#include "postfix.h"

Automata *nfaGen(TreeNode *current, int *counter) {

    if(!isOperator(current->getValue())){
        AutomataNode* a = new AutomataNode();
        AutomataNode* b = new AutomataNode();


        a->setNumber(*counter);
        *counter = *counter + 1;
        b->setNumber(*counter);
        *counter = *counter + 1;

        current->setAutomata(letterAut(a, b, current->getValue()));
        return current->getAutomata();
    }
    else {
        if (current->getValue() == '*') {
            Automata *leftAutom = nfaGen(current->getLeft(),counter);
            Automata *rightAutom = nfaGen(current->getRight(),counter);
            current->setAutomata(andAutomata(leftAutom, rightAutom));
            return current->getAutomata();
        }

        if (current->getValue() == '^') {
            Automata *leftAutom = nfaGen(current->getLeft(),counter);
            current->setAutomata(kleenAutomata(leftAutom));


            current->getAutomata()->getInitNode()->setNumber(*counter);
            *counter = *counter + 1;
            current->getAutomata()->getFinNode()->setNumber(*counter);
            *counter = *counter + 1;

            return current->getAutomata();
        }
        if (current->getValue() == '|') {
            Automata *leftAutom = nfaGen(current->getLeft(), counter);
            Automata *rightAutom = nfaGen(current->getRight(), counter);
            current->setAutomata(orAut(leftAutom, rightAutom));

            current->getAutomata()->getInitNode()->setNumber(*counter);
            *counter = *counter + 1;
            current->getAutomata()->getFinNode()->setNumber(*counter);
            *counter = *counter + 1;

            return current->getAutomata();
        }
    }

    return current->getAutomata();

}