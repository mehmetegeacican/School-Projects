/**
* Title: Heaps and AVL Trees
* Author: Mehmet Ege Acýcan
* ID: 21602186
* Section: 1
* Assignment: 3
* Description: This code is the implementation of the methods and constructors
*/

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "avlTree.h"

using namespace std;
avlTree::avlTree(){
    root = NULL;
}
avlTree::avlTree(const avlTree &tree){
    root  = tree.root;
}

/**
 * MAXIMUM
 */
int avlTree:: maximum(int a, int b)
{
    return (a > b)? a : b;
}

/**
 *HEIGHT METHODS
 */
//METHODS: HEIGHT
int avlTree::getHeight(){
    if(root == NULL){
        return 0;
    }
    return findHeight(root);
}
int avlTree::findHeight(avlNode *node){
    if (node == NULL){
        return 0;
    }
    int lheight = findHeight(node->leftChildPtr);
    int rheight = findHeight(node->rightChildPtr);
    /* use the larger one */
    if (lheight > rheight){
        return(lheight+1);
    }
    else{
        return(rheight+1);
    }
}
/**
 *METHOD: GET BALANCE
 */
 // Get Balance factor of node N
int avlTree::getBalance(avlNode* N)
{
    if (N == NULL)
        return 0;
    return findHeight(N->leftChildPtr) - findHeight(N->rightChildPtr);
}
/**
 *METHOD: NEW NODE
 */
 /* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
avlNode* avlTree::newAVL(int key)
{
    avlNode* node = new avlNode();
    node->item = key;
    node->leftChildPtr = NULL;
    node->rightChildPtr = NULL;

    return(node);
}
/**
 *METHODS: ROTATORS
 */
//Rotations
//Rotations
/**
 *R-R
 */
avlNode* avlTree::rightRightRotate(avlNode* &rotNode){
    avlNode *temp;
    temp = rotNode->rightChildPtr;
    rotNode->rightChildPtr = temp->leftChildPtr;
    temp->leftChildPtr = rotNode;
    return temp;
}
/**
 *L-L
 */
avlNode* avlTree::leftLeftRotate(avlNode* &rotNode){
    avlNode *temp;
    temp = rotNode->leftChildPtr;
    rotNode->leftChildPtr =temp->rightChildPtr;
    temp->rightChildPtr = rotNode;
    return temp;
}
/**
 *L-R
 */
avlNode* avlTree::leftRightRotate(avlNode* &rotNode){
    avlNode *temp;
    temp = rotNode->leftChildPtr;
    rotNode->leftChildPtr =rightRightRotate(temp);
    return leftLeftRotate(rotNode);
}
/**
 *R-L
 */
avlNode* avlTree::rightLeftRotate(avlNode* &rotNode){
    avlNode *temp;
    temp = rotNode->rightChildPtr;
    rotNode->rightChildPtr =leftLeftRotate(temp);
    return rightRightRotate(rotNode);
}

//Balance method
avlNode* avlTree::balancer(avlNode *temp)
{
    int bal_factor = getBalance(temp);
    if (bal_factor > 1)
    {
        if (getBalance(temp->leftChildPtr) > 0)
            temp = leftLeftRotate(temp);
        else
            temp = leftRightRotate(temp);
    }
    else if (bal_factor < -1)
    {
        if (getBalance(temp->rightChildPtr) > 0)
            temp = rightLeftRotate(temp);
        else
            temp = rightRightRotate(temp);
    }
    return temp;
}

//Methods: INSERTION
void avlTree::insertKey(int val){
    // Position of insertion found; insert after leaf
    insertVal(root,val);

}

avlNode* avlTree::insertVal(avlNode *&treePtr,const int &newItem){
    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = newAVL(newItem);
        return treePtr;
    }
    // Else search for the insertion position
    else if (newItem < treePtr->item){
        treePtr->leftChildPtr = insertVal(treePtr->leftChildPtr, newItem);
        treePtr = balancer(treePtr);
    }
    else if (newItem >= treePtr -> item){
        treePtr->rightChildPtr = insertVal(treePtr->rightChildPtr, newItem);
        treePtr = balancer(treePtr);
    }
    return treePtr;

}
//METHOD DELETION
void avlTree::deleteKey(int val){
    deleteVal(root,val);
}
/**
 *DELETE
 */
 avlNode* avlTree:: deleteVal(avlNode *&treeptr,const int &data){
    //NO LEFT OR RIGHT CHILD
    if(treeptr->leftChildPtr == NULL && treeptr->rightChildPtr == NULL){
        delete treeptr;
        treeptr = NULL;
        return NULL;
    }
    avlNode *q;
    if(treeptr->item < data){
        treeptr->rightChildPtr = deleteVal(treeptr->rightChildPtr,data);
    }
    else if(treeptr->item > data){
        treeptr->leftChildPtr = deleteVal(treeptr->leftChildPtr,data);
    }
    else{
        if(treeptr->leftChildPtr != NULL){
            q = processRight(treeptr->leftChildPtr);
            treeptr->item = q->item;
            treeptr->leftChildPtr=deleteVal(treeptr->leftChildPtr,q->item);
        }
        else{
            q = processLeft(treeptr->rightChildPtr);
            treeptr->item = q->item;
            treeptr->rightChildPtr = deleteVal(treeptr->rightChildPtr,q->item);
        }
    }
    //ROTATION AFTER DELETION
    if(getBalance(treeptr)==2 && getBalance(treeptr->leftChildPtr)==1){
            treeptr = leftLeftRotate(treeptr);
    }
    else if(getBalance(treeptr)==2 && getBalance(treeptr->leftChildPtr)==-1){
        treeptr = leftRightRotate(treeptr);
    }
    else if(getBalance(treeptr)==2 && getBalance(treeptr->leftChildPtr)==0){
            treeptr = leftLeftRotate(treeptr);
    }
    else if(getBalance(treeptr)==-2 && getBalance(treeptr->rightChildPtr)==-1){
            treeptr = rightRightRotate(treeptr);
    }
    else if(getBalance(treeptr)==-2 && getBalance(treeptr->rightChildPtr)==1){
            treeptr = rightLeftRotate(treeptr);
    }
    else if(getBalance(treeptr)==-2 && getBalance(treeptr->rightChildPtr)==0){
            treeptr = leftLeftRotate(treeptr);
    }

    return treeptr;
}

/**
 *ProcessLeftMost
 */
 avlNode* avlTree::processRight(avlNode* p){
    while(p->rightChildPtr!=NULL)
        p = p->rightChildPtr;
    return p;
}

 avlNode* avlTree:: processLeft(avlNode* p){
    while(p->leftChildPtr!=NULL)
        p = p->leftChildPtr;
    return p;
}
/**
 *PRINTING
 */
 void avlTree::levelOrder(){
     printLevelOrder(root);
     cout << "" << endl;
 }
 void avlTree:: printLevelOrder(avlNode* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<avlNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        avlNode* node = q.front();
        cout << node->item << "--";
        q.pop();

        /* Enqueue left child */
        if (node->leftChildPtr != NULL)
            q.push(node->leftChildPtr);

        /*Enqueue right child */
        if (node->rightChildPtr != NULL)
            q.push(node->rightChildPtr);
    }
}
/**
 * COUNT
 */

int avlTree::getNodeCount(){
    if(root == NULL){
        return 0;
    }
    return findTotalNode(root);
}
int avlTree::findTotalNode(avlNode *node){
    if(node == NULL){
        return 0;
    }
    else{
        return findTotalNode(node->leftChildPtr) + 1 +findTotalNode(node->rightChildPtr);
    }
}
/**
 *
 */
 bool avlTree::getKey(int key){
    if (root == NULL){
        return false;
    }
    // Position of deletion found
    else if (key == root->item){
        return true;
    }
    // Else search for the deletion position
    else if (key < root->item){
        return itemInTree(root->leftChildPtr, key);
    }
    else{
        return itemInTree(root->rightChildPtr, key);
    }
}

bool avlTree::itemInTree(avlNode *&treePtr,int key){
    if (treePtr == NULL){
        return false;
    }
    // Position of deletion found
    else if (key == treePtr->item){
        return true;
    }
    // Else search for the deletion position
    else if (key < treePtr->item){
        return itemInTree(treePtr->leftChildPtr, key);
    }
    else{
        return itemInTree(treePtr->rightChildPtr, key);
    }
}



