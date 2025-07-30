// roblem Statement



// Given an array representing the parent-child relationship in a binary tree, find the tree's height without building it. 



// The parent-child relationship is defined by (A[i], i) for every index i in the array. The root node's value will be i if -1 is present at index i in the array.



// The depth of a node is the total number of edges from the node to the tree's root node. The root is the only node whose depth is 0. 



// The height of a node is the total number of edges on the longest path from the node of a leaf. The height of a tree would be the height of its root node or equivalently the depth of its deepest node. A leaf node will have a height of 0.



// Example



// Parent: [-1, 0, 0, 1, 2, 2, 4, 4]

// Index: [0, 1, 2, 3, 4, 5, 6, 7]

 

// -1 is present at index 0, which implies that the binary tree root is node 0.
// 0 is present at index 1 and 2, which implies that the left and right children of node 0 are 1 and 2.
// 1 is present at index 3, which implies that the left or the right child of node 1 is 3.
// 2 is present at index 4 and 5, which implies that the left and right children of node 2 are 4 and 5.
// 4 is present at index 6 and 7, which implies that the left and right children of node 4 are 6 and 7.

// output = 4
// code
#include <stdio.h>
#include <stdlib.h>
void fillDepth(int*, int, int*);
int maxDepth(int*, int);
int main(){
    int parents[] = {-1, 0, 0, 1, 2, 2, 4, 4};
    printf("\nMax Depth: %d", maxDepth(parents, 8));
    return 0;
}
int maxDepth(int *parents, int size){
    int *depth = (int*)calloc(size,sizeof(int));
    for(int i = 0; i < size; i++){
        fillDepth(depth, i, parents);
    }
    int max = depth[0];
    for(int i = 1; i < size; i++){
        max = (depth[i] < max)? max : depth[i];
    }
    return max;
}
void fillDepth(int *depth, int i, int *parents){
    if(depth[i]){
        return;
    }
    if(parents[i] == -1){
        depth[i] = 1;
        return;
    }
    if(depth[parents[i]] == 0){
        fillDepth(depth, parents[i], parents);
    }
    depth[i] = (depth[parents[i]] + 1);
}