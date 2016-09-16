#include <vector>
#include <string>

using namespace std;

#ifndef C_COMPLIER_POSTFIX_H
#define C_COMPLIER_POSTFIX_H

int getOpWeight(char op);

bool hasHigherPrec(char op1, char op2);

bool isOperator(char c);

bool isOperand(char c);

string infix2Postfix(string sentence);

#endif //C_COMPLIER_POSTFIX_H