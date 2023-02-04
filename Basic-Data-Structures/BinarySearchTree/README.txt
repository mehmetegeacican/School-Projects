Pointer-based implementation of Binary Search Tree

includes methods of :
insertKey(int key)
deleteKey(int key)
getHeight();
getNodesRequired()//Number of nodes required to make a full binary tree
fullBTLevel()//returns the max level at which the tree is a full bt
mirrorTree()// creates a copy and changes left and right child of the tree
inOrder() // prints inorder traversal of the bst
levelOrder// prints level order of the bst

and support functions for these functions

main.cpp tests these functions:
1.creates a pointer based binary search tree and insert the following numbers into it: 
{7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 14, 5}
2.calls the findNodesRequired method
3.deletes 7 and 8 from the tree
4.calls the findFullBTLevel method
5.creates a mirrored copy of the tree and prints it
