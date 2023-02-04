#ifndef __PBLIST_H
#define __PBLIST_H
#include <string>
#include "PbNode.h"
using namespace std;
class PbList{
public:
    PbList();
    PbList(const PbList &linkedList);
    //Printing of the List
    void printList(PbNode* n);
    //Insertion and Deletion to the list
    void insertHead(PbNode** head_ref, int new_data);
    void insertTail(PbNode** head_ref, int new_data);
    void insertInBetween(PbNode* prev_node,int new_data);
    void insertAfter(PbNode** head_ref,int prev_data,int new_data);
    void deleteNode(PbNode** head_ref, int key);
    void deleteHead(PbNode** head);
    void deleteTail(PbNode** head);
    //Searching
    bool ifInList(PbNode *head, int x);
    int getNthElement(PbNode *head,int x);


    //will be made to be private later on
    PbNode *head;

};
#endif
