#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
tree *createnode(int);
tree *insert(int, tree*);
void print(tree*);
int main(){
    int nodes;
    printf("\nEnter number of nodes: ");
    scanf(" %d", &nodes);
    tree *root = NULL;
    while(nodes--){
        int temp;
        printf("\nEnter value: ");
        scanf(" %d", &temp);
        root = insert(temp, root);
    }
    print(root);
    return 0;
}
void print(tree *root){
    if(root == NULL){
        printf("NULL ");
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}
tree *insert(int val, tree *root){
    if(root == NULL){
        return createnode(val);
    }
    if(val == root->data){
        return root;
    }
    else if(val < root->data){
        root->left =  insert(val, root->left);
    }
    else{
        root->right =  insert(val, root->right);
    }
    return root;
}
tree *createnode(int val){
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}