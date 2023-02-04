// C++ program for Searching
#include <bits/stdc++.h>
#include <stdlib.h>
#include<time.h>
#include <ctime>
#include "SearchMethods.h"

/**Function to sort an array using insertion sort***/
void SearchMethods::insertionSort(int arr[], int first,int last)
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


int SearchMethods::linearSearch(int arr[],int n,int x){

    for(int i=0; i < n; i++){
        if(arr[i] == x)
            return i;
    }
    return -1;
}

int SearchMethods::binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left){
        int middle = left + (right - left) / 2;
        //MIDDLE ELEMENT
        if (arr[middle] == x)
            return middle;

        //RECURSIVE FUNCTIONS FOR LOOKING TO THE NEW SUBARRAYS
        if (arr[middle] > x)
            return binarySearch(arr, left, middle - 1, x);

        return binarySearch(arr, middle + 1, right, x);
    }

    return -1;
}

int main(){
    clock_t time_req;
    bool cont = false;
    SearchMethods S;

    do{
        int sz;
        cout<<"Enter the size of array::";
        cin>> sz;
        int randArray[sz];
        for(int i=0;i<sz;i++){
            randArray[i]=rand()%sz;  //Generate number between 0 to 999
        }
        cout<<"\nWhich Searching Algorithms would you like to use?"<<endl;
        cout<<"\n (1) Linear Search"<<endl;
        cout<<"\n (2) Binary Search"<<endl;
        int decision;
        do{
            cout << "\nPlease Enter the number:";
            cin >>decision;
            if(decision == 1){
                string printDec;
                time_req = clock();
                int searchedNumber;
                cout << "Which number you'd like to search:";
                cin >> searchedNumber;
                int index = S.linearSearch(randArray, sz, searchedNumber);
                cout << "The number is in index "<< index << endl;
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Merge Sort): \n";
                    for(int i = 0; i < sz;i++){
                        cout << randArray[i] << endl;
                        }
                    }

            }
            else if(decision == 2){
                string printDec;
                S.insertionSort(randArray,0,sz-1);
                time_req = clock();
                int searchedNumber;
                cout << "Which number you'd like to search:";
                cin >> searchedNumber;
                int index = S.binarySearch(randArray,0, sz-1, searchedNumber);
                cout << "The number is in index "<< index << endl;
                time_req = clock() - time_req;
                cout << " The process took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
                cout << "Would you like to print the sorted array?(y/n)"<<endl;
                cin >> printDec;
                if(printDec == "y"){
                    cout << "Sorted array(Merge Sort): \n";
                    for(int i = 0; i < sz;i++){
                        cout << randArray[i] << endl;
                        }
                    }

            }
            else{
                cout<<"Please Enter 1 or 2" << endl;
            }


        }
        while(decision > 3 || decision < 1);

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

}
