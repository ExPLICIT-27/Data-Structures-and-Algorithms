#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;
Node *createnode(int);
Node *levelOrderBuild(Node*, int*, int, int);
void levelorderPrint(Node *);
int main(){
    int level[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root =levelOrderBuild(NULL, level, 0, 8);
    levelorderPrint(root);
    return 0;
}
void levelorderPrint(Node *root){
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        Node *curr = queue[front++];
        printf("%d ", curr->data);
        if(curr->left != NULL){
            queue[rear++]  = curr->left;
        }
        if(curr->right != NULL){
            queue[rear++] = curr->right;
        }
    }
}
Node *levelOrderBuild(Node *root, int *arr, int i, int size){
    if(i >= size){
        return NULL;
    }
    root = createnode(arr[i]);
    root->left = levelOrderBuild(root->left, arr, 2*i+1, size);
    root->right = levelOrderBuild(root->right, arr, 2*i+2, size);
    return root;
}
Node *createnode(int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}