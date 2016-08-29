#include <iostream>

#include "postfix.h"
#include "TreeNode.h"


using namespace std;


int main(){

    string sentence ;

    cout <<"Escribir cadena ";

    getline(cin,sentence);

    cout << "Output =" << infix2Postfix(sentence) << "\n";

    TreeNode *root;

    for (int i = 0;i<sentence.length() ;i++){
            treeInsert(*&root, sentence[i] );

    }




    return 0;

}