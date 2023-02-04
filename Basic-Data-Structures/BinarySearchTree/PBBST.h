/**
* Title : Binary Search Trees
* Author : Mehmet Ege Acican
* Description : This project builds a binary search tree and tests runtimes of certain methods.
*/
#ifndef __PBST_H
#define __PBST_H
#include <string>
#include "PbBSTNode.h"
using namespace std;
class PbBST{
public:
    PbBST();
    PbBST(const PbBST &tree);
    //INSERTION AND DELETION
    void insertKey(int key);
    void insertItem(PbBSTNode *&node,const int &item);
    void deleteKey(int key);
    void deleteItem(PbBSTNode *&treePtr,int searchKey);
    void deleteNodeItem(PbBSTNode *&nodePtr);
    void processLeftmost(PbBSTNode *&nodePtr, int &treeItem);
    bool getKey(int key);
    bool itemInTree(PbBSTNode *&treePtr,int searchKey);
    //FIND NODES REQUIRED
    int getHeight();
    int findHeight(PbBSTNode *node);
    int getNodeCount();
    int findTotalNode(PbBSTNode *node);
    int findNodesRequired();
    //FIND FULL BT LEVEL
    int findFullBTLevel();
    int getLevelOrder(PbBSTNode* root);
    void printLevelOrder(PbBSTNode* root);
    void levelOrder();
    //MIRROR AND PRINT TREE
    void mirrorTree();
    void mirrorBST(PbBSTNode* root);
    void inOrder(PbBSTNode* node);
    void printTree();
private:
    PbBSTNode *root;
};
#endif
