//
// Created by Freddie on 9/14/2016.
//

#ifndef C_COMPILER_NFASIMULATION_H
#define C_COMPILER_NFASIMULATION_H

#include "AutomataNode.h"
#include <set>

using namespace std;

set<AutomataNode*> eClosure(AutomataNode* s);

#endif //C_COMPILER_NFASIMULATION_H
