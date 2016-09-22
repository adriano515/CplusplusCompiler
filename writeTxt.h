//
// Created by Freddie on 9/21/2016.
//

#ifndef C_COMPILER_WRITETXT_H
#define C_COMPILER_WRITETXT_H

#include "AutomataNode.h"

void moves(AutomataNode* a);
void nfaWriter(Automata* a,string language);
void dfaWriter(AutomataDfa* a,string language);

#endif //C_COMPILER_WRITETXT_H
