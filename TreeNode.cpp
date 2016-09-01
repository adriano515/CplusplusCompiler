//
// Created by Freddie on 8/29/2016.
//

#include <iostream>
#include <stack>
#include "postfix.h"


using namespace std;



struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char elem){
        value = elem;
        left = nullptr;
        right  = nullptr;
    }


    void setRight(TreeNode* newRight){
        right = newRight;
    }

    void setLeft(TreeNode* newLeft){
        left = newLeft;
    }

    void setValue(char elem){
        value = elem;
    }

};
/*

void treeInsert(TreeNode *&root, char newItem) {
    // Add the item to the binary sort tree to which the parameter
    // "root" refers.  Note that root is passed by reference since
    // its value can change in the case where the tree is empty.
    if ( root == nullptr ) {
        // The tree is empty.  Set root to point to a new node containing
        // the new item.  This becomes the only node in the tree.
        root = new TreeNode( newItem );
        // NOTE:  The left and right subtrees of root
        // are automatically set to NULL by the constructor.
        // This is important!
        return;
    }
    else if ( newItem < root->value ) {

        //condicion mala, son chars y si pueden ser menores o mayores, hay que revisar si son operadores y si el derecho esta vacio
        treeInsert( root->left, newItem );
    }
    else {
        treeInsert( root->right, newItem );
    }
}
// end treeInsert()

void postorderPrint( TreeNode *root ) {
    // Print all the items in the tree to which root points.
    // The items in the left subtree are printed first, followed
    // by the items in the right subtree and then the item in the
    // root node.
    if ( root != nullptr ) {  // (Otherwise, there's nothing to print.)
        postorderPrint( root->left );    // Print items in left subtree.
        postorderPrint( root->right );   // Print items in right subtree.
        cout << root->value << " ";       // Print the root item.
    }
} // end postorderPrint()

*/

//Stack para los operandos
//Stack para los subarboles (solo se meteria el nodo padre)

//Revisar de izq a derecha
//Si es operando pushearlo al stack
//Si es operador verificar si es kleen , si no es popear dos operandos del stack, si es popear 1
//Si solo se logro popear 1 operando ir al stack de arbol y popear un arbol
//si no se popeo nada ir al stack de arbol y popear 2 arboles

stack<char> items;
stack<TreeNode*> subTree;
stack<TreeNode*> nodes;

void postfix2Tree(string postfix){
    for (int i=0; i < postfix.length(); i++){
        if(isOperand(postfix[i])){
            items.push(postfix[i]);
        }
        else if(isOperator(postfix[i])){
            if (postfix[i]=='^'){

                if (items.size()>=1 ){
                    char der = items.top();
                    nodes.push(new TreeNode(der));
                    items.pop();

                    subTree.push(new TreeNode(postfix[i]));
                    subTree.top()->setRight(nodes.top());
                    nodes.pop();

                    subTree.top()->setValue(postfix[i]);
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
}