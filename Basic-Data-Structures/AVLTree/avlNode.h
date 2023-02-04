/**
* Title: Heaps and AVL Trees
* Author: Mehmet Ege Acýcan
* ID: 21602186
* Section: 1
* Assignment: 3
* Description: This code contains the basic structure of an avlnode
*/

#ifndef __AVLNODE_H
#define __AVLNODE_H
#include <string>
using namespace std;
class avlNode{
public:
    int getKey();
private:
    avlNode() {}
    avlNode(const int &nodeItem,
        avlNode *left = NULL,
        avlNode *right = NULL
        )
        :item(nodeItem),leftChildPtr(left),rightChildPtr(right){}

    int item;       // data portion
    avlNode *leftChildPtr;  // pointer to left child
    avlNode *rightChildPtr; // pointer to right child
    friend class avlTree;

};
#endif
