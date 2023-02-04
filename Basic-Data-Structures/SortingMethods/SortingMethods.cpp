// C++ program for insertion sort
#include <bits/stdc++.h>
#include <stdlib.h>
#include<time.h>
#include <ctime>
#include "SortingMethods.h"
using namespace std;


/**THE MERGE FUNCTION***/
void SortingMethods::merge(int arr[], int first, int mid, int last)
{
    //ADJUSTING THE LENGTHS OF THE SUB-ARRAYS
    int n1 = mid - first + 1;
    int n2 = last - mid;

    // TEMP ARRAYS
    int LeftArr[n1], RightArr[n2];

    // COPYING THE DATA
    for(int i = 0; i < n1; i++)
        LeftArr[i] = arr[first + i]; //LEFT SIDE GIVEN
    for(int j = 0; j < n2; j++)
        RightArr[j] = arr[mid + 1 + j]; // RIGHT SIDE GIVEN

    // MERGE

    // INDEXES(i for left, j for right)
    int i = 0;
    int j = 0;
    //INDEXES (k for main)
    int k = first;

    //COMPARING AND PUTTING THE SMALLER OF THE INDEXES Left[i],Right[j]
    while (i < n1 && j < n2){
        if (LeftArr[i] <= RightArr[j]){
            arr[k] = LeftArr[i];
            i++;
        }
        else{
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }
    //IF ONE OF THE ARRAYS HAS BEEN COMPLETED, PUT THE REMAINING OF THE OTHER TO THE NORMAL ARRAY
    while(i< n1){
        arr[k] = LeftArr[i];
        i++;
        k++;
    }
    while(i< n2){
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void SortingMethods::mergeSort(int theArray[],int first,int last){
    if (first < last) {
      int mid = first + (last - first) / 2;
      mergeSort(theArray, first, mid);
      mergeSort(theArray, mid+1, last);
      merge(theArray,first, mid, last);
   }
}
/***************************************************************
****************************************************************/
void SortingMethods::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/**This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot ***/

int SortingMethods::partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/***The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index ****/

void SortingMethods::quickSort(int theArray[], int first, int last){
    if (first < last)
    {
        int pivotIndex = partition(theArray, first, last);
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }
}

/**Function to sort an array using insertion sort***/
void SortingMethods::insertionSort(int arr[], int first,int last)
{
    int key, j;
    for (; first <= last; first++)
    {
        key = arr[first];
        j = first - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/**THIS IS HYBRID SORT IN WHICH AFTER PARTITION SIZE BECOMESS LESS THAN 10, THE SORTING MECHANISM CHANGES TO INSERTION SORT**/
void SortingMethods::hybridSort(int arr[],int first, int last){
    if(last-first >= 10){
        int pivot = partition(arr,first,last);
        quickSort(arr,first,last);
        --last;
    }
    else{
        insertionSort(arr,first,last);
    }
}

// UTILITY FUNCTION
void SortingMethods::printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver code */
int main()
{
    //GENERATING AN ARRAY************************
    clock_t time_req;
    bool cont = false;
    SortingMethods A;

    do{
        int sz;
        cout<<"Enter the size of array::";

        cin>> sz;
        int randArray[sz];
        for(int i=0;i<sz;i++){
            randArray[i]=rand()%sz;  //Generate number between 0 to 999
        }
        //cout<<"\nElements of the array::"<<endl;
        //PRINTING THE ELEMENTS (UNSORTED)
        //for(int i=0;i<sz;i++){

            //cout<<"Elements no "<<i+1<<"::"<<randArray[i]<<endl;
        //}
        //GENERATING AN ARRAY**********************************************
        cout<<"\nWhich Sorting Algorithms would you like to use?"<<endl;
        cout<<"\n (1) Merge Sort"<<endl;
        cout<<"\n (2) Insertion Sort"<<endl;
        cout<<"\n (3) Quick Sort"<<endl;
        cout<<"\n (4) Hybrid Sort"<<endl;
        int decision;

        do{
            cout << "\nPlease Enter the number:";
            cin >>decision;

            if(decision == 1){
                string printDec;
                time_req = clock();
                A.mergeSort(randArray, 0, sz - 1);
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Merge Sort): \n";
                    A.printArray(randArray, sz);
                }
            }
            else if(decision == 2){
                string printDec;
                time_req = clock();
                A.insertionSort(randArray, 0, sz - 1);
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Insertion Sort): \n";
                    A.printArray(randArray, sz);
                }
            }
            else if(decision == 3){
                string printDec;
                time_req = clock();
                A.quickSort(randArray,0,sz-1);
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Quick Sort): \n";
                    A.printArray(randArray, sz);
                }
            }
            else if(decision == 4){
                string printDec;
                time_req = clock();
                A.hybridSort(randArray,0,sz-1);
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Hybrid Sort): \n";
                    A.printArray(randArray, sz);
                }
            }
            else{
                cout << "Please Enter between 1 and 5"<< endl;
            }
        }while(decision > 5 || decision < 1);


        //ASKED TO TEST AGAIN
        string answer;
        cout<< "Would you like to try again? (y/n)"<<endl;
        cin >> answer;
        if(answer == "y"){
            cont = true;
        }
        else{
            cont = false;
        }
    }while(cont == true);
    return 0;
}
