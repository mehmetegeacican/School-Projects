
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "avlTree.h"
#include "analysis.h"
using namespace std;


int main(){
    avlTree avl;
    analysis a1;

    int arrayOfElements[11]  = {5, 10, 15, 60, 8,40, 2, 30, 17, 12, 74};
    int deletionArray[5] = {30, 10, 8, 74, 5};
    for(int i = 0;i < 11; i++){
        avl.insertKey(arrayOfElements[i]);
    }
    cout <<  "Printing after deletion" << endl;
    avl.levelOrder();
    for(int j = 0; j < 5; j++){
        avl.deleteKey(deletionArray[j]);
    }
    cout << "Printing after deletion" << endl;
    avl.levelOrder();
    //HEIGHT ANALYSIS
    a1.heightAnalysis();

}
