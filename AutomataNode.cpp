#include "Transition.h"

using namespace std;

Automata *epsilonAut(AutomataNode *a, AutomataNode *b) {

    Transition *t = new Transition('e', b);
    a->addTransition(t);
    Automata *automata = new Automata(a, b);
    return  automata;
}

Automata *letterAut(AutomataNode *a, AutomataNode *b, char val) {

    Transition *t = new Transition(val, b);
    a->addTransition(t);
    Automata *automata = new Automata(a, b);
    return  automata;
}

Automata *orAut(Automata *a, Automata *b) {
    AutomataNode *initial = new AutomataNode();
    AutomataNode *final = new AutomataNode();

    epsilonAut(initial, a->getInitNode());
    epsilonAut(initial, b->getInitNode());

    epsilonAut(a->getFinNode(), final);
    epsilonAut(b->getFinNode(), final);

    Automata* autom = new Automata(initial, final);
    return  autom;
}

Automata *andAutomata(Automata *a, Automata *b) {
    for (int i=0;i<b->getInitNode()->getTransition().size();i++){
        a->getFinNode()->addTransition(b->getInitNode()->getTransition()[i]);
    }
    b->setInitAutomataNode(nullptr);
    Automata *autom = new Automata(a->getInitNode(), b->getFinNode());
    return autom;
}

Automata *kleenAutomata(Automata *a) {
    AutomataNode *init = new AutomataNode();
    AutomataNode *final = new AutomataNode();

    epsilonAut(a->getFinNode(), a->getInitNode());
    epsilonAut(init, a->getInitNode());
    epsilonAut(init, final);
    epsilonAut(a->getFinNode(), final);
    Automata* autom = new Automata(init, final);
    return autom;
}