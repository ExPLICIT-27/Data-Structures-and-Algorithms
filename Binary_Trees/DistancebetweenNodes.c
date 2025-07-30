#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;
Node *createnode(int);
Node *buildbst(Node*, int);
int distanceFromRoot(Node*, int);
int distanceBetween2(Node *, int, int);
int main(){
    int n;
    printf("\nEnter number of elements in bst: ");
    scanf(" %d", &n);
    Node *root = NULL;
    int temp;
    while(n--){
        printf("\nEnter root value: ");
        scanf(" %d", &temp);
        root = buildbst(root, temp);
    }
    int temp1;
    printf("\nEnter nodes to find distance between: ");
    scanf(" %d %d", &temp, &temp1);
    // our function must have the smaller node as the first argument
    printf("Distance between %d and %d: %d", temp, temp1, distanceBetween2(root, temp, temp1));
    return 0;
}
int distanceBetween2(Node *root, int x, int y){
    if(root == NULL){
        return 0;
    }
    if(root->data < x && root->data < y){
        return distanceBetween2(root->right, x, y);
    }
    if(root->data > x && root->data > y){
        return distanceBetween2(root->left, x, y);
    }
    if(root->data >= x && root->data <= y){
        return distanceFromRoot(root, x) + distanceFromRoot(root, y);
    }
}
Node *createnode(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
Node *buildbst(Node *root, int val){
    if(root == NULL){
        return createnode(val);
    }
    if(root->data == val){
        return root;
    }
    else if(root->data < val){
        root->right = buildbst(root->right, val);
    }
    else{
        root->left = buildbst(root->left, val);
    }
    return root;
}
int distanceFromRoot(Node *root, int x){
    if(root == NULL || root->data == x){
        return 0;
    }
    if(root->data < x){
        return 1 + distanceFromRoot(root->right, x);
    }
    return 1 + distanceFromRoot(root->left, x);
}