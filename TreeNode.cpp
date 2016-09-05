
#include <iostream>
#include <stack>
#include "postfix.h"
#include "TreeNode.h"

using namespace std;

//Stack para los operandos
//Stack para los subarboles (solo se meteria el nodo padre)

//Revisar de izq a derecha
//Si es operando pushearlo al stack
//Si es operador verificar si es kleen , si no es popear dos operandos del stack, si es popear 1
//Si solo se logro popear 1 operando ir al stack de arbol y popear un arbol
//si no se popeo nada ir al stack de arbol y popear 2 arboles

stack <TreeNode*> postfix2Tree(string postfix){

    stack<char> items;
    stack<TreeNode*> subTree;
    stack<TreeNode*> nodes;

    for (int i=0; i < postfix.length(); i++){
        if(isOperand(postfix[i])){
            items.push(postfix[i]);
        }
        else if(isOperator(postfix[i])){
            if (postfix[i]=='^'){

                if (items.size()>=1 ){
                    char izq = items.top();
                    nodes.push(new TreeNode(izq));
                    items.pop();

                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setLeft(nodes.top());
                    nodes.pop();

                    subTree.top()->setValue(postfix[i]);
                }

                else{
                    stack<TreeNode*> temp;
                    temp.push(subTree.top());
                    subTree.pop();
                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setLeft(temp.top());
                    temp.pop();
                }

            }

            else{
                if (items.size() >= 2){
                    char der = items.top();
                    nodes.push(new TreeNode(der));
                    items.pop();

                    char izq = items.top();
                    items.pop();
                    nodes.push(new TreeNode(izq));

                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setLeft(nodes.top());
                    nodes.pop();

                    subTree.top()->setRight(nodes.top());
                    nodes.pop();

                    subTree.top()->setValue(postfix[i]);

            }
                else if (items.size() ==1){

                    stack<TreeNode*> temp;

                    char izq = items.top();
                    items.pop();
                    nodes.push(new TreeNode(izq));

                    temp.push(subTree.top());
                    subTree.pop();

                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setLeft(nodes.top());
                    nodes.pop();

                    subTree.top()->setRight((temp.top()));
                    temp.pop();

                    subTree.top()->setValue(postfix[i]);

                }

                else if (items.size() ==0){
                    stack<TreeNode*> temp;

                    temp.push(subTree.top());
                    subTree.pop();
                    temp.push(subTree.top());
                    subTree.pop();

                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setLeft(temp.top());
                    temp.pop();
                    subTree.top()->setRight(temp.top());
                    temp.pop();


                }
            }

        }
    }
    return subTree;
}

