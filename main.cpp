#include <iostream>

#include "postfix.h"
#include "TreeNode.h"


using namespace std;


int main(){

    string sentence ;
    string postfix;



    cout <<"Escribir cadena ";

    getline(cin,sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    postfix = infix2Postfix(sentence);
/*
    TreeNode *root;
    root = nullptr;
    cout << postfix.length() << endl;
    for (int i = postfix.length();i>0 ;i--){
            treeInsert(*&root, postfix[i] );

    }
*/




    return 0;

}