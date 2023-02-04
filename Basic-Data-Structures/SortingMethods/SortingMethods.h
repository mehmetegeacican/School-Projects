#ifndef __SORTINGMETHODS_H
#define __SORTINGMETHODS_H
#include <string>
#include "SortingMethods.h"
using namespace std;
class SortingMethods{
public:
    //Sorting
    /**THE MERGE FUNCTION***/
    void merge(int arr[], int first, int mid, int last);
    void mergeSort(int theArray[],int first,int last);
    void swap(int *xp, int *yp);
    int partition(int arr[], int low, int high);
    /***The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index ****/
    void quickSort(int theArray[], int first, int last);
    /**Function to sort an array using insertion sort***/
    void insertionSort(int arr[], int first,int last);
    /**THIS IS HYBRID SORT IN WHICH AFTER PARTITION SIZE BECOMESS LESS THAN 10, THE SORTING MECHANISM CHANGES TO INSERTION SORT**/
    void hybridSort(int arr[],int first, int last);
    void printArray(int arr[], int n);


private:

};
#endif

