#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int);
struct Node *createTree(int*, int);
struct Node *createTreeHelper(int*, int*, int);
int HeightNodes(struct Node*);
int main(){
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    struct Node *root = createTree(preorder, size);
    printf("Height of Tree: %d", HeightNodes(root));
    return 0;
}
int HeightNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    int left = HeightNodes(root->left);
    int right = HeightNodes(root->right);
    int max = (left > right)? left : right;
    return (1 + max);
}
struct Node *createTreeHelper(int *input, int *index, int size){
    if(*index >= size || input[*index] == -1){
        (*index)++;
        return NULL;
    }
    struct Node *root = createNode(input[*index]);
    (*index)++;
    root->left = createTreeHelper(input, index, size);
    root->right = createTreeHelper(input, index, size);
    return root;
}
struct Node *createTree(int *input, int size){
    int index = 0;
    return createTreeHelper(input, &index, size);
}
struct Node *createNode(int val){
    if(val == -1){
        return NULL;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL, newNode->right = NULL;
    return newNode;
}