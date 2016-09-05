//
// Created by Freddie on 9/4/2016.
//

#ifndef C_COMPILER_TRANSITION_H
#define C_COMPILER_TRANSITION_H

#include "AutomataNode.h"
class AutomataNode;

class Transition{
private:
    char value;
    AutomataNode *nextNode ;
public:
    Transition(char val,AutomataNode *node){
        value = val;
        nextNode = node;
    }

    char getValue(){
        return value;
    }
};


#endif //C_COMPILER_TRANSITION_H
