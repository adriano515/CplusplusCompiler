#include <iostream>

#include "postfix.h"
#include "TreeNode.h"
#include "NFAgenerator.h"
#include "NFAsimulation.h"
#include "Nfa2Dfa.h"

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
    Automata *a = nfaGen(t.top(), num);

    cout <<"Escribir cadena a verificar ";
    /*getline(cin, text);
    if (nfaSimulation(text,a)==true){
        cout << "El resultado es: si se acepta la cadena" << endl;
    }
    else if(nfaSimulation(text,a)==false) {
        cout << "El resultado es: no se acepta la cadena" << endl;
    }
    */
    Nfa2Dfa(a,language);

    return 0;

}