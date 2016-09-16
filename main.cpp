#include <iostream>

#include "postfix.h"
#include "TreeNode.h"
#include "NFAgenerator.h"
#include "NFAsimulation.h"

using namespace std;

int main(){

    string sentence ;
    string postfix;
    string text;

    cout <<"Escribir cadena ";

    getline(cin, sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    postfix = infix2Postfix(sentence);

    stack < TreeNode * > t=postfix2Tree(postfix);

    TreeNode* tree = t.top();
    int tnum =0;
    int *num = &tnum;
    Automata *a = nfaGen(t.top(), num);

    cout <<"Escribir cadena a verificar ";

    getline(cin, text);
    if (nfaSimulation(text,a)==true){
        cout << "El resultado es: si se acepta la cadena" << endl;
    }
    else if(nfaSimulation(text,a)==false) {
        cout << "El resultado es: no se acepta la cadena" << endl;
    }
    return 0;

}