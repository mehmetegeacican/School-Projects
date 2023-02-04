#ifndef __QUEUE_H
#define __QUEUE_H
#include <string>
#include "Node.h"
using namespace std;
class Queue{
public:
    Queue();
    Queue(const Queue &pbQueue);
    //PUSH AND POP
    void enqueue(Node** head_ref, int new_data);
    void dequeue(Node** head);
    //PRINT
    void printQueue(Node* top);
    //The Top
    Node *head;

};
#endif
