/*
    CS 342 OPERATING SYSTEMS
    BERK TÜRK 21302570
    MEHMET EGE ACICAN 21602186
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>



// printfs are for debugging; remove them when you use/submit your library
struct memnode{
    int size;
    struct memnode *next;
};

/* Your Library Global Variables */
void *segmentptr; // points to the start of memory segment to manage
int segmentsize;  // size of segment to manage
int methodNumber;
int totalSize = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//You can define more variables if you wish

//ALLOCATION METHODS
// Function to allocate memory to blocks as per First fit algorithm 
void *firstFit(int objectsize) 
{
    struct memnode * tempBlock = (struct memnode *)segmentptr;

    if(objectsize < segmentsize && totalSize+objectsize < segmentsize){

        //For the first node allocation
        if(tempBlock->size == 0 && tempBlock->next == NULL)
        {
            segmentptr = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            ((struct memnode *)segmentptr) -> next = NULL;
            ((struct memnode *)segmentptr) -> size = objectsize;
            totalSize += objectsize;
            return segmentptr;
        }
        if(tempBlock->size == 0 && tempBlock->next != NULL)
        {                      
            ((struct memnode *)segmentptr) -> size = objectsize;
            totalSize += objectsize;
            return segmentptr;
        }

        //Allocating to the middle spots if there is an empty spot
        while(tempBlock->next!=NULL) 
        {
            if(tempBlock->size == 0 && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
            {
                tempBlock -> size = objectsize;
                totalSize += objectsize;
                return tempBlock->next;
            }
            
            tempBlock = tempBlock->next;    
        }

        // Start from the unallocated space
        if (tempBlock->next == NULL)
        {   
            tempBlock->next = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            tempBlock -> next -> next = NULL;
            tempBlock -> next -> size = objectsize;
            totalSize += objectsize;
            return tempBlock->next;
        }
    }
    return NULL;
}

// Function to allocate memory to blocks as per Best fit algorithm 
void *bestFit(int objectsize) 
{ 
    int bestfitNum = 0;
    char *bestfit;
    struct memnode * tempBlock = (struct memnode *)segmentptr;
    if (objectsize < segmentsize && totalSize+objectsize < segmentsize) // IF FOR CHECKING THE LIMIT, IF HIGHER THAN NOT ALLOCATED 
    {
        //For the first node allocation
        if(tempBlock->size == 0 && tempBlock->next == NULL)
        {
            segmentptr = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            ((struct memnode *)segmentptr) -> next = NULL;
            ((struct memnode *)segmentptr) -> size = objectsize;
            totalSize += objectsize;
            return segmentptr;
        }
        if(tempBlock->size == 0 && tempBlock->next != NULL && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
        {                      
            ((struct memnode *)segmentptr) -> size = objectsize;
            totalSize += objectsize;
            return segmentptr;
        }

        //Allocating to the middle spots if there is an empty spot
        while(tempBlock->next!=NULL) 
        {
            bestfitNum = (char*) (tempBlock->next) - (char*) (tempBlock) - 16;
            if(tempBlock->size == 0 && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
            {
                if((char*) (tempBlock->next) - (char*) (tempBlock) - 16 <= bestfitNum && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
                {
                    bestfit = (char*) (tempBlock) - 16;
                }
            }
            
            tempBlock = tempBlock->next;    
        }

        struct memnode * tempProcess = (struct memnode *)segmentptr;
        if(tempProcess->next!=NULL)
        {
            while(tempProcess->next!=NULL)
            {
                //if((char*) (tempProcess->next) - (char*) (tempProcess) - 16 == bestfitNum)
                if((char*) tempProcess->next - 16 == bestfit)
                {
                    tempProcess-> next -> size = objectsize;
                    totalSize += objectsize;
                    return tempProcess->next;
                }
                tempProcess = tempProcess->next;
            }
        }
        // Start from the unallocated space
        if (tempBlock->next == NULL)
        {   
            tempBlock->next = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            tempBlock -> next -> next = NULL;
            tempBlock -> next -> size = objectsize;
            totalSize += objectsize;
            return tempBlock->next;
        }
    }
    return NULL;
}
// Function to allocate memory to blocks as per worst fit algorithm 
void *worstFit(int objectsize) 
{
    int worstfitNum = 0;
    char *worstfit;
    struct memnode * tempBlock = (struct memnode *)segmentptr;
    if (objectsize < segmentsize && totalSize+objectsize < segmentsize) // IF FOR CHECKING THE LIMIT, IF HIGHER THAN NOT ALLOCATED 
    {
        //For the first node allocation
        if(tempBlock->size == 0 && tempBlock->next == NULL)
        {
            segmentptr = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            ((struct memnode *)segmentptr) -> next = NULL;
            ((struct memnode *)segmentptr) -> size = objectsize;
            totalSize += objectsize;
            return segmentptr;
        }

        //Allocating to the middle spots if there is an empty spot
        while(tempBlock->next!=NULL) 
        {
            worstfitNum = (char*) (tempBlock->next) - (char*) (tempBlock) - 16;
            if(tempBlock->size == 0 && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
            {
                if((char*) (tempBlock->next) - (char*) (tempBlock) - 16 > worstfitNum && (char*) (tempBlock->next) - (char*) (tempBlock) - 16 >= objectsize)
                {
                    worstfit = (char*) (tempBlock)->next - 16;
                }
            }
            
            tempBlock = tempBlock->next;    
        }

        struct memnode * tempProcess = (struct memnode *)segmentptr;
        if(tempProcess->next!=NULL)
        {
            while(tempProcess->next!=NULL)
            {
                if((char*) tempProcess->next - 16 == worstfit)
                {
                    tempProcess-> next -> size = objectsize;
                    totalSize += objectsize;
                    return tempProcess->next;
                }
                tempProcess = tempProcess->next;
            }
        }
        // Start from the unallocated space
        if (tempBlock->next == NULL)
        {   
            tempBlock->next = (struct memnode *)((char *)tempBlock + sizeof(struct memnode) + (tempBlock -> size));
            tempBlock -> next -> next = NULL;
            tempBlock -> next -> size = objectsize;
            totalSize += objectsize;
            return tempBlock->next;
        }
    }
    return NULL;
} 
//ALLOCATION METHODS
void *mem_allocate (int objectsize){
    if(objectsize < 128 || objectsize > 2048 *1024){
        printf("ERROR\n");
        exit(0);
    }
    struct memnode * temp = (struct memnode *)segmentptr;
    if(methodNumber == 0){  
        pthread_mutex_lock(&lock);
        temp = firstFit(objectsize);
        pthread_mutex_unlock(&lock);
        return temp;
    }

    else if(methodNumber == 1){
        pthread_mutex_lock(&lock);
        temp = bestFit(objectsize);
        pthread_mutex_unlock(&lock);
        return temp;
    }

    else if(methodNumber == 2){
        pthread_mutex_lock(&lock);
        temp = worstFit(objectsize);
        pthread_mutex_unlock(&lock);
        return temp;
    }
    else{
    }
    return (NULL);      // if not success     
}

/* THIS IS MEMORY INITIALIZATION*/
int mem_init(void *chunkpointer, int chunksize,int method)
{
    if(chunksize < 32 || chunksize > 32768){
        printf("ERROR\n");
        return -1;
    }
    //INITIALIZING THE POINTER AND SIZE AND METHOD NO
    segmentptr = chunkpointer;     // end of data segment
    segmentsize = chunksize;
    methodNumber = method;

    // adding a struct to the head of the segment to describe it as a free segment
    ((struct memnode *) segmentptr) -> size = 0;
    ((struct memnode *) segmentptr) -> next = NULL;

    return (0);
}
/*THIS IS MEMORY INITIALIZATION */
void mem_free(void *objectptr)
{
    struct memnode *tempBlock = segmentptr;

    if(tempBlock == (struct memnode *)objectptr)
    {
        pthread_mutex_lock(&lock);
        totalSize -= tempBlock->size;
        tempBlock -> size = 0;
        pthread_mutex_unlock(&lock);
        return;
    }

    while (tempBlock -> next != (struct memnode *)objectptr){
        tempBlock = tempBlock->next;
    }
    pthread_mutex_lock(&lock);
    if (tempBlock -> next){
        totalSize -= tempBlock->next->size;
        tempBlock -> next -> size = 0;
    }
    pthread_mutex_unlock(&lock);
    printf("free called\n");
    return;
}

void mem_print (void)
{
    struct memnode * temp = segmentptr;

    while(temp!=NULL)
    {
        printf("Address: %lx", (unsigned long) &temp->next-16);
        if(temp->size == 0)
        {
            printf(" State : free %d\n",temp->size);
        }
        else
        {
            printf(" State : allocated %d\n",temp->size);
        }
        temp = temp->next;

    }
    printf("Total unallocated size: %d\n", segmentsize - totalSize);
    return;
}