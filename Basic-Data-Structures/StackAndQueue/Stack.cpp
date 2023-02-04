#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

Stack::Stack(){
    top = NULL;
}
Stack::Stack(const Stack &pbStack){
    top = pbStack.top;
}
/**THIS FUNCTION PRINTS THE STACK FROM TOP TO BOTTOM*/
void Stack::printStack(Node* n){
    while (n != NULL) {
        cout << n->data << endl;
        n = n->next;
    }
}
/**THIS FUNCTION ADDS A NEW ELEMENT TO THE STACK*/
void Stack::push(Node** top_ref,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}
/**THIS FUNCTION REMOVES AN ELEMENT FROM THE STACK*/
void Stack::pop(Node** top){
    //IF STACK IS EMPTY
    if (*top == NULL){
            return;
    }
    // Store head node
    Node* temp = *top;

    // If head needs to be removed
    *top = temp->next;
    free(temp);
    return;
}
