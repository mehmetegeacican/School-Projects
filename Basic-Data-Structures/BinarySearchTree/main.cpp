#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "PbBST.h"
#include "analysis.h"
using namespace std;

int main(){
    cout<< "THIS IS WORKING" << endl;
    PbBST A;
    //analysis analyzer;
    //analyzer.timeAnalysis();
    //INSERTIONS
    A.insertKey(7);
    A.insertKey(3);
    A.insertKey(6);
    A.insertKey(12);
    A.insertKey(13);
    A.insertKey(4);
    A.insertKey(1);
    A.insertKey(9);
    A.insertKey(15);
    A.insertKey(0);
    A.insertKey(11);
    A.insertKey(14);
    A.insertKey(2);
    A.insertKey(8);
    A.insertKey(14);
    A.insertKey(5);
    //FIND NODES REQUIRED
    cout << A.findNodesRequired() << "--> amount of nodes needed for a full bt" << endl;
    //DELETION
    A.deleteKey(7);
    A.deleteKey(8);
    //FULL BT
    cout << A.findFullBTLevel() << "--> The level which the tree is a full bt" << endl;
    //PRINTING LEVEL ORDER OF THE TREE
    cout << "Printing the level order of the tree" << endl;
    A.levelOrder();
    A.mirrorTree();

}
