#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
tree *createnode(int);
tree *buildTree(tree*, int, int, int*);
int SumNodes(tree*);
int isSumtree(tree*);
int main(){
    int arr[] = {26, 10, 3, 4, 4, 3};
    tree *root = buildTree(NULL, 0, 6, arr);
    if(isSumtree(root)){
        printf("YEs");
    }
    else{
        printf("No");
    }
    return 0;
}
int isSumtree(tree *root){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return 1;
    }
    return ((root->data == (SumNodes(root->left) + SumNodes(root->right))) && isSumtree(root->left) && isSumtree(root->right));
}
int SumNodes(tree *root){
    if(root == NULL){
        return 0;
    }
    return root->data + SumNodes(root->left) + SumNodes(root->right);
}
tree *buildTree(tree *root, int i, int size, int *arr){
    if(i < size){
        root = createnode(arr[i]);
        root->left = buildTree(root->left, 2*i+1, size, arr);
        root->right = buildTree(root->right, 2*i+2, size, arr);
        return root;
    }
    return NULL;
}
tree *createnode(int val){
    tree *node = (tree*)malloc(sizeof(tree));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}