#include "AutomataNode.h"
#include <vector>
#include <string>

using namespace std;
class Automata{
    AutomataNode* initial;
    vector<AutomataNode*> final;
public:
    Automata(AutomataNode* init, vector<AutomataNode*> fin){
        initial = init;
        final = fin;
    }

    Automata(){}

    void addAutomataNodes(AutomataNode* node,bool b) {
        //where true = add initial and fals= add final
        if (b) {
            initial= node;
        }
        else{
            final.push_back(node);
        }
    }
    AutomataNode* getInitNode(){
        return initial;
    }

    vector<AutomataNode*> getFinalNodes(){
        return final;
    }

};


class AutomataNode{
private:
    vector<Transition*> Itransitions;
    vector<Transition*> Ftransitions;
    int number;
public:
    void setAutomataNumber(int num){
        number = num;
    }

    void addAutomataTran(Transition* t,bool b) {
        //where true = add initial and fals= add final
        if (b) {
            Itransitions.push_back(t);
        }
        else{
            Ftransitions.push_back(t);
        }
    }

};

class Transition{
private:
    AutomataNode* initial;
    AutomataNode* final;
    string transition;
public:
    Transition(AutomataNode* init, AutomataNode* fin, string tran){
        initial = init;
        final = fin;
        transition = tran;
    }
};



Automata *automataEpsilon(AutomataNode *i, vector<AutomataNode *> f) {
    Automata *automata = new Automata();
    for(int j=0;j<f.size();j++) {


        Transition *t = new Transition(i, f[j], "e");

        i->addAutomataTran(t, true);
        f[j]->addAutomataTran(t, false);

        automata->addAutomataNodes(f[j], false);
    }

    automata->addAutomataNodes(i, true);

    return automata;
}

Automata *automataEpsilon(AutomataNode *i, AutomataNode *f) {
    Automata *automata = new Automata();
    Transition *t = new Transition(i, f, "e");

    i->addAutomataTran(t, true);
    f->addAutomataTran(t, false);

    automata->addAutomataNodes(f, false);


    automata->addAutomataNodes(i, true);

    return automata;
}


Automata *automataLetter(AutomataNode *i, vector<AutomataNode *> f, string letter) {
    Automata *automata = new Automata();
    for(int j=0;j<f.size();j++) {


        Transition *t = new Transition(i, f[j], letter);

        i->addAutomataTran(t, true);
        f[j]->addAutomataTran(t, false);

        automata->addAutomataNodes(f[j], false);
    }

    automata->addAutomataNodes(i, true);

    return automata;
}

Automata *automataLetter(AutomataNode *i, AutomataNode *f, string letter) {
    Automata *automata = new Automata();
    Transition *t = new Transition(i, f, letter);

    i->addAutomataTran(t, true);
    f->addAutomataTran(t, false);
    automata->addAutomataNodes(f, false);

    automata->addAutomataNodes(i, true);

    return automata;
}


Automata *automataOR(Automata *a, Automata *b) {
    AutomataNode* initial = new AutomataNode(); //initial node
    AutomataNode* uFNode = a->getInitNode(); //upper first node
    AutomataNode* lFNode = b->getInitNode(); //lower first node
    AutomataNode* final = new AutomataNode(); //final automata

    vector<AutomataNode*> temp;
    temp.push_back(uFNode);
    temp.push_back(lFNode);

    vector<AutomataNode*> temp2;
    temp2 = a->getFinalNodes();
    for (int i =0;i<b->getFinalNodes().size();i++){
        temp2.push_back(b->getFinalNodes()[i]);
    }

    automataEpsilon(initial,temp);
    automataEpsilon(final,temp2);

    Automata* automata = new Automata(initial,temp2);
    return automata;

}

Automata *automataAnd(Automata *a, Automata *b) {

    Automata* automata = new Automata();

    automata->addAutomataNodes(a->getInitNode(),true);

    for (int i =0; i<b->getFinalNodes().size();i++){
        automata->addAutomataNodes(b->getFinalNodes()[i],false);
    }

    return automata;
}


Automata *automataKleen(Automata *a) {

    AutomataNode* init = new AutomataNode();
    AutomataNode* final = new AutomataNode();

    Automata* automata = new Automata();

    automataEpsilon(init,a->getInitNode());
    automataEpsilon(init,final);

    for (int i =0;i<a->getFinalNodes().size();i++){
        automataEpsilon(a->getFinalNodes()[i],final);
        automataEpsilon(a->getFinalNodes()[i],a->getInitNode());
    }

    automata->addAutomataNodes(init,true);
    automata->addAutomataNodes(final,false);

    return automata;
}



