#ifndef __PBSTNODE_H
#define __PBSTNODE_H
#include <string>
using namespace std;
class PbBSTNode{
public:
    int getKey();
private:
    PbBSTNode() {}
    PbBSTNode(const int &nodeItem,
        PbBSTNode *left = NULL,
        PbBSTNode *right = NULL)
        :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}

    int item;       // data portion
    PbBSTNode *leftChildPtr;  // pointer to left child
    PbBSTNode *rightChildPtr; // pointer to right child

    friend class PbBST;

};
#endif
