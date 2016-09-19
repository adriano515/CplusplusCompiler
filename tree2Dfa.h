//
// Created by Freddie on 9/18/2016.
//

#ifndef C_COMPILER_POSTFIX2DFA_H
#define C_COMPILER_POSTFIX2DFA_H

#include "TreeNode.h"

void nullable(TreeNode* t);
void firstPos(TreeNode* t);
void followPos(TreeNode* t);
void lastPos(TreeNode* t);
AutomataDfa* tree2Dfa(TreeNode* t,string language);

#endif //C_COMPILER_POSTFIX2DFA_H
