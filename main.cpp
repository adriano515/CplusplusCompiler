#include <iostream>

#include "postfix.h"
#include "TreeNode.h"
#include "AutomataNode.h"
#include "NFAgenerator.h"
#include "Transition.h"
#include "NFAsimulation.h"

using namespace std;

int main(){

    string sentence ;
    string postfix;

    cout <<"Escribir cadena ";

    getline(cin, sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    postfix = infix2Postfix(sentence);

    stack < TreeNode * > t=postfix2Tree(postfix);

    TreeNode* tree = t.top();
    int tnum =0;
    int *num = &tnum;
    Automata *a = nfaGen(t.top(), num);

    set<AutomataNode*> s = eClosure(a->getInitNode());

    return 0;

}