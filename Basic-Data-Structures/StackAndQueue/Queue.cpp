#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "Queue.h"
using namespace std;

Queue::Queue(){
    head = NULL;
}
Queue::Queue(const Queue &pbQueue){
    head = pbQueue.head;
}

void Queue::printQueue(Node* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << "" << endl;
}
/**THIS FUNCTION ADDS A NEW ELEMENT TO THE QUEUE*/
void Queue::enqueue(Node** head_ref,int new_data){
    //New Node Allocation
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    //If the Linked List is empty
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    //Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
/**THIS FUNCTION REMOVES AN ELEMENT FROM THE QUEUE*/
void Queue::dequeue(Node** head){
    //IF QUEUE IS EMPTY
    if (*head == NULL){
            return;
    }
    // Store head node
    Node* temp = *head;

    // If head needs to be removed
    *head = temp->next;
    free(temp);
    return;
}
