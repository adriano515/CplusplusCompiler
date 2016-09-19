#include <iostream>

#include "postfix.h"
#include "TreeNode.h"
#include "NFAgenerator.h"
#include "Simulation.h"
#include "Nfa2Dfa.h"
#include "tree2Dfa.h"

using namespace std;

int main(){

    string sentence ;
    string postfix;
    string text;
    string language;

    cout <<"Escribir cadena ";

    getline(cin, sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    for(int i =0; i<sentence.size(); i++) {
        if (isOperand(sentence[i])) {
            if (language.find(sentence[i]) == string::npos) {
                language += sentence[i];
            }
        }
    }

    cout <<"lenguaje contiene cadenas de " << language<< endl;

    postfix = infix2Postfix(sentence);

    stack < TreeNode * > t=postfix2Tree(postfix);

    int tnum =0;
    int *num = &tnum;
    Automata *nfa = nfaGen(t.top(), num);
    AutomataDfa *dfa = Nfa2Dfa(nfa,language);

    /*
    cout <<"Escribir cadena a verificar ";

    getline(cin, text);
    if (nfaSimulation(text,nfa)==true){
        cout << "El resultado con nfa es: si se acepta la cadena" << endl;
    }
    else if(nfaSimulation(text,nfa)==false) {
        cout << "El resultado con nfa es: no se acepta la cadena" << endl;
    }
    */
    cout <<"Escribir cadena a verificar ";
    getline(cin, text);

    if (dfaSimulation(text,dfa)==true){
        cout << "El resultado con dfa es: si se acepta la cadena" << endl;
    }
    else if(dfaSimulation(text,dfa)==false) {
        cout << "El resultado con dfa es: no se acepta la cadena" << endl;
    }

    nullable(t.top());
    firstPos(t.top());
    lastPos(t.top());
    followPos(t.top());

    tree2Dfa(t.top(),language);


    return 0;

}