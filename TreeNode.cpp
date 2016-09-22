
#include <iostream>
#include <stack>
#include "postfix.h"
#include "TreeNode.h"

using namespace std;

/*
Stack for operands
Stack for subtrees (only root nodes woudl be in here)

check left to right
if operand push to stack
if operator check if it's kleen , if not then pop two operands from stack, if it is then pop 1
if there was only 1 popped operand go to subtree stack and pop a subtree
if there was nothing to pop go to subtree stack and pop 2 subtrees
*/

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
                    if(postfix.size()-1==i and postfix[i]=='*' and temp.top()->getValue()=='^' ){
                                subTree.top()->setLeft(temp.top());
                                temp.pop();
                                subTree.top()->setRight(temp.top());
                                temp.pop();
                    }
                    else {
                        subTree.top()->setRight(temp.top());
                        temp.pop();
                        subTree.top()->setLeft(temp.top());
                        temp.pop();
                    }

                }
            }

        }
    }
    return subTree;
}