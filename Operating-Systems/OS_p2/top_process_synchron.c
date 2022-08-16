#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h>
#include <sys/types.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include<time.h> 

#define MAX_FILES 5
//#define K 20
//#define N 2
int *ip; // THE ARRAY
int *arrSize;// THE ARRAY SIZE
int index_arr;
sem_t *sem_mutex;       /* protects the buffer */
sem_t *sem_full;        /* counts the number of items */
sem_t *sem_empty;       /* counts the number of empty buffer slots */
int K;
int N;


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
}
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int smallest = i; // Initialize smalles as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) { 
        swap(&arr[i], &arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, smallest); 
    } 
} 
  
// Function to build a Max-Heap from the given array 
void buildHeap(int arr[], int n) 
{ 
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1; 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 
//READS FILES CONCURRENTLY AND ADDS THEM TO THE HEAP  
void arrayInsert(FILE* file){
	int j;
	
	while (!feof (file)){
		sem_wait(sem_empty);
		sem_wait(sem_mutex);
		fscanf(file, "%d", &j);
		if(arrSize[0] < K){
			ip[arrSize[0]] = j;
			buildHeap(ip,arrSize[0]);
			arrSize[0]++;
		}
		else{
			if(j > ip[0]){
				ip[0] = j;
				buildHeap(ip,arrSize[0]);
			}
		}
		sem_post(sem_mutex);
		sem_post(sem_full);	
    }
}
void * child_process(void *arg){
	//printf("THIS IS CHILD PROCESS\n");
	FILE* fp = fopen(arg, "r");
	//printf("FILE IS OPENENED\n");
	arrayInsert(fp);
	
}
int main(int argc, char **argv) 
{
    clock_t t;
    t = clock();
    pid_t pid;
    pid_t childpid[MAX_FILES];
    int fd,fd2;
    K = atoi(argv[1]);
    N = atoi(argv[2]);
    //SEMAPHORES
    void *sptr,*sptr2;
    /* CLEAN UP THE REMAINING SEMAPHORES FIRST */
    sem_unlink("SEMNAME_MUTEX");
	sem_unlink("SEMNAME_FULL");
	sem_unlink("SEMNAME_EMPTY");

    //OPENING A SHARED MEMORY FOR ARRAY
    fd = shm_open("MEMORYARRAY", O_RDWR | O_CREAT, 0660);
    ftruncate(fd, K*sizeof(int));//CHANGE 512 TO REQUIRED NUMBER
    sptr = mmap(NULL, K*sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    ip = (int *)sptr; // SHARED ARRAY HAS BEEN MADE
    //OPENING FOR SIZE
    fd2 = shm_open("MEMORYSIZE", O_RDWR | O_CREAT, 0660);
    ftruncate(fd2, K*sizeof(int));//CHANGE 512 TO REQUIRED NUMBER
    sptr2 = mmap(NULL, K*sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    close(fd2);
    arrSize = (int*) sptr2;
    FILE* fp = fopen(argv[MAX_FILES + 3 ], "w");

    //CREATE SEMAPHORES**********************************
    sem_mutex = sem_open("SEMNAME_MUTEX", O_RDWR | O_CREAT, 0660, 1);
    if (sem_mutex < 0) {
    	perror("can not create semaphore\n");
    	exit (1);
    }
    printf("sem %s created\n", "SEMNAME_MUTEX");

    sem_full = sem_open("SEMNAME_FULL", O_RDWR | O_CREAT, 0660, 0);
    if (sem_full < 0) {
    	perror("can not create semaphore\n");
    	exit (1);
    }printf("sem %s created\n", "SEMNAME_FULL");
    sem_empty =
    sem_open("SEMNAME_EMPTY", O_RDWR | O_CREAT, 0660, BUFSIZ);
    if (sem_empty < 0) {
    	perror("can not create semaphore\n");
    	exit (1);
	}
	printf("sem %s create\n", "SEMNAME_EMPTY");
	 //CREATE SEMAPHORES*****************************
	
    /* create sorter processes */
    for (int i = 0; i < N; i++)
    {
    	pid = fork();
    	if (pid == 0) {
    		child_process(argv[i + 3]);
    		exit (1);
    	}
    	childpid[i] = pid;
	}
	//WAITING FOR THE CHILD PROCESSES TO TERMINATE
	for (int i = 0; i < N; ++i)
	{
		waitpid (childpid[i], NULL, 0);
	}
	//UNLINKING THE SHARED MEMORY
	shm_unlink("MEMORYARRAY");
	shm_unlink("MEMORYSIZE");

	//WRITING TO THE OUTPUT FILE
	selectionSort(ip,K);
	for(int i = K - 1 ; i >= 0;i--){
		printf("Array element %d\n", ip[i]);
		fprintf(fp,"%d\n",ip[i]); 	
	}
	printf("Array size %d\n", K);
	printf("minimum %d\n", ip[0]);
	sem_close(sem_mutex);
	sem_close(sem_full);
	sem_close(sem_empty);

	t = clock() -t;
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("Time Taken : %f\n",time_taken);

}
