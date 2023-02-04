
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include "PbBST.h"
#include "analysis.h"
void  analysis::timeAnalysis(){
    //PART 1
    PbBST AnalysisTree;
    AnalysisTree.insertKey(1);
    //Creating an array with random 15000 elements
    cout << "Part e - Time analysis of Binary Search Tree - part 1" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
    int randomArr[15000];
    int index = 0;
    while(AnalysisTree.getNodeCount() < 15000){
        clock_t begin_time = clock();
        int randomNumber = 1 + rand() % 100000;
        if(AnalysisTree.getKey(randomNumber) == 0){
            randomArr[index] = randomNumber;
            index++;
            AnalysisTree.insertKey(randomNumber);
            if((AnalysisTree.getNodeCount() % 1500 == 0) && (AnalysisTree.getNodeCount() >= 1500)){
                if(AnalysisTree.getNodeCount() <= 10000){
                    cout << AnalysisTree.getNodeCount() << "         " << begin_time << " ms" << endl;
                }
                else if(AnalysisTree.getNodeCount() > 10000){
                    cout << AnalysisTree.getNodeCount() << "        " << begin_time << " ms" << endl;
                }
            }
        }
    }
    clock_t end_time = clock();
    cout << "-----------------------------------------------------" << endl;
    cout << "Part e - Time analysis of Binary Search Tree - part 2" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Tree Size Time Elapsed" << endl;
    cout << "-----------------------------------------------------" << endl;
    random_shuffle(&randomArr[0],&randomArr[15000]);
    for(int k = 0; k < 15000; k++){
        clock_t time_2 = clock();
        if((AnalysisTree.getNodeCount() % 1500 == 0) && (AnalysisTree.getNodeCount() >= 1500)){
            if(AnalysisTree.getNodeCount() <= 10000){
                cout << AnalysisTree.getNodeCount() << "         " << time_2 - end_time << " ms" << endl;
            }
            else if(AnalysisTree.getNodeCount() > 10000){
                cout << AnalysisTree.getNodeCount() << "        " << time_2 - end_time<< " ms" << endl;
            }
        }
        if(AnalysisTree.getNodeCount() != 0){
             AnalysisTree.deleteKey(randomArr[k]);
        }

    }

}
