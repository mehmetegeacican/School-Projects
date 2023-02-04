#ifndef __SEARCHMETHODS_H
#define __SEARCHMETHODS_H
#include <string>
using namespace std;
class SearchMethods{
public:
    //SORTING METHOD(FOR BINARY SEARCH)
    void insertionSort(int arr[], int first,int last);
    //SEARCH METHODS
    int linearSearch(int arr[],int n,int x);
    int binarySearch(int arr[], int left, int right, int x);

};
#endif
