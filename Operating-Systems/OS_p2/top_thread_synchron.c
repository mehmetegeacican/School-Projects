#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/signal.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include<time.h> 
struct node 
{ 
    int key; 
    struct node *left, *right;
};
#define MAX_FILES 5
/*SHARED BINARY TREE GLOBAL AND WORKER FUNCTION*/
struct node *tree;
int treeSize;
int K;
int N;
/* A MUTEX TO LOCK AND UNLOCK (FOR SYNCHRONIZATION)*/
pthread_mutex_t lock;
//pthread_cond_t xc;

// A utility function to do inorder traversal of BST 
void inorderRev(struct node *root) 
{ 
    if (root == NULL)
    	return; 
    inorderRev(root->right); 
    
    printf("%d \n", root->key); 
    
    inorderRev(root->left); 
     
}
void WriteRev(struct node *root,FILE* file) 
{ 
    if (root == NULL)
    	return; 
    WriteRev(root->right,file); 
    
    fprintf(file,"%d\n",root->key);  
    
    WriteRev(root->left,file); 
     
}
/*THIS IS FOR THE SELECTION SORT OF THE ARRAY*/
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL){
        struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
	    temp->key = key; 
	    temp->left = temp->right = NULL;
	    if(tree == NULL)
	    	tree = temp;
	    return temp; 
    }; 
  
    /* Otherwise, recur down the tree */
    if (key <= node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
}
/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node* minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
void putToTree(FILE* file,struct node* node){
    //FILE* filecp = fopen(file, "r");
    int j = 0;
    int minimum = 100;
    //SYNCHRONIZATION
    
    while (!feof (file)){
        pthread_mutex_lock(&lock); 
        fscanf(file, "%d", &j);
        tree = insert(tree,j);
        minimum = minValueNode(tree)->key;
        if(treeSize >= K){
            tree = deleteNode(tree,minimum);
        }
        else{
            treeSize++;
        }
        pthread_mutex_unlock(&lock);
    }
   
    //SYNCHRONIZATION
     fclose(file);
 }


/* Method for writing the tree output to the file*/
void WriteKelements(struct node* node,FILE* file,int k) 
{ 
    static int count = 0; 
    if (node == NULL) 
        return; 
  
    if (count <= k) { 
  
        /* first recur on left child */
        WriteKelements(node->right,file,k);
        count++; 
  
        // when count = n then print element 
        if (count <= k) 
            fprintf(file,"%d\n",node->key); 
  
        /* now recur on right child */
        WriteKelements(node->left,file,k);  
    } 
}
void * worker_thread(void *arg){
		FILE* fp = fopen(arg, "r");	
		putToTree(fp,tree);
		pthread_exit (NULL); 
		fclose(fp);
	}//END OF WORKER_THREAD

int main(int argc, char **argv) 
{
    clock_t t;
    t = clock();
    int ret;
    K = atoi(argv[1]);
    N = atoi(argv[2]);
    FILE* file2 = fopen(argv[MAX_FILES + 3],"w");
    pthread_t pids[MAX_FILES]; // producer tids
    //pthread_t mid;
    // create worker threadss
	for (int i = 0; i < N; ++i){
		ret = pthread_create(&pids[i], NULL, worker_thread, (void*) argv[i+3]);
		if (ret < 0){
			perror("thread create failed\n");
			exit(1);
		}
	}
	// wait for the producer threads to terminateb
	for (int i = 0; i < N; ++i)
		pthread_join(pids[i], NULL);

    printf("THE TREE\n");
    inorderRev(tree);
    //WRITE THE FINAL VERSION OF THE TREE TO THE OUTPUT FILE
    WriteRev(tree,file2);
    printf("TREE SIZE : %d\n",treeSize);
    pthread_mutex_destroy(&lock);

    t = clock() -t;
    double time_taken = ((double) t)/CLOCKS_PER_SEC;
    printf("Time Taken : %f\n",time_taken);


}
