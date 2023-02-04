#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "avlTree.h"
#include "analysis.h"

void  analysis::heightAnalysis(){
    //PART 1
    cout << "---------------------------------------------------------"<< endl;
    avlTree avlRandom;
    avlTree avlAsc;
    avlTree avlDesc;
    cout << "Part b - Height analysis of AVL trees" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Array Size   Random    Ascending    Descending" << endl;
    cout << "---------------------------------------------------------" << endl;
    avlRandom.insertKey(1);
    int increasing = 0;
    int decreasing = 80000;
    avlAsc.insertKey(increasing);
    avlDesc.insertKey(decreasing);
    while(avlRandom.getNodeCount() < 80000){
        int randomNumber = 1 + rand() % 100000;
        increasing++;
        decreasing--;
        avlRandom.insertKey(randomNumber);
        avlAsc.insertKey(increasing);
        avlDesc.insertKey(decreasing);
        if((avlRandom.getNodeCount() % 4000 == 0) && (avlRandom.getNodeCount() >= 4000)){
            cout << avlRandom.getNodeCount() << "          " << avlRandom.getHeight() << "           " << avlAsc.getHeight() << "           " << avlDesc.getHeight() << endl;
        }

    }
    cout << "---------------------------------------------------------" << endl;
    cout << avlAsc.getHeight() << " " << avlDesc.getHeight() << endl;

}
