#ifndef __PBNODE_H
#define __PBNODE_H
#include <string>
using namespace std;
class PbNode{
public:
    PbNode() {}
    PbNode(const int &nodeItem,
        PbNode *next = NULL)
        :data(nodeItem),next(next){}

    int data;
    PbNode* next;

    friend class PbList;
};
#endif
