#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int);
struct Node *buildTreeHelper(int*, int*, int);
struct Node *buildTree(int*, int);
void preorderPrint(struct Node *root); // preorder -> root, left, right
int main(){
    int preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    struct Node *root = buildTree(preorder, size);
    preorderPrint(root);
    return 0;
}
void preorderPrint(struct Node *root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    printf("%d ", root->data);
    preorderPrint(root->left);
    preorderPrint(root->right);
}
struct Node *createNode(int value){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL, node->right = NULL;
    return node;
}
struct Node *buildTreeHelper(int preorder[], int *index, int size){
    if(*index >= size || preorder[*index] == -1){
        (*index)++;
        return NULL;
    }
    struct Node *root = createNode(preorder[*index]);
    (*index)++;
    root->left = buildTreeHelper(preorder, index, size);
    root->right = buildTreeHelper(preorder, index, size);

    return root;
}
struct Node *buildTree(int preorder[], int size){
    int index = 0;
    return buildTreeHelper(preorder, &index, size);
}