#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main(){

    //GENERATING AN ARRAY************************
    Stack s;
    Queue q;
    bool cont = false;

    do{
        //DECISION OF LINKED LIST**********************************************
        cout<<"\nWhat would you like to do with Stacks and Queues?"<<endl;
        cout<<"\n (1) Add new Element to the Stack"<<endl;
        cout<<"\n (2) Delete an Element from the Stack"<<endl;
        cout<<"\n (3) Add new Element to the Queue"<<endl;
        cout<<"\n (4) Delete an Element from the Queue"<<endl;
        cout<<"\n (5) Print Stack"<<endl;
        cout<<"\n (6) Print Queue" << endl;
        int decision;
        do{
            cout << "\nPlease Enter the number:";
            cin >>decision;

            if(decision == 1){
                int dataNumber;
                cout << "Please Enter the Data value that you want to add to Stack"<<endl;
                cin>> dataNumber;
                s.push(&s.top,dataNumber);
                cout << "The number " << dataNumber << "has been added to the Stack" << endl;

            }
            else if(decision == 2){
                s.pop(&s.top);
                cout << "The top of the stack has been popped" << endl;
            }
            else if(decision == 3){
                int dataNumber;
                cout << "Please Enter the Data value that you want to add to Queue"<<endl;
                cin>> dataNumber;
                q.enqueue(&q.head,dataNumber);
                cout << "The number " << dataNumber << "has been added to the Queue" << endl;
            }
            else if(decision == 4){
                q.dequeue(&q.head);
                cout << "The head of the queue has been dequeued" << endl;
            }
            else if(decision == 5){
                cout << "**************STACK*********************" << endl;
                s.printStack(s.top);
                cout << "**************STACK*********************" << endl;

            }
            else if(decision == 6){
                cout << "**************QUEUE*********************" << endl;
                q.printQueue(q.head);
                cout << "**************QUEUE*********************" << endl;

            }
            else{
                cout << "Please Enter between 1 and 6"<< endl;
            }
        }while(decision > 6 || decision < 1);

        //ASKED TO TEST AGAIN
        string answer;
        cout<< "Would you like to continue? (y/n)"<<endl;
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
