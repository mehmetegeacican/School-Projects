/**
* Title: Heaps and AVL Trees
* Author: Mehmet Ege Acýcan
* ID: 21602186
* Section: 1
* Assignment: 3
* Description: This code contains the interfaces of the methods and constructors
*/


#ifndef AVLTREE_H
#define AVLTREE_H
#include "avlNode.h"
class avlTree{
public:
    avlTree();
    avlTree(const avlTree &tree);
    int maximum(int a,int b);
    //METHODS: NEW AVL
    avlNode* newAVL(int key);
    //METHODS: HEIGHT
    int getHeight();
    int findHeight(avlNode* node);
    int getBalance(avlNode* node);
    //METHODS: ROTATE
    avlNode* rightRightRotate(avlNode* &rotNode);
    avlNode* leftRightRotate(avlNode* &rotNode);
    avlNode* leftLeftRotate(avlNode* &rotNode);
    avlNode* rightLeftRotate(avlNode* &rotNode);
    avlNode* balancer(avlNode* temp);
    //METHODS: INSERTION AND DELETION
    void insertKey(int val);
    avlNode* insertVal(avlNode *&treePtr,const int &newItem);
    void deleteKey(int val);
    avlNode* deleteVal(avlNode *&treePtr,const int &newItem);
    avlNode* processRight(avlNode* p);
    avlNode* processLeft(avlNode* p);
    //METHODS: PRINTING
    void printTree();
    void levelOrder();
    void printLevelOrder(avlNode* root);
    //METHODS: NODE COUNT
    int getNodeCount();
    int findTotalNode(avlNode *node);
    bool getKey(int key);
    bool itemInTree(avlNode *&treePtr,int key);




private:
    avlNode *root;
};
#endif // AVLTREE_H
