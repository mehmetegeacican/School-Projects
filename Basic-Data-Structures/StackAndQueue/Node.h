#ifndef __NODE_H
#define __NODE_H
#include <string>
using namespace std;
class Node{
public:
    Node() {}
    Node(const int &nodeItem,
        Node *next = NULL)
        :data(nodeItem),next(next){}

    int data;
    Node* next;

    friend class Stack;
    friend class Queue;
};
#endif
