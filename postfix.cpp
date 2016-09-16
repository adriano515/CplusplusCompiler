
#include <string>
#include <stack>

using namespace std;

int getOpWeight(char op){
    int weight = -1;
    switch (op){

        case '|' :
            weight = 1;
            break;
        case '*' :
            weight = 2;
            break;
        case '^' :
            weight = 3;
            break;
        default:break;
    }

    return weight;
}

bool hasHigherPrec(char op1, char op2){
    int op1Weight;
    op1Weight = getOpWeight(op1);
    int op2Weight;
    op2Weight = getOpWeight(op2);

    return op1Weight > op2Weight;
}

bool isOperator(char c) {

    return (c == '|' || c == '*' || c == '^');
}


bool isOperand(char c){
    return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c<= 'Z');

}

string infix2Postfix(string sentence){
    stack<char> elems;
    string postfix = "";

    for (int i = 0;i<sentence.length() +1;i++){

        if(sentence[i] == ' ' || sentence[i] == ',') continue;

        else if(isOperand(sentence[i])){
            postfix += sentence[i];
        }

        else if(isOperator(sentence[i])){
            while (!elems.empty() && elems.top() != '(' && hasHigherPrec(elems.top(),sentence[i])){
                postfix += elems.top();
                elems.pop();
            }
            elems.push(sentence[i]);
        }
        else if(sentence[i] == '('){
            elems.push(sentence[i]);
        }
        else if(sentence[i]==')'){
            while(!elems.empty() && elems.top() != '(' ){
                postfix += elems.top();
                elems.pop();
                }
            elems.pop();
        }

    }

    while (!elems.empty()){
        postfix += elems.top();
        elems.pop();

    }

    return postfix;
}