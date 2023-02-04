#ifndef __STACK_H
#define __STACK_H
#include <string>
#include "Node.h"
using namespace std;
class Stack{
public:
    Stack();
    Stack(const Stack &pbStack);
    //PUSH AND POP
    void push(Node** top_ref, int new_data);
    void pop(Node** top);
    //PRINT
    void printStack(Node* top);
    //The Top
    Node *top;

};
#endif
