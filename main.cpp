#include <iostream>

#include "postfix.h"
#include "TreeNode.h"
#include "AutomataNode.h"
#include "NFAgenerator.h"
#include "Transition.h"

using namespace std;

int main(){

    string sentence ;
    string postfix;

    cout <<"Escribir cadena ";

    getline(cin,sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    postfix = infix2Postfix(sentence);

    stack < TreeNode * > t=postfix2Tree(postfix);

    TreeNode* tree = t.top();

    nfaGen(t.top());

    return 0;

}