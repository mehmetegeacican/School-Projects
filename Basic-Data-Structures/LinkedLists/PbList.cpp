#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "PbList.h"
using namespace std;

PbList::PbList(){
    head = NULL;
}
PbList::PbList(const PbList &linkedList){
    head = linkedList.head;
}

void PbList::printList(PbNode* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << "" <<endl;
}

/**THIS FUNCTION INSERTS A NEW NODE TO THE HEAD OF THE LINKED LIST**/
void PbList::insertHead(PbNode** head_reference,int new_data){

    PbNode* new_node = new PbNode();
    new_node->data = new_data;
    new_node->next = (*head_reference);
    (*head_reference) = new_node;

}
/**THIS FUNCTION INSERTS A NEW NODE TO THE TAIL OF THE LINKED LIST **/
void PbList::insertTail(PbNode** head_reference,int new_data){
    //New Node Allocation
    PbNode* new_node = new PbNode();
    PbNode *last = *head_reference;
    new_node->data = new_data;
    new_node->next = NULL;

    //If the Linked List is empty
    if (*head_reference == NULL)
    {
        *head_reference = new_node;
        return;
    }
    //Else traverse till the last node
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;

}
/**THIS FUNCTION INSERTS A NEW NODE IN BETWEEN THE LINKED LIST AFTER THE PARAMETER NODE*/
void PbList::insertInBetween(PbNode* prev_node,int new_data){
    //check if the given prev_node is NULL
    if (prev_node == NULL){
        return;
    }

    //New Node allocation
    PbNode* new_node = new PbNode();
    new_node->data = new_data;
    //next of new node is next of prev_node
    new_node->next = prev_node->next;
    //the next of prev_node as new_node
    prev_node->next = new_node;

}
/**THIS FUNCTION INSERTS A NEW NODE IN BETWEEN AFTER THE NODE WITH THE PARAMETER VALUE*/
void PbList::insertAfter(PbNode** head_ref,int prev_data,int new_data){
    //FINDING THE NODE WITH THE PREV DATA
    PbNode* prev_node = *head_ref;

    while (prev_node != NULL)
    {
        if (prev_node->data == prev_data){
            break;
        }
        prev_node = prev_node->next;
    }
    insertInBetween(prev_node,new_data);
}
/**THIS FUNCTION DELETES A GIVEN NODE FROM THE LINKED LIST*/
void PbList::deleteNode(PbNode** head_ref, int key){
    // If linked list is empty
    if (*head_ref == NULL){
        return;
    }
    // Store head node
    PbNode* temp = *head_ref;

    // If head needs to be removed
    if (key == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<key-1; i++)
         temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    PbNode *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}
/**THIS FUNCTION DELETES FROM THE HEAD OF THE NODE*/
void PbList::deleteHead(PbNode** head_ref){
        // If linked list is empty
        if (*head_ref == NULL){
                return;
        }

        // Store head node
        PbNode* temp = *head_ref;

        // If head needs to be removed
        *head_ref = temp->next;
        free(temp);
        return;
}
/**THIS FUNCTION DELETES FROM THE TAIL OF THE NODE*/
void PbList::deleteTail(PbNode** head_ref){
        // If linked list is empty
        if (*head_ref == NULL){
                return;
        }
        // Store head node
        PbNode* temp = *head_ref;
        // If head needs to be removed
        if (temp->next == NULL)
        {
            *head_ref = temp->next;   // Change head
            free(temp);               // free old head
            return;
        }
        // Find the second last node
        PbNode* second_last = head;
        while (second_last->next->next != NULL)
            second_last = second_last->next;

        // Delete last node
        delete (second_last->next);

        // Change next of second last
        second_last->next = NULL;
}
/**THIS FUNCTION GETS THE NTH ELEMENT OF THE LINKED LIST*/
int PbList::getNthElement(PbNode* head,int x){
    PbNode* curr = head;

    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (curr != NULL) {
        if (count == x)
            return (curr->data);
        count++;
        curr = curr->next;
    }

    if(curr == NULL){
        return -1;
    }
}
/**THIS FUNCTION CHECKS WHETHER THE GIVEN ELEMENT IS IN THE LINKED LIST*/
bool PbList::ifInList(PbNode* head,int x){
    PbNode* curr = head; // Initialize current
    while (curr != NULL)
    {
        if (curr->data == x){
            return true;
        }

        curr = curr->next;
    }
    return false;
}
int main(){
    PbList A;
    PbNode* first = NULL;
    PbNode* second = NULL;
    PbNode* third = NULL;

    // allocate 3 nodes in the heap
    first = new PbNode();
    second = new PbNode();
    third = new PbNode();
    //GENERATING AN ARRAY************************
    clock_t time_req;
    bool cont = false;

    do{
        //DECISION OF LINKED LIST**********************************************
        cout<<"\nWhat would you like to do with the linked list?"<<endl;
        cout<<"\n (1) Add new Element"<<endl;
        cout<<"\n (2) Delete an Element"<<endl;
        cout<<"\n (3) Search an Element"<<endl;
        cout<<"\n (4) Print the linked list" << endl;
        int decision;
        do{
            cout << "\nPlease Enter the number:";
            cin >>decision;

            if(decision == 1){
                    int decNumber;
                    int dataNumber;
                    cout << "\nPlease Enter the number to be added to the list" << endl;
                    cin >> dataNumber;
                    cout << "\nWhere would you like to insert this new number?" << endl;
                    cout << "\n (1) Head of the list" << endl;
                    cout << "\n (2) Tail of the list" << endl;
                    cin >> decNumber;
                    if(decNumber == 1){
                        cout << "\nInsertion to head has been done" << endl;
                        A.insertHead(&A.head,dataNumber);
                    }
                    else if(decNumber == 2){
                        cout << "\nInsertion to tail has been done" << endl;
                        A.insertTail(&A.head,dataNumber);
                    }
                    else{
                        cout << "\nPlease select between 1 and 2"<<endl;
                    }
            }
            else if(decision == 2){
                    int decNumber;
                    int dataNumber;
                    cout << "\nWhere would you like to delete?" << endl;
                    cout << "\n (1) Head of the list" << endl;
                    cout << "\n (2) Tail of the list" << endl;
                    cin >> decNumber;
                    if(decNumber == 1){
                        cout << "\nDeletion from head has been done" << endl;
                        A.deleteHead(&A.head);
                    }
                    else if(decNumber == 2){
                        cout << "\nDeletion from tail has been done" << endl;
                        A.deleteTail(&A.head);
                    }
                    else{
                        cout << "\nPlease select between 1 and 2"<<endl;
                    }

            }
            else if(decision == 3){
                    int decNumber;
                    int indexNumber;
                    int x;
                    cout << "\nHow would you like to search?" << endl;
                    cout << "\n (1) Whether a particular number exist in the list" << endl;
                    cout << "\n (2) What is the number of the particular index" << endl;
                    cin >> decNumber;
                    if(decNumber == 1){
                        cout << "\nWhich number would you like to search" << endl;
                        cin >> indexNumber ;
                        x = A.ifInList(A.head,indexNumber);
                        if(x == 0){
                            cout << "The number does not exist in the list" << endl;
                        }
                        else{
                            cout << "The number exists in the list"<< endl;
                        }
                    }
                    else if(decNumber == 2){
                        cout << "\nPlease Enter the index that you'd like to find the value of" << endl;
                        cin>>indexNumber;
                        x = A.getNthElement(A.head,indexNumber);
                        cout << "The " << indexNumber << "th index holds " << x << "value" << endl;
                    }
                    else{
                        cout << "\nPlease select between 1 and 2"<<endl;
                    }

            }
            else if(decision == 4){
                cout << "*******************THE LINKED LIST ************"<<endl;
                A.printList(A.head);
                cout << "*******************THE LINKED LIST ************"<<endl;
            }
            else{
                cout << "Please Enter between 1 and 4"<< endl;
            }
        }while(decision > 4 || decision < 1);


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


