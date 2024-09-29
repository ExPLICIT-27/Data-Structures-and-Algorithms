#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;
tree *createnode(int);
tree *insert(tree*, int);
int findMin(tree*);
int main(){
    int nodes[] = {5, 4, 6, 3, 7, 1};
    tree *root = NULL;
    for(int i = 0; i < 6; i++){
        root = insert(root, nodes[i]);
    }
    printf("%d", findMin(root));
    return 0;
}
int findMin(tree *root){
    if(root == NULL){
        return -1;
    }
    tree *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
tree *insert(tree *root, int val){
    if(root == NULL){
        return createnode(val);
    }
    if(root->data == val){
        return root;
    }
    else if(root->data > val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
tree *createnode(int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}