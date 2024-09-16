#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
int isEqual(struct Node *, struct Node *);
struct Node *createNode(int);
struct Node *createTree(int*, int);
struct Node *createTreeHelper(int*, int*, int);
int isSubtree(struct Node *, struct Node*);
int main(){
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    struct Node *root = createTree(preorder, size);
    int subarr[] = {1, 2, 4, -1, -1, -1, -1};
    struct Node *subroot = createTree(subarr, 7);
    if(isSubtree(root, subroot)){
        printf("\nYEs");
    }
    else{
        printf("\nNO");
    }
    return 0;
}
int isSubtree(struct Node *root,  struct Node *subroot){
    if(subroot == NULL){
        return 1;
    }
    if(root == NULL){
        return 0;
    }
    if(root->data == subroot->data){
        if(isEqual(root, subroot)){
            return 1;
        }
    }
    return isEqual(root->left, subroot) || isEqual(root->right, subroot);
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
int isEqual(struct Node *root, struct Node *check){
    if(root == NULL && check == NULL){
        return 1;
    }
    if(root == NULL || check == NULL){
        return 0;
    }
    if(root->data == check->data){
        return isEqual(root->left, check->left) && isEqual(root->right, check->right);
    }
    return 0;
}