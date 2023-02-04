#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "PbBST.h"
using namespace std;

PbBST::PbBST(){
    root = NULL;
}
PbBST::PbBST(const PbBST &tree){
    root = tree.root;
}
//INSERT METHOD
/**
 *For inserting the key
 *
 */
void PbBST::insertKey(const int Key){
    // Position of insertion found; insert after leaf
    if (root == NULL) {
        root = new PbBSTNode(Key, NULL, NULL);
    }
    // Else search for the insertion position
    else if (Key < root->item){
        insertItem(root->leftChildPtr,Key);
    }

    else{
        insertItem(root->rightChildPtr,Key);
    }

}
void PbBST::insertItem(PbBSTNode *&treePtr,const int &newItem){
    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new PbBSTNode(newItem, NULL, NULL);
    }
    // Else search for the insertion position
    else if (newItem < treePtr->item){
        insertItem(treePtr->leftChildPtr, newItem);
    }
    else{
        insertItem(treePtr->rightChildPtr, newItem);
    }
}
//DELETE METHOD
/**
 *For delete key
 *
 */
void PbBST::deleteKey(int key){
    deleteItem(root, key);
}
void PbBST::deleteItem(PbBSTNode *&treePtr,int searchKey){
    if (treePtr == NULL){
        //cout << "No node found to delete" << endl;
    }
    // Position of deletion found
    else if (searchKey == treePtr->item){
        deleteNodeItem(treePtr);
    }
    // Else search for the deletion position
    else if (searchKey < treePtr->item){
        deleteItem(treePtr->leftChildPtr, searchKey);
    }
    else{
        deleteItem(treePtr->rightChildPtr, searchKey);
    }
}
void PbBST::deleteNodeItem(PbBSTNode *&nodePtr){
    PbBSTNode *delPtr;
    int replacementItem;
    // (1)  Test for a leaf
    if((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)){
        delete nodePtr;
        nodePtr = NULL;
    }
    // (2)  Test for no left child
    else if(nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    // (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else{
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}
void PbBST::processLeftmost(PbBSTNode *&nodePtr, int &treeItem){

    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        PbBSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else{
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    }
}
//FIND NODES REQUIRED METHODS
//HEIGHT
/**
 *For height
 */
int PbBST::getHeight(){
    if(root == NULL){
        return 0;
    }
    return findHeight(root);
}
int PbBST::findHeight(PbBSTNode *node){
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
 *For getting the node count
 *
 */
int PbBST::getNodeCount(){
    if(root == NULL){
        return 0;
    }
    return findTotalNode(root);
}
int PbBST::findTotalNode(PbBSTNode *node){
    if(node == NULL){
        return 0;
    }
    else{
        return findTotalNode(node->leftChildPtr) + 1 +findTotalNode(node->rightChildPtr);
    }
}
/**
 *For finding the nodes required
 *
 */
int PbBST::findNodesRequired(){
    int FullTreeNumber = 1;
    for(int i = 0; i < getHeight();i++){
        FullTreeNumber = FullTreeNumber *2;
    }
    FullTreeNumber--;
    return FullTreeNumber - getNodeCount();
}
/**
 *For Getting the key
 */
bool PbBST::getKey(int key){
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

bool PbBST::itemInTree(PbBSTNode *&treePtr,int key){
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
/**
 *FIND FULL BT
 */
int PbBST:: getLevelOrder(PbBSTNode* root)
{
    // Base Case
    if (root == NULL)
        return 0;

    int fullBTLevel = 1;
    int powerLevel = 1;
    // Create an empty queue for level order traversal
    queue<PbBSTNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        PbBSTNode* node = q.front();
        if(q.size() == pow(2,powerLevel)){
            fullBTLevel++;
            powerLevel++;
        }
        q.pop();

        /* Enqueue left child */
        if (node->leftChildPtr != NULL)
            q.push(node->leftChildPtr);

        /*Enqueue right child */
        if (node->rightChildPtr != NULL)
            q.push(node->rightChildPtr);
    }
    return fullBTLevel;
}
 int PbBST::findFullBTLevel(){
    return getLevelOrder(root);
 }
 //MIRROR TREE
 void PbBST::mirrorTree(){
     cout << "Printing inorder traversal of the tree" << endl;
     inOrder(root);
     cout << "" << endl;
     mirrorBST(root);
     cout << "Printing level order of the copy mirrored tree" << endl;
     printLevelOrder(root);
     cout << "" << endl;
     cout << "Printing the inorder traversal of the copy mirrored tree" << endl;
     inOrder(root);
     cout << "" << endl;
 }

 void PbBST::mirrorBST(PbBSTNode* root){
     // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<PbBSTNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        PbBSTNode* node = q.front();
        swap(node->leftChildPtr,node->rightChildPtr);
        q.pop();

        /* Enqueue left child */
        if (node->leftChildPtr != NULL)
            q.push(node->leftChildPtr);

        /*Enqueue right child */
        if (node->rightChildPtr != NULL)
            q.push(node->rightChildPtr);
    }
 }
 void PbBST:: inOrder(PbBSTNode* node)
{
    if (node == NULL)
        return;

    inOrder(node->leftChildPtr);
    cout << node->item << " ";
    inOrder(node->rightChildPtr);
}
void PbBST::levelOrder(){
    printLevelOrder(root);
    cout << "" << endl;
}
void PbBST:: printLevelOrder(PbBSTNode* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<PbBSTNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        PbBSTNode* node = q.front();
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

