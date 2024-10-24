#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;
Node *createnode(int);
void insert(Node **, int);
void inorder(Node*);
void kthmin(Node *, int*);
int main(){
    int nodes, node;
    printf("\nEnter number of nodes: ");
    scanf(" %d", &nodes);
    Node *root = NULL;
    while(nodes--){
        printf("\nEnter the node: ");
        scanf(" %d", &node);
        insert(&root, node);
    }
    inorder(root);
    printf("\nEnter k val: ");
    scanf(" %d", &node);
    kthmin(root, &node);
    return 0;
}
void kthmin(Node *root, int *k){
    if(root == NULL || *k < 1){
        return;
    }
    kthmin(root->left, k);
    if(*k == 1){
        printf("Kth Minimum: %d ", root->data);
    }
    (*k)--;
    kthmin(root->right, k);
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void insert(Node **root, int val){
    if(*root == NULL){
        *root = createnode(val);
    }
    if((*root)->data < val){
        insert(&((*root)->right), val);
    }
    else if((*root)->data > val){
        insert(&((*root)->left), val);
    }
}
Node *createnode(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}